#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 2e6 + 10;

long long mod = 1e9 + 7;
vector<pii> vec;
int par[N], n;
map<int, int> mp;

int findroot( int now ) { return par[now] == now ? now : par[now] = findroot( par[now] ); }

int main()
{
    for( int i = 1 ; i < N ; i++ ) par[i] = i;
    scanf("%d",&n);
    for( int i = 1, x, y ; i <= n ; i++ ) {
        scanf("%d %d",&x,&y);
        vec.emplace_back( x, y );
    }
    sort( vec.begin(), vec.end() );
    for( int i = 0 ; i < n ; i++ ) {
        auto l = mp.lower_bound( vec[i].x ), r = mp.upper_bound( vec[i].y );
        if( r != mp.begin() ) {
            for( ; l != r ; l++ ) {
                par[findroot(i)] = findroot( l->y + n );
                par[findroot(i+n)] = findroot( l->y );
                if( findroot(l->y) == findroot( prev(r)->y )) break;
            }
        }
        mp[vec[i].y] = i;   
    }
    for( int i = 0 ; i < n ; i++ ) if( findroot( i ) == findroot( i+n ) ) return !printf("0\n");
    long long ans = 1;
    for( int i = 0 ; i < n ; i++ ) if( findroot( i ) == i ) ans = ( ans * 2LL ) % mod;
    printf("%lld\n",ans);
    return 0;
}