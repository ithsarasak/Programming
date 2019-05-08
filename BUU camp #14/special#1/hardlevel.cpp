#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50010;
int n, hard[3][N], dp[N][3][3], ans = 1e9;
int main() 
{
    scanf("%d",&n);
    for( int i = 0 ; i < 3 ; i++ ) for( int j = 1 ; j <= n ; j++ ) scanf("%d",&hard[i][j]);
    for( int i = 0 ; i < 3 ; i++ ) for( int j = 1 ; j <= n ; j++ ) {
        dp[j][i][0] = hard[i][j] + dp[j-1][i][0];
    }
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = 0 ; j < 3 ; j++ ) {
            for( int k = 1 ; k <= 3 ; k++ ) {
                dp[i][j][k]  = min( dp[i-1][( j+1 )%3][k-1] , dp[i-1][( j+2 )%3][k-1] ) + hard[j][i];

            }
        }
    }
    for( int i = 0 ; i < 3 ; i++ ) {
        printf("%d",dp[n][i][3] );
        ans = min( ans, dp[n][i][3] );
    }
    printf("%d",ans);
    return 0;
}