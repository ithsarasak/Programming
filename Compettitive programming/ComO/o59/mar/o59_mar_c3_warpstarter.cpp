#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int n, k;
long long ans = 1e18, sum;
vector<pii> point;
deque<pii> q;
set<pii> s;

long long cal( pii a, pii b ) { return ( long long )( abs( a.x - b.x ) + abs( a.y - b.y ) ); }

void all( pii t, long long w ) {
    //printf("T : %d %d\n",t.x,t.y);
    if( w == 1LL ) s.insert( t );
    auto it = s.lower_bound( t ), it2 = it;
    it++;
    if( it2 == s.begin() ) {
        //printf("%d %d %d %d\n",(*it).x,(*it).y,(*it2).x,(*it2).y);
        sum += w * cal( *it, *it2 );
    }
    else if( it == s.end() ) {
        it--, it2--;
        sum += w * cal( *it, *it2 );
    }
    else {
        auto it3 = it2;
        it2--;
        sum += w * ( cal( *it2, *it3 ) + cal( *it, *it3 ) - cal( *it, *it2 ) );
    }
    if( w == -1LL ) s.erase( t );
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1, x, y ; i <= n ; i++ ) {
        scanf("%d %d",&x,&y);
        point.emplace_back( pii( y, x ) );
    }
    sort( point.begin(), point.end() );
    for( int i = 0 ; i < n ; i++ ) {
        //printf("%d :\n",i);
        pii t = pii( point[i].y, point[i].x );
        q.emplace_back( t );
        if( s.size() == 0 ) s.insert( t );
        else all( t, 1LL );
        if( i != n - 1 && t.x == point[i+1].x ) continue ;
        if( q.size() > k ) {
            pii temp = q.front();
            //printf("%d %d\n",q.size(),i);
            q.pop_front();
            all( temp, -1LL );
            while( !q.empty() && q.front().y == temp.y ) {
                temp = q.front();
                //printf("%d\n",temp.y);
                q.pop_front(); 
                all( temp, -1LL );
            } 
        }
        if( q.size() == k ) ans = min( ans, sum );
        //printf("sum : %lld\n",sum);
    }
    printf("%lld",ans);
    return 0;
}