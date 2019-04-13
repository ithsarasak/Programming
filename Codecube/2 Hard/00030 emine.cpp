#include <bits/stdc++.h>

using namespace std;
long long dp[2][510][60];
long long n, k, ans;
int main()
{
	scanf("%lld %lld",&n,&k);
	for( long long i = 1 ; i <= n ; i++ ){
		for( long long j = 1 ; j <= n ; j++ ){
			long long ma;
			scanf("%lld",&ma);
			long long m = 0;
			for( long long l = 1 ; l <= k ; l++ ){
				dp[i%2][j][l] = max( dp[(i+1)%2][j][l-1], dp[i%2][j-1][l-1] ) + ma;
				m = max( m, max( dp[(i+1)%2][j][l-1] , dp[i%2][j-1][l-1] ) );
			}
			dp[i%2][j][0] = max( m, max( dp[(i+1)%2][j][k], dp[i%2][j-1][k] ) );
		}
	}
	for( long long j = 1 ; j <= n ; j++ )for( long long i = 0 ; i <= k ; i++ )ans = max( ans, dp[n%2][j][i] );
	printf("%lld",ans);
	return 0;
}