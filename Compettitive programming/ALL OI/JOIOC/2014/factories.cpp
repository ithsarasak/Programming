#include <bits/stdc++.h>
#include "factories.h"

#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

const int N = 5e5 + 10;
int book[N], sz[N], dep[N], par[N], n, now;
bool chk[N];
long long d[N][25], mn[N];
vector<pii> g[N];

int getsz( int u, int p ) { sz[u] = 1; for( pii v : g[u] ) if( v.x != p && !chk[v.x] ) sz[u] += getsz( v.x, u ); return sz[u]; }

int find_cen( int u, int p, int all, pii &ret ) {
    int mx = all - sz[u];
    for( pii v : g[u] ) if( v.x != p && !chk[v.x] ) {
        mx = max( mx, find_cen( v.x, u, all, ret ) );
    }
    ret = min( ret, pii( mx, u ) );
    return sz[u];
}

void dfs( int u, int p, int dep ) {
    for( pii v : g[u] ) if( v.x != p && !chk[v.x] ) {
        d[v.x][dep] = d[u][dep] + ( long long )v.y;
        dfs( v.x, u, dep );
    }
}

void build_centroid( int u, int p ) {
    pii ret( 1e9, -1 );
    getsz( u, u ), find_cen( u, u, sz[u], ret );
    //printf("%d %d %d\n",sz[u],ret.x,ret.y);
    dep[u=ret.y] = dep[p] + 1, par[u] = p;
    //printf("centroid : %d\n",u);
    dfs( u, u, dep[u] );
    chk[u] = true;
    for( pii v : g[u] ) if( !chk[v.x] ) build_centroid( v.x, u );
}

long long query( int u ) {
    //printf("QUERY%d\n",u);
    long long ret = 1e18;
    if( book[u] == now ) ret = min( ret, mn[u] );
    for( int i = par[u] ; i ; i = par[i] ) {
        //printf("%d %d\n",i,par[i]);
        if( book[i] != now ) continue ;
        ret = min( mn[i] + d[u][dep[i]], ret );
    }
    return ret;
}

void update( int u ) {
    //printf("UPDATE%d\n",u);
    book[u] = now, mn[u] = 0;
    for( int i = par[u] ; i ; i = par[i] ) {
        if( book[i] != now ) {
            book[i] = now, mn[i] = d[u][dep[i]];
        }
        else mn[i] = min( mn[i], d[u][dep[i]] );
        //printf("%d %d %d %d\n",i,par[i],book[i],mn[i]);
    }
}

void Init( int N, int A[], int B[], int D[] ) {
    n = N;
    for( int i = 0 ; i < n-1 ; i++ ) g[++A[i]].emplace_back(++B[i],D[i]), g[B[i]].emplace_back( A[i], D[i] );
    dep[1] = 1;
    build_centroid( 1, 0 );
}

long long Query( int s, int x[], int t, int y[] ) {
    ++now;
    long long ret = 1e18;
    for( int i = 0 ; i < s ; i++ ) update( ++x[i] );
    for( int i = 0 ; i < t ; i++ ) {
        ret = min( ret, query( ++y[i] ) );
    }
    return ret;
}
/*int main()
{
    int n, q, a[100], b[100], d[100];
    scanf("%d %d",&n,&q);
    for( int i = 0 ; i < n - 1 ; i++ ) scanf("%d %d %d",&a[i],&b[i],&d[i]);
    Init( n, a, b, d );
    for( int i = 0 ; i < q ; i++ ) {
        int s, t, x[100], y[100];
        scanf("%d %d",&s,&t);
        for( int j = 0 ; j < s ; j++ ) scanf("%d",&x[j]);
        for( int j = 0 ; j < t ; j++ ) scanf("%d",&y[j]);
        printf("%lld\n",Query( s, x, t, y ) );
    }
    return 0;
}*/