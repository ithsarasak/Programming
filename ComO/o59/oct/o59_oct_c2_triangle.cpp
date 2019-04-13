#include <bits/stdc++.h>

using namespace std;
int n, k;
const int mod = 1e9+7;
long long dp[150][150];
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 1 ; i <= min(k+1,n) ; i++ ){
        dp[1][i] = ((i-1)*(i))/2;
        dp[i][1] = dp[1][i];
    }
    for( int i = k+2 ; i <= n ; i++ ){
        dp[1][i] = dp[1][i-1] + k;
        dp[i][1] = dp[i-1][1] + k;
    }
    for( int i = 2 ; i <= n ; i++ ){
    	for( int j = i ; j <= n ; j++ ){
    		dp[i][j] = dp[i-1][j] + dp[j-1][i] - dp[i-1][j-1];
    		dp[i][j] %= mod;
    		for( int l = i - 1 ; l >= max( 1, (i-k) ) ; l-- ){
                dp[i][j] += dp[l-1][j-1] + 1;
                dp[i][j] %= mod;
            }
            for( int l = j - 1 ; l >= max( 1, (j-k) ) ; l-- ){
                dp[i][j] += dp[i-1][l-1] + 1;
                dp[i][j] %= mod;
            }
            dp[j][i] = dp[i][j];
    	}
    }
    printf("%lld",dp[n][n]);
    return 0;
}