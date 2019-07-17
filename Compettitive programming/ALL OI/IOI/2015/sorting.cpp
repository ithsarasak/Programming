#include <bits/stdc++.h>
#include "sorting.h"
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

const int NN = 2e5 + 10;
const int MM = 6e5 + 10;

int n, m, s[NN], x[MM], y[MM];

vector<pii> chk( int mid ) {
    int pos[NN], te[NN];
    vector<pii> ret;
    for( int i = 0 ; i < n ; i++ ) te[i] = s[i];
    for( int i = 0 ; i < mid ; i++ ) swap( te[x[i]], te[y[i]] );
    for( int i = 0 ; i < n ; i++ ) pos[te[i]] = i;
    for( int i = 0 ; i < n ; i++ ) if( te[i] != i ) {
        ret.emplace_back( pii( te[i], i ) );
        int now = te[i];
        swap( te[i], te[pos[i]] );
        swap( pos[now], pos[i] );
    }
    return ret;
}

int findSwapPairs( int N, int S[], int M, int X[], int Y[], int p[], int q[] ) {
    int pos[NN];
    n = N, m = M;
    for( int i = 0 ; i < n ; i++ ) s[i] = S[i];
    for( int i = 0 ; i < m ; i++ ) x[i] = X[i], y[i] = Y[i];
    int l = 0, r = m;
    while( l < r ) {
        int mid = ( l + r ) >> 1;
        if( chk( mid ).size() <= mid ) r = mid;
        else l = mid + 1;
    } 
    vector<pii> ans = chk( l );
    for( int i = 0 ; i < n ; i++ ) pos[s[i]] = i;
    for( int i = 0 ; i < r ; i++ ) {
        swap( pos[s[x[i]]], pos[s[y[i]]] );
        swap( s[x[i]], s[y[i]] );
        if( i < ans.size() ) {
            int a = ans[i].x, b = ans[i].y;
            p[i] = pos[a], q[i] = pos[b];
            swap( s[pos[a]], s[pos[b]] );
            swap( pos[a], pos[b] );
        } 
    }
    for( int i = ans.size() ; i < r ; i++ ) p[i] = 0, q[i] = 0;
    return l;
}