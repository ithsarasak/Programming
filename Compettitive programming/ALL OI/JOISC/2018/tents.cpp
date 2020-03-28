#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const long long mod = 1e9 + 7;
long long dp[N][N];
int h, w;
int main()
{
    scanf("%d %d",&h,&w);
    for( int i = 0 ; i <= w ; i++ ) dp[0][i] = 1;
    for( int i = 0 ; i <= h ; i++ ) dp[i][0] = 1;
    for( int i = 1 ; i <= h ; i++ ) {
        for( int j = 1 ; j <= w ; j++ ) {
            dp[i][j] = dp[i-1][j];
            dp[i][j] = ( dp[i][j] + dp[i-1][j-1] * 4 * j ) % mod;
            if( i > 1 ) dp[i][j] = ( dp[i][j] + dp[i-2][j-1] * ( long long )( i-1 ) * ( long long )j ) % mod;
            if( j > 1 ) dp[i][j] = ( dp[i][j] + dp[i-1][j-2] * ( ( long long )j * ( long long )(j-1) / 2LL ) ) % mod;
        }
    }
    //printf("%lld ",dp[1][1]);
    printf("%lld",( dp[h][w] - 1 + mod ) % mod );
    return 0;
}