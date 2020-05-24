#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, dp[N][2][N], sum[N], mod = 2012;
char s[N];
int main()
{
    freopen( "bbreeds.in", "r", stdin );
    freopen( "bbreeds.out", "w", stdout );
    scanf("%s",&s[1]);
    n = strlen( &s[1] );
    for( int i = 1 ; i <= n ; i++ ) sum[i] = sum[i-1] + ( s[i] == '(' ? 1 : -1 );
    dp[0][0][0] = dp[0][1][0] = 1;
    for( int i = 1 ; i <= n ; i++ ) {
        if( s[i] == '(' ) {
            for( int j = 0 ; j < 2 ; j++ ) {
                for( int k = 1 ; k <= n ; k++ ) {
                    dp[i][j][k] = ( dp[i][j][k] + dp[i-1][j][k-1] ) % mod;
                    if( sum[i-1]-k+1 >= 0 && i > 1 ) dp[i][j][k] = ( dp[i][j][k] + dp[i-1][j^1][sum[i-1]-k+1] ) % mod;
                }
            }
        }
        else {
            for( int j = 0 ; j < 2 ; j++ ) {
                for( int k = 0 ; k < n ; k++ ) {
                    dp[i][j][k] = ( dp[i][j][k] + dp[i-1][j][k+1] ) % mod;
                    if( sum[i-1]-k-1 >= 0 && i > 1 ) dp[i][j][k] = ( dp[i][j][k] + dp[i-1][j^1][sum[i-1]-k-1] ) % mod;
                }
            }
        }
        /*printf("\n");
        for( int j = 0 ; j < 2 ; j++ ) {
            for( int k = 0 ; k <= n ; k++ ) printf("%d ",dp[i][j][k]);
            printf("\n");
        }*/
    }
    printf("%d",( dp[n][0][0] + dp[n][1][0] ) % mod);
    return 0;
}