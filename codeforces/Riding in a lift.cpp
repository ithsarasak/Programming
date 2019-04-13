#include <bits/stdc++.h>

using namespace std;
int n, a, b, k;
long long dp[2][5010];
int pos[5010];
long long mod = 1e9+7;
int main()
{
	scanf("%d %d %d %d",&n,&a,&b,&k);
	dp[0][a] = 1;
	for( int i = 1 ; i < b ; i++ )dp[0][i] += dp[0][i-1];
	for( int i = n ; i > b ; i-- )dp[0][i] += dp[0][i+1];
	for( int i = 1 ; i < b ; i++ ){
		int p = ( i + b - 1 ) / 2;
		if( p == i )p--;
		pos[i] = p;
	}
	for( int i = n ; i > b ; i-- ){
		int p = ( i + b + 2 ) / 2;
		if( p == i )p++;
		pos[i] = p;
	}
	for( int i = 1 ; i <= k ; i++ ){
		for( int j = 1 ; j < b ; j++ ){
			dp[i%2][j] = dp[(i+1)%2][pos[j]];
			if( pos[j] > j )dp[i%2][j] -= ( dp[(i+1)%2][j] - dp[(i+1)%2][j-1] );
			dp[i%2][j] = ( dp[i%2][j] + mod ) % mod;
			dp[i%2][j] = ( dp[i%2][j-1] + dp[i%2][j] ) % mod;
		}
		for( int j = n ; j > b ; j-- ){
			dp[i%2][j] = dp[(i+1)%2][pos[j]];
			if( pos[j] < j )dp[i%2][j] -= ( dp[(i+1)%2][j] - dp[(i+1)%2][j+1] );
			dp[i%2][j] = ( dp[i%2][j] + mod ) % mod;
			dp[i%2][j] = ( dp[i%2][j+1] + dp[i%2][j] ) % mod;
		}
	}
	printf("%lld",(dp[k%2][b-1]+dp[k%2][b+1])%mod );
	return 0;
}