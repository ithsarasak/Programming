#include <bits/stdc++.h>

using namespace std;
long long n, m, dp[1100][1100][5], ma[1100][1100];
int main()
{
	scanf("%lld %lld",&n,&m);
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= m ; j++ ){
			scanf("%lld",&ma[i][j]);
		}
	}
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= m ; j++ ){
			dp[i][j][0] = max( dp[i-1][j][1], max( dp[i-1][j][2], max( dp[i][j-1][1], max( dp[i][j-1][2], max( dp[i-1][j][0], dp[i][j-1][0] )))));
			dp[i][j][1] = ma[i][j] + max( dp[i-1][j][0], dp[i][j-1][0] );
			dp[i][j][2] = ma[i][j] + max( dp[i-1][j][1], dp[i][j-1][1] );
		}
	}
	printf("%lld",max( dp[n][m][0], max( dp[n][m][1], dp[n][m][2] ) ) );
	return 0;	
}