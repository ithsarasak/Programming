#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int n, sz[N], cpar[N], cdep[N], d[18][N];
vector<int> g[N];
bool chk[N];

int get_sz( int u, int p ) { sz[u] = 1; for( int v : g[u] ) if( v != p && !chk[v] ) sz[u] += get_sz( v, u ); return sz[u]; }

int find_cen( int u, int p, int all, pii &ret ) {
    int mx = all - sz[u];
    for( int v : g[u] ) if( v != p && !chk[v] ) mx = max( mx, find_cen( v, u, all, ret ) );
    ret = min( ret, pii( mx, u ) );
    return sz[u];
}


void dfs( int u, int p, int dep ) {
    for( int v : g[u] ) if( v != p && !chk[v] ) {
        d[dep][v] = d[dep][u] + 1;
        dfs( v, u, dep );
    }
}
void build_centroid( int u, int p ) {
    pii ret( 1e9, -1 );
    get_sz( u, u ), find_cen( u, u, sz[u], ret );
    cdep[u = ret.y] = cdep[p] + 1, cpar[u] = p, chk[u] = true;
    dfs( u, u, cdep[u] );
    for( int v : g[u] ) if( v != p && !chk[v] ) build_centroid( v, u );
}

int main()
{
    scanf("%d",&n);
    for( int i = 1, u, v ; i <= n - 1 ; i++ ) {
        scanf("%d %d",&u,&v);
        g[u].emplace_back( v ), g[v].emplace_back( u );
    }
    build_centroid( 1, 0 );
    for( int i = 1 ; i <= n ; i++ ) printf("%c ",cdep[i]-1+'A');
    return 0;
}