#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, k, t[4*N][22], sz[N], dep[N], par[N], rot[N], lz[4*N], pos[N];
vector<int> g[N];

void dfs( int u, int p ) {
    if( p != 0 ) g[u].erase( find( g[u].begin(), g[u].end(), p ) );
    sz[u] = 1, par[u] = p, dep[u] = dep[p] + 1;
    for( int &v : g[u] ) {
        dfs( v, u );
        sz[u] += sz[v];
        if( sz[v] > sz[g[u][0]] ) swap( v, g[u][0] );
    }
}

void hld( int u ) {
    static int idx = 0;
    if( par[u] == 0 || u != g[par[u]][0] ) rot[u] = u;
    else rot[u] = rot[par[u]];
    pos[u] = ++idx;
    for( int v : g[u] ) hld( v );
}

void push( int l, int r, int idx ) {
    if( lz[idx] ) {
        vector<int> v(21);
        for( int i = 0 ; i < k ; i++ ) v[(i+lz[idx])%k] = t[idx][i];
        for( int i = 0 ; i < k ; i++ ) t[idx][i] = v[i];
        if( l != r ) lz[idx<<1] += lz[idx], lz[idx<<1|1] += lz[idx];
        lz[idx] = 0;
    }
}

void build( int l = 1, int r = n, int idx = 1 ) {
    if( l == r ) return void( t[idx][0] = 1 );
    int mid = l + r >> 1;
    build( l, mid, idx<<1 ), build( mid+1, r, idx<<1|1 );
    t[idx][0] = t[idx<<1][0] + t[idx<<1|1][0];
}

void update( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    push( l, r, idx );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz[idx] = ( lz[idx] + 1 ) % k;
        push( l, r, idx );
        return ;
    }
    int mid = l + r >> 1;
    update( ll, rr, l, mid, idx<<1 ), update( ll, rr, mid+1, r, idx<<1|1 );
    for( int i = 0 ; i < k ; i++ ) t[idx][i] = t[idx<<1][i] + t[idx<<1|1][i];
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 2, a ; i <= n ; i++ ) {
        scanf("%d",&a);
        g[a].emplace_back( i ), g[i].emplace_back( a );
    }
    dfs( 1, 0 ), hld( 1 ), build();
    for( int x = 1 ; x ; x = par[rot[x]] ) update( pos[rot[x]], pos[x] );
    for( int i = 2 ; i <= n ; i++ ) {
        for( int x = i ; x ; x = par[rot[x]] ) update( pos[rot[x]], pos[x] );
        //printf("%d\n",t[1][0]);
        if( i % k != 0 || t[1][0] - n + i != i / k ) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}