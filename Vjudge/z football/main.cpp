#include<bits/stdc++.h>
int m, n, k, i, j;
int dp[2][10010];
int abs( int x )
{
    if( x < 0 ){
        return -1 * x;
    }
    else{
        return x;
    }
}
int main()
{
    scanf("%d %d %d",&m,&n,&k);
    for( i = 0 ; i <= n ; i++ ){
        if( i <= k )
        dp[0][i] = 1;
    }
    for( i = 1 ; i <= m ; i++ ){
        //printf("%d\n",j);
        for( j = 0 ; j <= n ; j++ ){
            //printf("%d\n",j);
            if( abs( i - j ) <= k ){
                if( j == 0 ){
                    dp[1][j] = 1;
                }
                else{
                    dp[1][j] =  ( dp[0][j] + dp[1][j - 1] ) % 1000007;
                }
            }
        }
        for( j = 0 ; j <= n ; j++ ){
            //printf("%d\n",j);
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    printf("%d",dp[0][n]);
    return 0;
}
