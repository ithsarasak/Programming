#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 10;

int n, q, sz[N], par[N], dep[N], d[N][18];
vector<int> g[N];
ordered_set<pii> s1[N], s2[N];
bool chk[N];

int getsz( int u, int p ) { sz[u] = 1; for( int v : g[u] ) if( v != p && !chk[v] ) sz[u] += getsz( v, u ); return sz[u]; }

int find_cen( int u, int p, int all, pii &ret ) {
    int mx = all - sz[u];
    for( int v : g[u] ) if( v != p && !chk[v] ) 
        mx = max( mx, find_cen( v, p, all, ret ) );
    ret = min( ret, pii( mx, u ) );
    return sz[u];
}

void dfs( int u, int p, int dep ) {
    for( int v : g[u] ) if( v != p && !chk[v] ) {
        d[v][dep] = d[u][dep] + 1;
        dfs( v, u, dep );
    }
}

void build_centroid( int u, int p ) {
    pii ret( 1e9, -1 );
    getsz( u, u ), find_cen( u, u, sz[u], ret );
    par[u = ret.y] = p, dep[u] = dep[p] + 1, chk[u] = 1;
    dfs( u, u, dep[u] );
    for( int v : g[u] ) if( !chk[v] ) build_centroid( v, u );
}

void update( int a, int k ) {
    s1[a].insert( k );
    for( int i = par[a], pv = a ; i ; pv = i, i = par[i] ) 
        if( k >= d[a][dep[i]] ) s1[i].insert( k - d[a][dep[i]] ), s2[pv].insert( k - d[a][dep[i]] );
}

int query( int a ) {
    int ret = s1[a].size();
    for( int i = par[a], pv = a ; i ; pv = i, i = par[i] ) {
        ret += ( ( int )s1[i].size() - s1[i].order_of_key( d[a][dep[i]] ) );
        ret -= ( ( int )s2[pv].size() - s2[pv].order_of_key( d[a][dep[i]] ) );
    }
    return ret;
}

int main()
{
    scanf("%d %d",&n,&q);
    for( int i = 1, u, v ; i < n ; i++ ) {
        scanf("%d %d",&u,&v);
        g[u].emplace_back( v ), g[v].emplace_back( u );
    }
    build_centroid( 1, 0 );
    for( int i = 1, t, a, b ; i <= q ; i++ ) {
        scanf("%d %d",&t,&a);
        if( t == 1 ) {
            scanf("%d",&b);
            update( a, b );
        }
        else printf("%d\n",query( a ) );
    } 
    return 0;
}