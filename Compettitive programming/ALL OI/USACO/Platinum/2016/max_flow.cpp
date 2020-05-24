#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;

int n, k, lz[N*4], t[N*4], sz[N], dep[N], par[N], idx, rot[N], pos[N];
vector<int> g[N];

void dfs( int u, int p ) {
    if( p != 0 ) g[u].erase( find( g[u].begin(), g[u].end(), p ) );
    par[u] = p, sz[u] = 1, dep[u] = dep[p] + 1;
    for( int &v : g[u] ) if( v != p ) {
        dfs( v, u );
        sz[u] += sz[v];
        if( sz[v] > sz[g[u][0]] ) swap( v, g[u][0] );
    }
}

void hld( int u ) {
    if( par[u] == 0 || g[par[u]][0] != u ) rot[u] = u;
    else rot[u] = rot[par[u]];
    pos[u] = ++idx;
    for( int v : g[u] ) hld( v ); 
}

void push( int l, int r, int idx ) {
    if( !lz[idx] ) return;
    t[idx] += lz[idx];
    if( l != r ) lz[idx<<1] += lz[idx], lz[idx<<1|1] += lz[idx];
    lz[idx] = 0;
}

void update( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    push( l, r, idx );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz[idx] += 1;
        push( l, r, idx );
        return ;
    }
    int mid = l + r >> 1;
    update( ll, rr, l, mid, idx<<1 ), update( ll, rr, mid+1, r, idx<<1|1 );
    t[idx] = max( t[idx<<1], t[idx<<1|1] );
}

void uphld( int a, int b ) {
    //printf("TIME\n",a,b);
    while( rot[a] != rot[b] ) {
        //printf("%d %d\n",a,b);
        if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
        update( pos[rot[a]], pos[a] );
        a = par[rot[a]];
    }
    if( dep[a] > dep[b] ) swap( a, b );
    //printf("eiei : %d %d\n",pos[a],pos[b]);
    update( pos[a], pos[b] );
}

int main()
{
    freopen("maxflow.in", "r", stdin );
    freopen("maxflow.out", "w", stdout );
    scanf("%d %d",&n,&k);
    for( int i = 1, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }   
    dfs( 1, 0 ), hld( 1 );
    for( int i = 1, a, b ; i <= k ; i++ ) {
        scanf("%d %d",&a,&b);
        uphld( a, b );
    }
    printf("%d",t[1]);
    return 0;
}