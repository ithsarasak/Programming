#include <bits/stdc++.h>

using namespace std;
int dp[2][5][5], mod = 2553, ans;
int n, word[1000100];
char wo[1000100];
void init()
{
	for( int i = 1 ; i <= 3 ; i++ )for( int j = 1 ; j <= 3 ; j++ )dp[1][i][j] = 1;
	return ;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",wo);
	for( int i = 0 ; i < n ; i++ ){
		if( wo[i] == 'P' )word[i] = 1;
		else if( wo[i] == 'R' )word[i] = 2;
		else word[i] = 3;
	}
	for( int i = 1 ; i < word[n-1] ; i++ )ans++;
	for( int i = 1 ; i < n ; i++ ){
		if( i == 1 )init();
		else{
			for( int j = 1 ; j <= 3 ; j++ ){
				for( int k = 1 ; k <= 3 ; k++ ){
					dp[i%2][j][k] = 0;
					if( j == k ){
						for( int l = 1 ; l <= 3 ; l++ ){
							if( l != k )dp[i%2][j][k] = ( dp[i%2][j][k] + dp[(i+1)%2][k][l] + mod ) % mod;
						}
					}
					else{
						for( int l = 1 ; l <= 3 ; l++ ){
							dp[i%2][j][k] = ( dp[i%2][j][k] + dp[(i+1)%2][k][l] + mod ) % mod; 
						}
					}
				}
			}
		}
		/*printf("%d\n",i);
		for( int j = 1 ; j <= 3 ; j++ ){
			for( int k = 1 ; k <= 3 ; k++ ){
				printf("%d ",dp[i%2][j][k]);
			}
			printf("\n");
		}*/
		for( int j = 1 ; j < word[n-i-1] ; j++ ){
			for( int k = 1 ; k <= 3 ; k++ ){
				if( ( n-i-1 >= 2 && j == word[n-i-2] && j == word[n-i-3] ) || ( n-i-1 >= 1 && j == k && j == word[n-i-2] ) )continue;
				ans = ( ans + dp[i%2][j][k] ) % mod;
			}
		}
	}
	printf("%d",(ans+1)%mod);
	return 0;
}	