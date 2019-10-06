#include <bits/stdc++.h>

using namespace std;

void dfs1( int u, int p ) {
    erase( find( g[u].begin(), g[u].end(), p ) );
    sz[u] = 1, par[u] = p, dep[u] = dep[p] + 1;
    for( int &v : g[u] ) {
        dfs1( v, u );
        sz[u] += sz[v];
        if( sz[v] > sz[g[u][0]] ) swap( v, g[u][0] );
    }
    return sz[u];
}

void hld( int u ) {
    static idx = 1;
    if( par[u] == 0 || u != g[par[u]][0] ) rot[u] = u;
    else rot[u] = rot[par[u]];
    updatetree( idx, va[u] );
    pos[u] = idx++;
    for( int &v : g[u] ) hld( v );
    return ;
}

void updatehld( int u ) {
    updatetree( pos[u], va[u] );
}

void queryhld( int a, int b ) {
    while( rot[a] != rot[b] ) {
        if( dep[rot[a]] > dep[rot[b]] ) swap( a, b );
        ret = min( ret, querytree( pos[rot[b]], pos[b] ) );
        b = par[rot[b]];
    }
    if( dep[a] > dep[b] ) swap( a, b );
    ret = min( ret, querytree( pos[a], pos[b] ) );
    return ret;
}
int main()
{
    return 0;
}