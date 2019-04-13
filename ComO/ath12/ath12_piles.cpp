#include <bits/stdc++.h>

using namespace std;
const long long mod = 9871;
long long t, n, dp[110][110], k, pre[110][110], fac[110];

long long play( long long n, long long m )
{
	if( n < k*m )return dp[n][m] = 0;
	if( m == 1 )return dp[n][m] = 1;
	if( dp[n][m] != -1 )return dp[n][m];
	dp[n][m] = 0;
	for( long long i = k ; i <= n ; i++ ){
		dp[n][m] += pre[n][i] * play( n-i , m-1 );
		dp[n][m] %= mod;
	}
	return dp[n][m];
}
long long compute( long long up, long long down )
{
	for( long long i = 0 ; i <= mod ; i++ ){
		if( (down*i)%mod  == 1 ){
			return ( i * up ) % mod;
		}
	}
}
int main()
{
	pre[0][0] = 1, fac[0] = 1;
	for( long long i = 1 ; i <= 100 ; i ++ ){
		fac[i] = fac[i-1] * i;
		fac[i] %= mod;
		for( long long j = 0 ; j <= i ; j ++ ){
			if( j == 0 || j == i )pre[i][j] = 1;
			else{
				pre[i][j] = pre[i-1][j-1] + pre[i-1][j];
				pre[i][j] %= mod;
			}
		}
	}
	scanf("%lld",&t);
	while( t-- ){
		memset( dp, -1, sizeof dp );
		scanf("%lld %lld",&n,&k);
		long long ans = 0;
		for( long long i = 1 ; i*k <= n ; i++ ){
			ans += compute( play( n, ( long long )i ), fac[i] );
			ans %= mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}