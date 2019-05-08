#include "ricehub.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
long long sum[N];

int check( int mid, int r, long long b, int x[] ) {
    for( int i = mid - 1 ; i < r ; i++ ) {
        int rb = i, lb = i - mid + 1;
        int m = ( rb + lb ) >> 1;
        long long cost = sum[rb+1] - sum[m+1] - sum[m] + sum[lb] + ( long long )x[m] * ( long long )( 2*m - rb - lb );
        if( cost <= b ) return 1;
    }
    return 0;
}

int besthub( int r, int l, int x[], long long b ) {
    sum[0] = 0;
    for( int i = 1 ; i <= r ; i++ ) sum[i] = sum[i-1] + ( long long )x[i-1];
    if( !check( 2, r, b, x ) ) return 1;
    int ll = 2, rr = r;
    while( ll < rr ) {
        int mid = ( ll + rr + 1 ) >> 1;
        if( check( mid, r, b, x ) ) ll = mid;
        else rr = mid - 1;
    }
    return ll;
}