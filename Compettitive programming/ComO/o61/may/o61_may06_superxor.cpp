#include <bits/stdc++.h>
#define iii tuple<long long, long long, long long>
#define pii pair<long long, long long>
#define x first
#define y second 

using namespace std;

const int N = 1e5 + 10;
vector<pii> g[N];
vector<iii> ed;
vector<long long> mat, sol;
int n, m, q, chk[N];
long long d[N];

void dfs( long long u, long long p ) {
    chk[u] = true;
    for( pii v : g[u] ) if( v.x != p ) {
        if( chk[v.x] ) mat.emplace_back( d[u] ^ d[v.x] ^ v.y );
        else d[v.x] = d[u]  ^ v.y, dfs( v.x, u );
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&q);
    for( int i = 1 ; i <= m ; i++ ) {
        long long f, t, d;
        scanf("%lld %lld %lld",&f,&t,&d);
        g[f].emplace_back( pii( t, d ) ), g[t].emplace_back( pii( f, d ) );
    }
    dfs( 1LL, 0LL );
    for( int i = 62 ; i >= 0 ; i-- ) {
        long long now = 0;
        for( auto &x : mat ) if( x >> i & 1 ) now = x;
        if( !now ) continue ;
        sol.emplace_back( now );
        for( auto &x : mat ) if( x >> i & 1 ) x ^= now;
    }
    for( int i = 0, u, v ; i < q ; i++ ) {
        scanf("%d %d",&u,&v);
        long long ans = d[u] ^ d[v];
        for( auto x : sol ) if( ( ans ^ x ) > ans ) ans ^= x;
        printf("%lld\n",ans); 
    }
    return 0;
}