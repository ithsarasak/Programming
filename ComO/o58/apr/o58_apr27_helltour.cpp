#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 3;
const long long mod = 1e6 + 3;

struct mm{
	long long mat[N][N];
	mm() { }
	friend mm operator*(const mm &a, const mm &b) {
		mm c;
		memset( c.mat, 0, sizeof c.mat );
		for( int k = 1 ; k < N ; k++ ) for( int i = 1 ; i < N ; i++ ) for( int j = 1 ; j < N ; j++ ) {
			c.mat[i][j] += ( a.mat[i][k] * b.mat[k][j] ) % mod;
			c.mat[i][j] %= mod;
		}
		return c;
	}
}mul, start;
int r, c, ma[N][N];
long long k, dp[N][N];

void cal( int row, int column ) {
	memset( dp, 0, sizeof dp );
	dp[row][column] = 1;
	for( int i = 2 ; i <= c ; i++ ) for( int j = 1 ; j <= r ; j++ ) 
		dp[j][i] = ( ma[j][i] ) ? ( dp[j-1][i-1] + dp[j][i-1] + dp[j+1][i-1] ) % mod : 0;

	for( int i = 1 ; i <= r ; i++ ) mul.mat[row][i] = dp[i][c];
	// for( int i = 1 ; i <= r ; i++ ) {
	// 	for( int j = 1 ; j <= c ; j++ ) {
	// 		printf("%lld ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return ;
}

void power( long long k ) {
	for( ; k ; k >>= 1 ) {
		if( k & 1 ) start = start * mul;
		mul = mul * mul;
	}
}
int main()
{
	scanf("%d %d %lld",&r,&c,&k);
	for( int i = 1 ; i <= r ; i++ ) for( int j = 1 ; j <= c ; j++ ) scanf("%d",&ma[i][j]);
	for( int i = 1 ; i <= r ; i++ ) if( ma[i][1] ) cal( i, 1 );
	// for( int i = 1 ; i <= r ; i++ ) {
	// 	for( int j = 1 ; j <= r ; j++ ) printf("%lld ",mul.mat[i][j] );
	// 		printf("\n");
	// }
	for( int i = 1 ; i <= r ; i++ ) for( int j = i ; j <= r ; j++ ) start.mat[i][j] = ( i == j ) ? 1 : 0;
	power( k );
	for( int i = 1 ; i <= r ; i++ ) {
		long long sum = 0;
		// cout << sum << endl;
		for( int j = 1 ; j <= r ; j++ ) {
			sum = ( sum + start.mat[i][j] ) % mod;
		}
		printf("%lld\n",sum);
	}
	return 0;
}