#include <bits/stdc++.h>

using namespace std; 

int dp[2][4][4][4][4], a[101000];
int n, ans;
string s;
int cal( int a, int b, int c )
{
	int ret = 0;
	if(a == 1 || b == 1 || c == 1) ret++;
	if(a == 2 || b == 2 || c == 2) ret++;
	if(a == 3 || b == 3 || c == 3) ret++;
	return ret;
}
int main()
{
	scanf("%d",&n);
	cin >> s;
	for( int i = 1 ; i <= n ; i++ ){
		if( s[i-1] == 'M' )a[i] = 1;
		else if( s[i-1] == 'F' )a[i] = 2;
		else a[i] = 3;
	}
	for( int i = 0 ; i < 2 ; i++ )for( int j = 0 ; j < 4 ; j++ )for( int k = 0 ; k < 4 ; k++ )for( int l = 0 ; l < 4 ; l++ )for( int m = 0 ; m < 4 ; m++ )dp[i][j][k][l][m] = -999999999;
	dp[1][0][a[1]][0][0] = dp[1][0][0][0][a[1]] = 1;
	for( int i = 2 ; i <= n ; i++ ){
		for( int j = 0 ; j < 4 ; j++ )for( int k = 0 ; k < 4 ; k++ )for( int l = 0 ; l < 4 ; l++ )for( int m = 0 ; m < 4 ; m++ ){
			dp[i%2][l][a[i]][j][k] = max( dp[(i+1)%2][m][l][j][k] + cal( m, l, a[i] ), dp[i%2][l][a[i]][j][k] );
		}
		for( int j = 0 ; j < 4 ; j++ )for( int k = 0 ; k < 4 ; k++ )for( int l = 0 ; l < 4 ; l++ )for( int m = 0 ; m < 4 ; m++ ){
			dp[i%2][j][k][l][a[i]] = max( dp[(i+1)%2][j][k][m][l] + cal( m, l, a[i] ), dp[i%2][j][k][l][a[i]] );
		}
	}
	for( int i = 0 ; i < 4 ; i++ )for( int j = 0 ; j < 4 ; j++ )
		for( int k = 0 ; k < 4 ; k++ )for( int l = 0 ; l < 4 ; l++ ){
			ans = max( ans, dp[n%2][i][j][k][l] );
		}
	printf("%d",ans);
	return 0;
}