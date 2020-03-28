#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
const int K = 11;

int n, k, q, sz[N], cdep[N], par[N], col[K], c[N];
long long cnt1[K][N], cnt2[K][N], sum1[K][N], sum2[K][N], d[N][18], ans[K];
bool chk[N];
vector<pii> g[N];

int getsz( int u, int p ) { sz[u] = 1; for( pii v : g[u] ) if( v.x != p && !chk[v.x] ) sz[u] += getsz( v.x, u ); return sz[u]; }

int find_cen( int u, int p, int all, pii &ret ) {
    int mx = all - sz[u];
    for( pii v : g[u] ) if( v.x != p && !chk[v.x] ) 
        mx = max( mx, find_cen( v.x, u, all, ret ) );
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
    //printf("%d %d\n",u,p);
    pii ret( 1e9, -1 );
    getsz( u, u );
    //printf("%d\n",sz[u]);
    find_cen( u, u, sz[u], ret );
    cdep[u = ret.y] = cdep[p] + 1, par[u] = p, chk[u] = true;
    //printf("%d\n",u);
    dfs( u, u, cdep[u] );
    for( pii v : g[u] ) if( !chk[v.x] ) build_centroid( v.x, u );
}

void update( int a, bool del ) {
    if( del ) --cnt1[c[a]][a];
    else ++cnt1[c[a]][a];
    for( int i = par[a], pv = a ; i ; pv = i, i = par[i] ) {
        sum1[c[a]][i] += d[a][cdep[i]] * ( del ? -1ll : 1ll );
        sum2[c[a]][pv] += d[a][cdep[i]] * ( del ? -1ll : 1ll );
        if( del ) cnt1[c[a]][i]--, cnt2[c[a]][pv]--;
        else cnt1[c[a]][i]++, cnt2[c[a]][pv]++; 
    }
}

long long query( int a ) {
    long long ret = sum1[c[a]][a];
    for( int i = par[a], pv = a ; i ; pv = i, i = par[i] ) {
        ret += sum1[c[a]][i] - sum2[c[a]][pv] + ( cnt1[c[a]][i] - cnt2[c[a]][pv] ) * d[a][cdep[i]];
    }
    return ret;
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&c[i]);
    for( int i = 1 ,u, v, d ; i < n ; i++ ) {
        scanf("%d %d %d",&u,&v,&d);
        g[u].emplace_back( pii( v, d ) ), g[v].emplace_back( pii( u, d ) );
    }
    build_centroid( 1, 0 );
    for( int i = 1 ; i <= n ; i++ ) {
        ans[c[i]] += query( i );
        update( i, 0 );
        col[c[i]]++;
        printf("%lld\n",ans[c[i]]);
    }
    scanf("%d",&q);
    for( int i = 1, t, a, b ; i <= q ; i++ ) {
        scanf("%d %d",&t,&a);
        if( t == 1 ) {
            if( col[a] == 0 ) printf("-1\n");
            if( col[a] < 2 ) printf("%.12lf\n",0);
            else printf("%.12lf\n",(double)ans[a] / (double)( 1ll * col[a] * ( col[a]-1 ) / 2ll ) );
        }
        else {
            scanf("%d",&b);
            update( a, 1 );
            ans[c[a]] -= query( a );
            col[c[a]]--;
            c[a] = b;
            col[c[a]]++;
            ans[c[a]] += query( a );
            update( a, 0 );
        }
    }
    return 0;
}