#include <bits/stdc++.h>

using namespace std;
int q, a, b;
const int mod = 2009;
long long dp[60][60];
int main()
{
	dp[0][0] = 1, dp[1][0] = 1, dp[2][0] = 1, dp[2][1] = 1;
	for( int i = 3 ; i <= 50 ; i++ ){
		for( int j = 0 ; j < i ; j++ ){
			if( j == 0 || j == i-1 ){
				dp[i][j] = 1;
				continue;
			}
			for( int k = 0 ; k < i ; k++ ){
				int tim;
				if( k == i - 1 )tim = j;
				else tim = j - 1;
				for( int l = 0 ; l <= tim ; l++ ){
					dp[i][j] += dp[k][l] * dp[i-1-k][tim-l];
					dp[i][j] %= mod;
				}
			}
		}
	}
	scanf("%d",&q);
	while( q-- ){
		scanf("%d %d",&a,&b);
		printf("%lld\n",dp[a][b]);
	}
	return 0;
}