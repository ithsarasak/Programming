#include <bits/stdc++.h>
#include "gardenlib.h"
#include "garden.h"
 
using namespace std;
 
const int N = 3e5 + 10;
int chk[N], d[N], to[N], cyc;
vector<int> vec, g[N];
 
void dfs( int u ) {
    chk[u] = 1, vec.emplace_back( u );
    for( int v : g[u] ) {
        if( !chk[v] ) d[v] = d[u] + 1, dfs( v );
        else if( chk[v] == 1 ) for( int i = (int)vec.size() - 1 ; i >= 0 ; i-- ) {
            cyc++;
            if( vec[i] == v ) break;
        }
    }
    chk[u] = 2, vec.pop_back();
}
 
void count_routes( int n, int m, int p, int r[][2], int q, int G[] ) {
    for( int i = 0 ; i < m ; i++ ) {
        if( g[r[i][0]].size() < 2 ) g[r[i][0]].emplace_back( r[i][1] );
        if( g[r[i][1]].size() < 2 ) g[r[i][1]].emplace_back( r[i][0] );
    }
    for( int i = 0 ; i < n ; i++ ) for( int j = 0 ; j < g[i].size() ; j++ ) {
        int v = g[i][j], now = i + j*n;
        if( g[v][0] == i && g[v].size() > 1 ) {
            to[now] = v + n;
            if( g[i].size() == 1 ) to[i+n] = v + n;
        }
        else {
            to[now] = v;
            if( g[i].size() == 1 ) to[i+n] = v + n;
        }
    }
    for( int i = 0 ; i < 2*n ; i++ ) g[i].clear();
    for( int i = 0 ; i < 2*n ; i++ ) g[to[i]].emplace_back( i );
    vector<int> ans( q, 0 );
    vec.clear(), memset( d, 127, sizeof d ), d[p] = cyc = 0, memset( chk, 0, sizeof chk );
    dfs( p );
    for( int i = 0 ; i < q ; i++ ) {
        for( int j = 0 ; j < n ; j++ ) {
            if( d[j] > G[i] ) continue ;
            if( cyc ) ans[i] += ( ( G[i] - d[j] ) % cyc == 0 );
            else ans[i] += ( d[j] == G[i] );
        }
    }
    vec.clear(), memset( d, 127, sizeof d ), d[p+n] = cyc = 0, memset( chk, 0, sizeof chk );
    dfs( p+n );
    for( int i = 0 ; i < q ; i++ ) {
        for( int j = 0 ; j < n ; j++ ) {
            if( d[j] > G[i] ) continue ;
            if( cyc ) ans[i] += ( ( G[i] - d[j] ) % cyc == 0 );
            else ans[i] += ( d[j] == G[i] );
        }
       answer( ans[i] );   
    }
}