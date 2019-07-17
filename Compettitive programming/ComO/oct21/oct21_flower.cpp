#include <bits/stdc++.h>

using namespace std;
int a[110], b[110], c[110];
int m, n, dp[110][110][110], ans;
int main()
{
	scanf("%d %d",&m,&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	}
	memset( dp, -1, sizeof dp );
	dp[0][0][0] = 0; 
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = m-a[i] ; j >= 0 ; j-- ){
			for( int k = 0 ; k <= n ; k++ ){
				for( int l = 0 ; l <= n ; l++ ){
					if( c[i] && l >= 1 ){
						if( dp[j][k][l-1] != -1 ){
							dp[j+a[i]][k][l] = max( dp[j+a[i]][k][l], dp[j][k][l-1] + b[i] );
						}
					}
					else if( !c[i] && k >= 1 ){
						if( dp[j][k-1][l] != -1 ){
							dp[j+a[i]][k][l] = max( dp[j+a[i]][k][l], dp[j][k-1][l] + b[i] );
						}
					}
				}
			}
		}
	}
	for( int i = 0 ; i <= m ; i++ )for( int j = 0 ; j <= n ; j++ )for( int k = 0 ; k <= n ; k++ )if( min( j, k ) * 2 + 2 >= max( j, k ) )ans = max( ans, dp[i][j][k] );
	printf("%d",ans);
	return 0;
}
