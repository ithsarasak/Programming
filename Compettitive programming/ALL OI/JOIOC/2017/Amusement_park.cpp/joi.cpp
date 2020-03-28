#include <bits/stdc++.h>
#include <Joi.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e4 + 10;
vector<pii> t[N], e, tre, init;
vector<int> g[N];
int par[N], id[N], re[N], deg[N], idx, n, m;

void dfs( int u, int p ) { id[u] = idx++; for( int v : g[u] ) if( v != p ) dfs( v, u ); }
int find( int u ) { return u == par[u] ? u : par[u] = find( par[u] ); }

void extend_tree( int u, int p ) {
    if( !t[u].empty() ) return;
    int leaf;
    vector<pii> tree = t[p];
    for( pii e : tree ) ++deg[e.x], ++deg[e.y];
    for( pii e : tree ) {
        int a, b; tie( a, b ) = e;
        if( deg[a] == 1 && a != p ) { leaf = a; break; }
        if( deg[b] == 1 && b != p ) { leaf = b; break; }
    }
    re[u] = re[leaf];
    for( pii e : tree ) {
        --deg[e.x], --deg[e.y];
        if( e.x == leaf || e.y == leaf ) continue;
        t[u].emplace_back( e );
    }
    t[u].emplace_back( u, p );
    for( int v : g[u] ) if( v != p ) extend_tree( v, u );
}

void Joi( int N, int M, int A[], int B[], long long X, int T ) {
    n = N, m = M;
    iota( par, par + N, 0 );
    for( int i = 0 ; i < m ; i++ ) e.emplace_back( pii( A[i], B[i] ) );
    for( pii x : e ) {
        int a = find( x.x ), b = find( x.y );
        if( a != b ) {
            par[a] = b;
            g[x.x].emplace_back( x.y );
            g[x.y].emplace_back( x.x );
            tre.emplace_back( x );
        }
    }
    dfs( 0, 0 );
    for( pii e : tre ) if( id[e.x] < 60 && id[e.y] < 60 ) init.emplace_back( e );
    for( int i = 0 ; i < n ; i++ ) if( id[i] < 60 ) {
        re[i] = id[i];
        t[i] = init;
    }
    for( int i = 0 ; i < n ; i++ ) if( id[i] < 60 ) for( int v : g[i] ) extend_tree( v, i );
    for( int i = 0 ; i < n ; i++ ) MessageBoard( i, X >> re[i] & 1 );
}
