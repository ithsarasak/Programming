#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int n, k, q, c[N], col[15];
int chk[N], sz[N], par[N], dep[N];
long long d[N][17], sum1[15][N], sum2[15][N], ans[15];
int cnt1[15][N], cnt2[15][N];
vector<pii> g[N];

int getsz( int u, int p ) {
    sz[u] = 1;
    for( pii v : g[u] ) if( v.x != p && !chk[v.x] ) sz[u] += getsz( v.x, u );
    return sz[u];
}

int findcen( int u, int p, int all, pii &ret ) {
    int mx = all - sz[u];
    //printf("eiei %d %d\n",u,p);
    for( pii v : g[u] ) if( v.x != p && !chk[v.x] ) 
        mx = max( mx, findcen( v.x, u, all, ret ) );
    ret = min( ret, pii( mx, u ) );
    return sz[u];
}

void dfs( int u, int p, int dep ) {
    for( pii v : g[u] ) if( v.x != p && !chk[v.x] ) {
        d[v.x][dep] = d[u][dep] + v.y;
        dfs( v.x, u, dep );
    }
}

void build_centroid( int u, int p ) {
    pii ret( 1e9, -1 );
    //printf("U : %d P : %d\n",u,p);
    getsz( u, u ), findcen( u, u, sz[u], ret );
    dep[u = ret.y] = dep[p] + 1, par[u] = p, chk[u] = 1;
    dfs( u, u, dep[u] );
    //printf("cen : %d\n",u);
    for( pii v : g[u] ) if( !chk[v.x] ) build_centroid( v.x, u );
}

void update( int a, int del ) {
    cnt1[c[a]][a] += del, col[c[a]] += del;
    for( int i = par[a], pv = a ; i != 0 ; pv = i, i = par[i] ) {
        sum1[c[a]][i] += d[a][dep[i]] * del;
        sum2[c[a]][pv] += d[a][dep[i]] * del;
        cnt1[c[a]][i] += del;
        cnt2[c[a]][pv] += del;
    }
}

long long query( int a ) {
    long long ret = sum1[c[a]][a];
    for( int i = par[a], pv = a ; i != 0 ; pv = i, i = par[i] ) {
        ret += sum1[c[a]][i] - sum2[c[a]][pv];
        ret += ( cnt1[c[a]][i] - cnt2[c[a]][pv] ) * d[a][dep[i]];
    }
    return ret;
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&c[i]);
    for( int i = 1 ; i < n ; i++ ) {
        long long a, b, c;
        scanf("%lld %lld %lld",&a,&b,&c);
        g[a].emplace_back( pii( b, c ) ), g[b].emplace_back( pii( a, c ) );
    }
    build_centroid( 1, 0 );
    for( int i = 1 ; i <= n ; i++ ) {
        //printf("%d\n",query(i));
        ans[c[i]] += query( i );
        update( i, 1 );
    }
    scanf("%d",&q);
    while( q-- ) {
        int x, y, z;
        scanf("%d %d",&x,&y);
        if( x == 1 ) {
            //printf("%lld\n",ans[y]);
            if( col[y] < 2 ) printf("0\n");
            else printf("%f\n", (double)ans[y] / (double)( 1ll * col[y] * ( col[y] - 1 ) / 2ll ) );
        }
        else {
            scanf("%d",&z);
            update( y, -1 );
            ans[c[y]] -= query( y );
            c[y] = z;
            ans[c[y]] += query( y );
            update( y, 1 );
        }
    }
    return 0;
}