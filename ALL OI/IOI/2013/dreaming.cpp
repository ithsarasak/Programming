#include "dreaming.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
 
const int N = 1e5+5, INF = 1e9+1;
 
vector<pii> g[N];
bool check[N];
int ans;
pii mx1[N], mx2[N];
 
void dfs( int u, int p ) {
    check[u] = true;
    for( pii v : g[u] ) if( v.x != p ) {
        dfs( v.x, u );
        pii ret( mx1[v.x].x + v.y, v.x );
        if( ret > mx1[u] ) swap( ret, mx1[u] );
        if( ret > mx2[u] ) swap( ret, mx2[u] );
    } 
    ans = max( ans, mx1[u].x + mx2[u].x );
} 
 
void find(int u, int p, int d, int &ret) {
    int now = max( mx1[u].x, d );
    if( now < ret ) ret = now;
    for( pii v : g[u] ) if( v.x != p ) 
        find( v.x, u, max( d, mx1[u].y == v.x ? mx2[u].x : mx1[u].x ) + v.y, ret );
}
 
int travelTime( int N, int M, int L, int A[], int B[], int T[] ) {
    for( int i = 0 ; i < M ; i++ ) {
        g[A[i]].emplace_back( B[i], T[i] );
        g[B[i]].emplace_back( A[i], T[i] );
    }
    vector<int> V;
    for( int i = 0; i < N; i++ ) if( !check[i] ) {   
        dfs( i, -1 ); 
        int shortest = INF;
        find( i, -1, 0, shortest );
        V.emplace_back( shortest );
    }
    sort( V.begin(), V.end(), greater<int>() );
    if( V.size() >= 2 ) ans = max( ans, V[0] + V[1] + L );
    if( V.size() >= 3 ) ans = max( ans, V[1] + V[2] + L + L );
    return ans;
}