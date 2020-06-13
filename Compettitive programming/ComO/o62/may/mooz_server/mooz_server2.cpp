#include <bits/stdc++.h>
#include "mooz_server.h"
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 305;

vector<int> g[N], path[N], sub[N];
vector<pii> ans;
int par[N], n, edges;
bool vis[N];

void build_dfstree( int u ) {
    /*vis[u] = true;
    while( 1 ) {
        if( edges == n-1 ) return ;
        vector<int> nxt;
        for( int i = 1 ; i <= n ; i++ ) if( !vis[i] ) nxt.emplace_back( i );
        if( nxt.empty() ) return ;
        if( nxt.size() == 1 ) {
            vector<int> test;
            test.emplace_back( nxt[0] ), test.emplace_back( u );
            if( get_component( test ) == 1 ) {
                g[u].emplace_back( nxt[0] ), g[nxt[0]].emplace_back( u );
                edges++;
                build_dfstree( nxt[0] );
            }
            return ;
        }
        int l = 0, r = (int)nxt.size();
        while( l < r ) {
            vector<int> test;
            int mid = l + r >> 1;
            for( int i = 0 ; i <= min( mid, (int)nxt.size() - 1 ) ; i++ ) test.emplace_back( nxt[i] );
            int bef = get_component( test );
            test.emplace_back( u );
            int aft = get_component( test );
            if( aft == bef + 1 ) l = mid + 1;
            else r = mid;
        }
        if( l == (int)nxt.size() ) return ;
        g[u].emplace_back( nxt[l] ), g[nxt[l]].emplace_back( u );
        edges++;
        build_dfstree( nxt[l] );
    }*/
    for( int i = 1 ; i < n ; i++ ) g[i].emplace_back( i + 1 ), g[i+1].emplace_back( i );
}

void dfs( int u, int p, vector<int> vec ) {
    sub[u].emplace_back( u );
    path[u] = vec, par[u] = p;
    for( int v : g[u] ) if( v != p ) {
        vec.emplace_back( v );
        dfs( v, u, vec );
        for( int x : sub[v] ) sub[u].emplace_back( x );
        vec.pop_back();
    }
    
}

bool check1( int u, int p ) {
    vector<int> test;
    for( int v : g[u] ) if( v != p ) {
        for( int x : sub[v] ) test.emplace_back( x );
    }
    int bef = get_component( test );
    for( int x : path[p] ) test.emplace_back( x );
    int aft = get_component( test );
    if( aft == bef + 1 ) return 1;
    else return 0;
}

bool check2( int u, int p ) {
    vector<int> test;
    test.emplace_back( u );
    for( int x : path[p] ) if( x != p ) test.emplace_back( x );
    if( get_component( test ) == 2 ) return 1;
    else return 0;
}

void findans( int u, int p ) {
    if( p != 0 ) {
        if( check1( u, p ) && check2( u, p ) ) ans.emplace_back( pii( u, p ) );
    }
    for( int v : g[u] ) if( v != p ) findans( v, u );
}

vector< pair<int,int> > find_bridge( int N ) {
    n = N;
    build_dfstree( 1 );
    /*for( int i = 1 ; i <= n ; i++ ) {
        printf("%d : ",i);
        for( int v : g[i] ) printf("%d ",v);
        printf("\n");
    }*/
    dfs( 1, 0, vector<int>( 1, 1 ) ), findans( 1, 0 );
    return ans;
}