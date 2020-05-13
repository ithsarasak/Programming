#include "doll.h"
#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e5+5;
int lef[N], rig[N], arr[N], vis[N], cnt, pos;
 
int build( int l, int r ) {
    if( l == r ) return l;
    int mid = l + r >> 1, cur = ++cnt;
    lef[cur] = build( l, mid );
    rig[cur] = build( mid+1, r );
    //printf("build: l = %d, r = %d\n", l, r);
    //printf("switch = %d, lef = %d, rig = %d\n", -cur, lef[cur], rig[cur]);
    return -cur;
}
 
int fix( int num, int lim, int j ) {
    int cur = ++cnt;
    if ( num & ( 1<<j ) ) lef[cur] = build(lim+1, lim+(1<<j)), num -= (1<<j), lim += (1<<j);
    else lef[cur] = -1;
    if( j == 0 ) rig[cur] = 0;
    else rig[cur] = fix( num, lim, j-1 );
    //printf("fix: j = %d\n", j);
    //printf("cur = %d, lef = %d, rig = %d\n", -cur, lef[cur], rig[cur]);
    return -cur;
}
 
void create_circuit( int m, vector<int> A ) {
    int n = A.size();
    for( int i = 1 ; i <= n ; i++ ) arr[i] = A[i-1];
    int j = 0;
    while ( ( 1 << j ) <= n ) j++;
    vector<int> C( m+1 );
    C[0] = fix( n, 0, j-1 );
    for( int i = 1 ; i <= m ; i++ ) C[i] = C[0];
    int cur = -1;
    while( cur != 0 ){
        if( !vis[-cur] ){
            vis[-cur] ^= 1;
            if( lef[-cur] >= 1 ) lef[-cur] = arr[++pos], cur = C[0];
            else cur = lef[-cur];
        }
        else{
            vis[-cur] ^= 1;
            if( rig[-cur] >= 1 ) rig[-cur] = arr[++pos], cur = C[0];
            else cur = rig[-cur];
        }
    }

    vector<int> x, y;
    for ( int i = 0; i < cnt; i++ ) x.emplace_back( lef[i+1] ), y.emplace_back( rig[i+1] );
    answer( C, x, y );
}