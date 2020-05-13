#include "treasure.h"
#include <bits/stdc++.h>
using namespace std;
 
const int N = 110;
int pref[N][N];
 
void findTreasure( int n ) {
    int m = n >> 1;
    for( int i = n ; i > 0 ; i-- ) for( int j = n ; j > 0 ; --j ) {
        if( i > m && j > m ) pref[i][j] = countTreasure( 1, 1, i, j );
        if( i <= m && j > m ) pref[i][j] = pref[n][j] - countTreasure( i+1, 1, n, j );
        if( i > m && j <= m ) pref[i][j] = pref[i][n] - countTreasure( 1, j+1, i, n );
        if( i <= m && j <= m ) pref[i][j] = pref[n][j] + pref[i][n] - pref[n][n] + countTreasure( i+1, j+1, n, n );
    }
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= n ; j++ ) if( pref[i][j] - pref[i-1][j] - pref[i][j-1] + pref[i-1][j-1] ) Report( i, j );
}