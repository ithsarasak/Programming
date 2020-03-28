#include <bits/stdc++.h>
#include <Ioi.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e4 + 10;
vector<pii> t[N], e, tre, init;
vector<int> g[N];
int par[N], id[N], re[N], deg[N], idx, n, m;
long long ans;

int find( int u ) { return u == par[u] ? u : par[u] = find( par[u] ); }
void dfs( int u, int p ) { re[u] = id[u] = idx++; for( int v : g[u] ) if( v != p ) dfs( v, u ); }

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

void get_ans( int u, int p ) {
    for( int v : g[u] ) if( v != p ) {
        int nex = Move( v );
        if( nex ) ans += 1ll << re[v];
        get_ans( v, u );
        Move( u );
    }
}
long long Ioi( int N, int M, int A[], int B[], int P, int V, int T ) {
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
    for( int i = 0 ; i < n ; i++ ) g[i].clear();
    for( pii e : t[P] ) g[e.x].emplace_back( e.y ), g[e.y].emplace_back( e.x );
    if( V ) ans += 1ll << re[P];
    get_ans( P, P );
    return ans;
}
