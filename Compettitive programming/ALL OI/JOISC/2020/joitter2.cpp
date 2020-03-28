#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
set<int> in[N], out[N], com[N], e[N];
long long ans;
long long par[N], sz[N];
int n, m;

int find( int u ) { return par[u] == u ? u : par[u] = find( par[u] ); }

long long cal( int u ) { return 1LL * ( ( ( int )e[u].size() - sz[u] ) * sz[u] ) + 1LL * sz[u] * ( sz[u]-1 ); }

void merge( int a, int b ) {
    vector<pii> v;
    a = find( a ), b = find( b );
    if( a == b ) return ;
    if( in[a].size() + out[a].size() + e[a].size() < in[b].size() + out[b].size() + e[b].size() ) swap( a, b );
    ans -= cal( a ), ans -= cal( b );
    in[a].erase( b ), in[b].erase( a ), out[a].erase( b ), out[b].erase( a );
    for( int x : in[b] ) {
        if( out[a].count( x ) ) v.emplace_back( x, a );
        out[x].erase( b ), out[x].emplace( a );
    }
    for( int x : out[b] ) {
        if( in[a].count( x ) ) v.emplace_back( x, a );
        in[x].erase( b ), in[x].emplace( a );
    }
    for( int x : in[b] ) in[a].emplace( x );
    for( int x : out[b] ) out[a].emplace( x );
    for( int x : e[b] ) e[a].emplace( x );
    in[b].clear(), out[b].clear(), e[b].clear();
    sz[a] += sz[b], par[b] = a;
    ans += cal( a );
    for( pii x : v ) merge( x.x, x.y ); 
}

int main()
{
    scanf("%d %d",&n,&m);
    iota( par, par + N, 0 ), fill( sz, sz + N, 1 );
    for( int i = 1 ; i <= n ; i++ ) e[i].emplace( i );
    while( m-- ) {
        int u, v;
        scanf("%d %d",&u,&v);
        int a = find( u ), b = find( v );
        if( out[b].count( a ) ) merge( u, v );
        else {
            ans -= cal( b );
            in[b].emplace( a ), out[a].emplace( b );
            e[b].emplace( u );
            ans += cal( b );
        }
        printf("%lld\n",ans);
    }
    return 0;
}