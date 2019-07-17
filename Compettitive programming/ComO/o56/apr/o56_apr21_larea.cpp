#include <bits/stdc++.h>

using namespace std;

const int N = 5e2;
int dp[N][N], dp2[N][N], sum[N][N], n, m, ans;

int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) scanf("%d",&sum[i][j]);
	for( int i = 2 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) sum[i][j] += sum[i-1][j];
	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = 1 ; j <= i ; j++ ) {
			int mx = 0;
			for( int k = 1 ; k <= m ; k++ ) {
				mx += sum[i][k] - sum[j-1][k];
				dp[i][k] = max( dp[i][k], mx );
				ans = max( ans, mx + dp[j-1][k] );
				if( mx < 0 ) mx = 0;
			}
			mx = 0;
			for( int k = m ; k >= 1 ; k-- ) {
				mx += sum[i][k] - sum[j-1][k];
				dp2[i][k] = max( dp2[i][k], mx );
				ans = max( ans, mx + dp2[j-1][k] );
				if( mx < 0 ) mx = 0;
			}
		}
	}
	printf("%d",ans);
	return 0;
}