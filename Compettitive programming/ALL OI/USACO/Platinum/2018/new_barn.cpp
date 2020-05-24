#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

int q, cnt;
vector<pii> ask;
vector<int> g[N];
pii mx1[N], mx2[N];
int sz[N], dep[N], d[N][20], par[N];
bool ok[N], chk[N];

int getsz( int u, int p ) { sz[u] = 1; for( int v : g[u] ) if( v != p && !chk[v] ) sz[u] += getsz( v,u ); return sz[u]; }

int findcen( int u, int p, int all, pii &ret ) {
    int mx = all - sz[u];
    for( int v : g[u] ) if( v != p && !chk[v] ) mx = max( mx, findcen( v, u, all, ret ) );
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
    getsz( u, u ), findcen( u, u, sz[u], ret );
    dep[u=ret.y] = dep[p] + 1, par[u] = p;
    d[u][dep[u]] = 0;
    chk[u] = true;
    dfs( u, u, dep[u] ); 
    for( int v : g[u] ) if( !chk[v] ) build_centroid( v, u );
}

void update( int u ) {
    ok[u] = true;
    //printf("U : %d\n",u);
    for( int v = par[u], pv = u ; v ; pv = v, v = par[v]) {
        pii now( d[u][dep[v]], pv );
        //printf("%d\n",v);
        if( mx1[v].y == pv ) mx1[v].x = max( mx1[v].x, d[u][dep[v]] ), now = pii( -1, -1 );
        if( mx2[v].y == pv ) mx2[v].x = max( mx2[v].x, d[u][dep[v]] ), now = pii( -1, -1 );
        if( mx1[v] < mx2[v] ) swap( mx1[v], mx2[v] );
        if( now > mx1[v] ) swap( mx1[v], now );
        if( now > mx2[v] ) swap( mx2[v], now );
    }
}

int query( int u ) {
    //printf("Q : %d\n",u);
    int ret = mx1[u].y != -1 ? mx1[u].x : 0;
    for( int v = par[u], pv = u ; v ; pv = v, v = par[v] ) if( ok[v] ) {
        ret = max( ret, d[u][dep[v]] );
        //printf("%d %d %d %d %d %d\n",v,d[u][dep[v]],mx1[v].y,mx1[v].x,mx2[v].y,mx2[v].x);
        if( mx1[v].y != pv && mx1[v].y != -1 ) ret = max( ret, d[u][dep[v]] + mx1[v].x );
        if( mx2[v].y != pv && mx2[v].y != -1 ) ret = max( ret, d[u][dep[v]] + mx2[v].x );
    }
    return ret;
}
int main()
{
    freopen( "newbarn.in", "r", stdin );
    freopen( "newbarn.out", "w", stdout );
    for( int i = 0 ; i < N ; i++ ) mx1[i] = mx2[i] = pii( -1, -1 );
    scanf("%d",&q);
    for( int i = 1, a ; i <= q ; i++ ) {
        char c;
        scanf(" %c %d",&c,&a);
        if( c == 'B' ) {
            ask.emplace_back( 0, ++cnt );
            if( a == -1 ) continue;
            g[cnt].emplace_back( a ), g[a].emplace_back( cnt );
        }
        else ask.emplace_back( 1, a );
    }
    for( int i = 1 ; i <= cnt ; i++ ) if( !chk[i] ) build_centroid( i, 0 );
    for( pii x : ask ) {
        if( !x.x ) update( x.y );
        else printf("%d\n",query( x.y ));
    }
    return 0;
}