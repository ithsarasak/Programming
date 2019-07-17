#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
struct mm{
	long long mat[5][5];
	mm() { } 
	friend mm operator*( const mm &a, const mm &b ) {
		mm c;
		memset( c.mat, 0, sizeof c.mat );
		for( int k = 0 ; k < 4 ; k++ ) for( int i = 0 ; i < 4 ; i++ ) for( int j = 0 ; j < 4 ; j++ ) {
			c.mat[i][j] = ( c.mat[i][j] + ( a.mat[i][k] * b.mat[k][j] ) ) % mod;
		}
		return c;
	}
}mul, st;
long long sum;
int n;
void power( int times ) {
	for( ; times ; times >>= 1 ) {
		if( times & 1 ) st = mul * st;
		mul = mul * mul;
	}
	return ;
}
int main()
{
	st.mat[0][0] = 1, st.mat[1][0] = 1, st.mat[2][0] = 1;
	for( int i = 0 ; i < 4 ; i++ ) {
		for( int j = 0 ; j < 4 ; j++ ) {
			if( i == 0 && j != 2 ) mul.mat[i][j] = 1;
			else if( i == 1 && j != 3 ) mul.mat[i][j] = 1;
			else if( i == 2 && j != 0 ) mul.mat[i][j] = 1;
			else if( i == 3 && j > 1 ) mul.mat[i][j] = 1;
		}
	}	
	scanf("%d",&n);
	power( n );
	for( int i = 0 ; i < 3 ; i++ ) sum = ( sum + st.mat[i][0] ) % mod;
	printf("%lld",sum);
	return 0;
}