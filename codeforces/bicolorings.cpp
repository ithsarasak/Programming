#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
long long dp[1100][2100][5], ans;
int n, k;
int dif( int a, int b )
{
	int cnt = __builtin_popcount( a ^ b );
	if( cnt == 0 )return 0;
	else if( cnt == 1 ){
		if( a == 0 || a == 3 )return 1;
		else return 0;
	}
	else{
		if( a == 0 || a == 3 )return 1;
		else return 2;
	}
}
int main()
{
	scanf("%d %d",&n,&k);
	dp[1][1][0] = dp[1][1][3] = 1;
	dp[1][2][1] = dp[1][2][2] = 1;
	for( int i = 2 ; i <= n ; i++ ){
		for( int j = 1 ; j <= k ; j++ ){
			for( int m = 0 ; m < 4 ; m++ ){
				for( int l = 0 ; l < 4 ; l++ ){	
					//printf("%d %d %d %d %d\n",i,j,m,l,dif( l, m ));
					if( j < dif( l, m ) ){
						continue;
					}
					//printf(" - %d \n",dp[i-1][j-dif( l, m )][l] );
					dp[i][j][m] += dp[i-1][j-dif( l, m )][l];
					dp[i][j][m] %= mod;
				}
			}
		}
	}
	/*for( int l = 1 ; l <= n ; l++ ){
		for( int i = 1 ; i <= k ; i++ ){
			for( int j = 0 ; j < 4 ; j++ ){
				printf("dp[%d][%d][%d] : %lld\n",l,i,j,dp[l][i][j]);
			}
		}
	}*/
	for( int i = 0 ; i < 4 ; i++ ){
		ans += dp[n][k][i];
		ans %= mod;
	}
	printf("%lld",ans);
	return 0;
}
