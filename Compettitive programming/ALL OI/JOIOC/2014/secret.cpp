#include <bits/stdc++.h>
#include "secret.h"
 
const int N = 1e3 + 10;
 
int n, a[N], prer[10][N], prel[10][N];
 
void solve( int l, int r, int cnt ) {
    if( cnt > 9 || l == r ) return ;
    int mid = l + r >> 1;
    prer[cnt][mid+1] = a[mid+1];
    prel[cnt][mid] = a[mid];
    for( int i = mid - 1 ; i >= l ; i-- ) prel[cnt][i] = Secret( a[i], prel[cnt][i+1] );
    for( int i = mid + 2 ; i <= r ; i++ ) prer[cnt][i] = Secret( prer[cnt][i-1], a[i] );
    solve( l, mid, cnt+1 ), solve( mid+1, r, cnt+1 );
}
 
 
void Init( int N_, int A[] ) {
    n = N_;
    for( int i = 0 ; i < n ; i++ ) a[i] = A[i];
    solve( 0, n-1, 1 );
}
 
int cal( int ll, int rr, int l, int r, int cnt ) {
    int mid = l + r >> 1;
    if( ll <= mid && mid + 1 <= rr ) return Secret( prel[cnt][ll], prer[cnt][rr] );
    else if( rr <= mid ) return cal( ll, rr, l, mid, cnt + 1 );
    else return cal( ll, rr, mid + 1, r, cnt + 1 );
}
 
int Query( int L, int R ) { 
    if( L == R ) return a[L];
    else if( L + 1 == R ) return Secret( a[L], a[R] );
    return cal( L, R, 0, n-1, 1 ); 
}