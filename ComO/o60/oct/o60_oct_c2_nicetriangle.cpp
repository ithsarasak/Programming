#include <bits/stdc++.h>

using namespace std;
int x, y, z;
long long dp[710][710], ans;
const int mod = 29947;
int main()
{
	scanf("%d %d %d",&x,&y,&z);
	x--, y--, z--;
	for( int i = 0 ; i <= 700 ; i++ ){
		for( int j = 0 ; j <= 700 ; j++ ){
			if( i == 0 || j == 0 )dp[i][j] = 1;
			else{
				dp[i][j] = ( dp[i-1][j] + dp[i][j-1] ) % mod;
			}
		}
	}
	for( int i = 1 ; i <= x ; i++ ){
		for( int j = 1 ; j <= y ; j++ ){
			ans += dp[i-1][j-1] * dp[x-i+y-j][z];
			ans %= mod;
		}
	}
	ans += dp[x+y][z];
	ans %= mod;
	printf("%lld",ans);
	return 0;
}