#include <bits/stdc++.h>

using namespace std;

const int N = 2e4+100;
int t, a, b, c, d[1010];
int dp[1010][N];
int main()
{
	scanf("%d",&t);
	while( t-- ) {
		memset( dp, 127, sizeof dp );
		dp[0][0] = 0;
		scanf("%d %d %d",&a,&b,&c);
		for( int i = 1 ; i <= c ; i++ ) scanf("%d",&d[i]);
		int w = abs( a - b );
		for( int i = 1 ; i <= c ; i++ ) {
			for( int j = 0; j <= w ; j++ ) {
				if( j < d[i] ) dp[i][j] = dp[i-1][j];
				else dp[i][j] = min( dp[i-1][j], dp[i][j-d[i]] + 1 );
			}
		}
		if( dp[c][w] < 1e9 ) printf("%d\n",dp[c][w]);
		else printf("-1\n");
	}
	return 0;
}