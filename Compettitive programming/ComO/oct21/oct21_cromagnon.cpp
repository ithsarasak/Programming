#include <bits/stdc++.h>

using namespace std;
const int mod = 2009;
int n, k;
int op[25][25], num[110], mark[150][150][30], check[150][150];
void play( int l, int r )
{
	if( l == r ){
		mark[l][r][num[l]] = 1;
		return ;
	}
	if( check[l][r] != -1 )return ;
	check[l][r] = 1;
	for( int i = l ; i < r ; i++ ){
		play( l, i ), play( i + 1, r );
		for( int j = 0 ; j < k ; j++ ){
			for( int m = 0 ; m < k ; m++ ){
				mark[l][r][op[j][m]] += mark[l][i][j] * mark[i+1][r][m];
				mark[l][r][op[j][m]] %= mod;
			}
		}
	}
	return ;
}
int main()
{
	memset( check, -1, sizeof check );
	scanf("%d",&k);
	for( int i = 0 ; i < k ; i++ ){
		for( int j = 0 ; j < k ; j++ ){
			scanf("%d",&op[i][j]);
		}
	}
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&num[i]);
	}
	play( 1, n );
	for( int i = 0 ; i < k ; i++ ){
		printf("%d\n",mark[1][n][i]);
	}
	return 0;
}