#include<bits/stdc++.h>
int i, j, dp[2][10010], n, k, sum;
int main()
{
    scanf("%d %d",&n,&k);
    dp[0][0] = 1;
    for( i = 2 ; i <= n ; i++ ){
        sum = 0;
        for( j = 0 ; j <= k ; j++ ){
            if( j < i ){
                sum += dp[0][j];
            }
            else{
                sum += dp[0][j] - dp[0][j - i];
            }
            dp[1][j] = sum;
            if( dp[1][j] > 2012 ){
                dp[1][j] %= 2012;
            }
        }
        for( j = 0 ; j <= k ; j++ ){
            dp[0][j] = dp[1][j];
        }
    } 
    printf("%d",dp[0][k]);
    return 0;
}
