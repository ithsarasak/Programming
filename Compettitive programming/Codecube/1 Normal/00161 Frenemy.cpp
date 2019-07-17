#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n;
char ma[1010][1010];
int dp1[1010][1010], dp2[1010][1010], dp3[1010][1010], dp4[1010][1010];
long long ans;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%s",&ma[i][1]);
	}
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			if( i == 1 && j == 1 )dp1[i][j] = 1;
			else if( ma[i][j] == '0' )dp1[i][j] = 0;
			else dp1[i][j] = dp1[i-1][j] + dp1[i][j-1];
			dp1[i][j] %= mod;
		}
	}
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = n ; j >= 1 ; j-- ){
			if( i == 1 && j == n )dp2[i][j] = 1;
			else if( ma[i][j] == '0' )dp2[i][j] = 0;
			else dp2[i][j] = dp2[i-1][j] + dp2[i][j+1];
			dp2[i][j] %= mod;
		}
	}
	for( int i = n ; i >= 1 ; i-- ){
		for( int j = 1 ; j <= n ; j++ ){
			if( i == n && j == 1 )dp3[i][j] = 1;
			else if( ma[i][j] == '0' )dp3[i][j] = 0;
			else dp3[i][j] = dp3[i+1][j] + dp3[i][j-1];
			dp3[i][j] %= mod;
		}
	}
	for( int i = n ; i >= 1 ; i-- ){
		for( int j = n ; j >= 1 ; j-- ){
			if( i == n && j == n )dp4[i][j] = 1;
			else if( ma[i][j] == '0' )dp4[i][j] = 0;
			else dp4[i][j] = dp4[i+1][j] + dp4[i][j+1];
			dp4[i][j] %= mod;
		}
	}
	/*for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			printf("%d ",dp1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			printf("%d ",dp2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			printf("%d ",dp3[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			printf("%d ",dp4[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	for( int i = 2 ; i < n ; i++ ){
		for( int j = 2 ; j < n; j++ ){
			if( ma[i][j] != '0' ){
				long long tt = ( long long )dp1[i-1][j]*( long long )dp2[i][j+1];
				tt %= mod;
				tt *= ( long long )dp3[i][j-1];
				tt %= mod;
				tt *= ( long long )dp4[i+1][j];
				tt %= mod;
				ans += tt;
				ans %= mod;
				tt = ( long long )dp1[i][j-1]*( long long )dp2[i-1][j];
				tt %= mod;
				tt *= ( long long )dp3[i+1][j];
				tt %= mod;
				tt *= ( long long )dp4[i][j+1];
				tt %= mod;
				ans += tt;
				ans %= mod;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
