#include <bits/stdc++.h>

using namespace std;
int n, x, dp[110][110][110];
int play( int l, int r )
{
	if( l == r )return dp[l][r][l] = 1;
	for( int i = l ; i < r ; i++ ){
		play( l, i ), play( i + 1, r );
		for( int j = 0 ; j <= 2)
	}
}
int main()
{
	scanf("%d %d",&n,&x);
	play( 1, n );
}