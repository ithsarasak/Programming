#include <bits/stdc++.h>
#include "boxes.h"

using namespace std;

const int N = 1e7 + 10;
long long ans = 1e18, dpr[N], dpl[N], n, k, l, p[N];

long long delivery( int N, int K, int L, int P[] ) {
    n = ( long long )N, k = ( long long )K, l = ( long long )L;
    for( int i = 1 ; i <= n ; i++ ) p[i] = ( long long )P[i-1];
    for( int i = 1 ; i <= n ; i++ ) dpr[i] = ( p[i] <= l / 2 ? p[i] * 2LL : l ) + dpr[max( 0LL, ( long long )i - k )];
    for( int i = n ; i >= 1 ; i-- ) dpl[i] = ( p[i] >= l / 2 ? ( l - p[i] ) * 2LL : l ) + dpl[min( n + 1, ( long long )i + k )];
    for( int i = 0 ; i <= n ; i++ ) ans = min( ans, dpr[i] + dpl[i+1] );
    return ans;
}