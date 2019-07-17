#include <bits/stdc++.h>

using namespace std;
long long mod = 1e9+7;
struct mm{
	long long mat[4][4];
	mm operator*( const mm &b ){
		mm c;
		for( int i = 0 ; i < 4 ; i++ ){
			for( int j = 0 ; j < 4 ; j++ ){
				long long a = 0;
				for( int k = 0 ; k < 4 ; k++ )a = ( a + mat[i][k]*b.mat[k][j] ) % mod ;
				c.mat[i][j] = a % mod;
			}
		}
		return c;
	}
};
mm st, mul;
mm mu( int now )
{ 
	if( now == 1 )return mul;
	mm temp = mu( now / 2 );
	if( now % 2 )return mul * temp* temp;
	else return temp * temp;
}
int n;
int main()
{
	for( int i = 0 ; i < 4 ; i++ ){
		for( int j = 0 ; j < 4 ; j++ ){
			if( i == j )st.mat[i][j] = 1;
		}
	}
	for( int i = 0 ; i < 4 ; i++ ){
		for( int j = 0 ; j < 4 ; j++ ){
			if( i != j )mul.mat[i][j] = 1;
			else mul.mat[i][j] = 0;
		}
	}
	scanf("%d",&n);
	st = st * mu( n );
	printf("%lld",st.mat[0][0]);
	return 0;
}