#include <bits/stdc++.h>

using namespace std;

const int M = 110;
const int K = 510;

int n, m, k;
long long dp[M][K], band[M];

long long cal( long long num, long long k ) {
    long long seg1 = 0, seg2 = 0, times1 = 0, times2 = 0;
    seg1 = num / ( k + 1 );
    seg2 = seg1 + 1;
    times1 = k + 1;
    times2 = num % ( k + 1 );
    times1 -= times2;
    return ( ( times1 * seg1 * ( seg1 + 1 ) ) + ( times2 * seg2 * ( seg2 + 1 ) ) ) / 2;
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1, ba ; i <= n ; i++ ) {
        scanf("%d",&ba);
        band[ba]++;
    }
    memset( dp, 127, sizeof dp );
    dp[0][0] = 0;
    for( int i = 1 ; i <= m ; i++ ) {
        dp[i][0] = dp[i-1][0] + ( band[i] * ( band[i] + 1 ) ) / 2;
        long long ret = 1e18;
        for( int j = 1 ; j <= k ; j++ ) {
            for( int k = 0 ; k <= j && k <= band[i] ; k++ ) ret = min( ret, cal( ( long long )band[i], ( long long )k ) + dp[i-1][j-k] );
            dp[i][j] = ret;
        }
    }
    printf("%lld",dp[m][k]);
    return 0;
}