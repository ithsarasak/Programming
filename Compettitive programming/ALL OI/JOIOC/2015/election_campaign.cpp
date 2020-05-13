#include <bits/stdc++.h>
#define iii tuple<int, int, int>

using namespace std;

const int N = 1e5 + 10;

vector<iii> path[N];
vector<int> g[N];
int sz[N], par[N], dp[N], dep[N], rot[N], pos[N], n, q, sum[2][N], key[N];

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
    static int idx = 0;
    if( par[u] == 0 || g[par[u]][0] != u ) rot[u] = u;
    else rot[u] = rot[par[u]];
    pos[u] = ++idx;
    key[idx] = u;
    for( int v : g[u] ) hld( v );
}

int queryhld( int ty, int a, int b ) {
    int ret = 0, mi;
    while( rot[a] != rot[b] ) {
        if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
        if( rot[key[pos[a]+1]] != rot[a] ) mi = 0;
        else mi = sum[ty][pos[a]+1];
        ret += sum[ty][pos[rot[a]]] - mi;
        a = par[rot[a]];
    }
    if( dep[b] < dep[a] ) swap( a, b );
    if( rot[key[pos[b]+1]] != rot[b] ) mi = 0;
    else mi = sum[ty][pos[b]+1];
    ret += sum[ty][pos[a]] - mi;
    return ret;
}

int lca( int a, int b ) {
     while( rot[a] != rot[b] ) {
        if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
        a = par[rot[a]];
    }
    if( dep[b] < dep[a] ) return b;
    else return a;
}

void updt( int ty, int u, int va ) {
    if( rot[key[pos[u]+1]] != rot[u] ) sum[ty][pos[u]] = va;
    else sum[ty][pos[u]] = sum[ty][pos[u]+1] + va;
}

void solve( int u, int p ) {
    for( int v : g[u] ) if( v != p ) {
        solve( v, u );
        dp[u] += dp[v];
    }   
    updt( 0, u, dp[u] );
    updt( 1, u, 0 );
    for( iii x : path[u] ) {
        int a, b, c;
        tie( a, b, c ) = x;
        dp[u] = max( dp[u], c + queryhld( 0, a, b ) - queryhld( 1, a, b ) );
    }
    updt( 1, u, dp[u] );
}

int main()
{
    scanf("%d",&n);
    for( int i = 1, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    dfs( 1, 0 ), hld( 1 );
    scanf("%d",&q);
    for( int i = 1, a, b, c ; i <= q ; i++ ) {
        scanf("%d %d %d",&a,&b,&c);
        int x = lca( a, b );
        path[x].emplace_back( a, b, c );
    }
    solve( 1, 0 );
    printf("%d",dp[1]);
    return 0;
}