#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

int n, m;
vector<pii> mxhull, mnhull, eq;

bool bad( pii a, pii b, pii c ) { return ( c.y - a.y ) * ( b.x - c.x ) < ( c.y - b.y ) * ( a.x - c.x ); }

void build_maxhull() {
    for( pii li : eq ) {
        while( mxhull.size() > 1 && bad( mxhull[(int)mxhull.size()-2], mxhull.back(), li ) ) mxhull.pop_back();
        while( !mxhull.empty() && mxhull.back().x == li.x && mxhull.back().y <= li.y ) mxhull.pop_back();
        mxhull.emplace_back( li ); 
    }
}

void build_minhull() {
    for( pii li : eq ) {
        while( mnhull.size() > 1 && bad( mnhull[(int)mnhull.size()-2], mnhull.back(), li ) ) mnhull.pop_back();
        while( !mnhull.empty() && mnhull.back().x == li.x && mnhull.back().y >= li.y ) mnhull.pop_back();
        mnhull.emplace_back( li );
    }
}

long long f( pii li, long long x ) { return x*li.x + li.y; }

long long querymx( long long x ) {
    int l = 0, r = (int)mxhull.size() - 1;
    while( l < r ) {
        int mid = l + r >> 1;
        if( f( mxhull[mid], x ) > f( mxhull[mid+1], x ) ) r = mid;
        else l = mid + 1;
    }
    return f( mxhull[l],x );
}

long long querymn( long long x ) {
    int l = 0, r = (int)mnhull.size() - 1;
    while( l < r ) {
        int mid = l + r >> 1;
        if( f( mnhull[mid], x ) < f( mnhull[mid+1], x ) ) r = mid;
        else l = mid + 1;
    }
    return f( mnhull[l], x );
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) {
        long long a, b;
        scanf("%lld %lld",&a,&b);
        eq.emplace_back( -1*a*a, b );
    }
    sort( eq.begin(), eq.end() ), build_maxhull();
    sort( eq.begin(), eq.end(), greater<pii>() ), build_minhull();
    for( int i = 1 ; i <= m ; i++ ) {
        long long a, b, mx, mn;
        scanf("%lld %lld",&a,&b);
        mx = querymx( a ), mn = querymn( a );
        if( a < 0 ) {
            if( mx <= b ) printf("ALL\n");
            else if( mn > b ) printf("NONE\n");
            else printf("SOME\n");
        } 
        else {
            if( mn >= b ) printf("ALL\n");
            else if( mx < b ) printf("NONE\n");
            else printf("SOME\n");
        }
    }
    return 0;
}