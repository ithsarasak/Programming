#include <bits/stdc++.h>

using namespace std;
int t, n, mx, pos;
int dp[4][100100], tower[100100];
int main()
{
	scanf("%d",&t);
	while( t-- ){
		mx = 0, pos = 0;
		memset( dp, 0, sizeof dp );
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ ){
			scanf("%d",&tower[i]);
		}
		tower[0] = 2000000;
		tower[n+1] = 2000000;
		for( int i = 1 ; i <= n ; i++ ){
			if( tower[i] - tower[i-1] >= 1 && tower[i] - tower[i-1] <= 2 ){
				dp[0][i] = dp[0][i-1] + 1;
			}
			else{
				dp[0][i] = 1;
			} 
			if( tower[i-1] - tower[i] >= 1 && tower[i-1] - tower[i] <= 2 ){
				dp[1][i] = dp[1][i-1] + 1;
			}
			else{
				dp[1][i] = 1;
			}
		}
		for( int i = n ; i >= 1 ; i-- ){
			if( tower[i+1] - tower[i] >= 1 && tower[i+1] - tower[i] <= 2 ){
				dp[2][i] = dp[2][i+1] + 1;
			}
			else{
				dp[2][i] = 1;
			}
			if( tower[i] - tower[i+1] >= 1 && tower[i] - tower[i+1] <= 2 ){
				dp[3][i] = dp[3][i+1] + 1;
			}
			else{
				dp[3][i] = 1;
			}
		}
		for( int i = 1 ; i <= n ; i++ ){
			if( i == 1 ){
				if( mx < max( dp[2][i+1] , dp[3][i+1] ) + 1 ){
					mx = max( dp[2][i+1] , dp[3][i+1] ) + 1;
					pos = i;
				}
			}
			else if( i == n ){
				if( mx < max( dp[1][i-1], dp[0][i-1] ) + 1 ){
					mx = max( dp[1][i-1], dp[0][i-1] ) + 1;
					pos = i;
				}
			}
			else{
				if( tower[i+1] - tower[i-1] >= 2 && tower[i+1] - tower[i-1] <= 4 ){
					if( mx < dp[0][i-1] + dp[2][i+1] + 1 ){
						mx = dp[0][i-1] + dp[2][i+1] + 1;
						pos = i;
					}
				}
				if( tower[i-1] - tower[i+1] >= 2 && tower[i-1] - tower[i+1] <= 4 ){
					if( mx < dp[1][i-1] + dp[3][i+1] + 1 ){
						mx = dp[1][i-1] + dp[3][i+1] + 1;
						pos = i;
					}
				}
				if( mx < max( dp[2][i+1] , dp[3][i+1] ) + 1 ){
					mx = max( dp[2][i+1] , dp[3][i+1] ) + 1;
					pos = i;
				}
				if( mx < max( dp[1][i-1], dp[0][i-1] ) + 1 ){
					mx = max( dp[1][i-1], dp[0][i-1] ) + 1;
					pos = i;
				}
			}
		}
		printf("%d %d\n",mx, pos-1);
	}
	return 0;
}