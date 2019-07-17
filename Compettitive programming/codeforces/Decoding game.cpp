#include <bits/stdc++.h>

using namespace std;
long long mod = 1e9+7;
int m, k;
long long n;
struct mm{
	long long mat[60][60];
	mm operator*( const mm &b ){
		mm c;
		for( int i = 0 ; i < m ; i++ ){
			for( int j = 0 ; j < m ; j++ ){
				long long a = 0;
				for( int k = 0 ; k < m ; k++ )a = ( a + mat[i][k]*b.mat[k][j] ) % mod ;
				c.mat[i][j] = a;
			}
		}
		return c;
	}
};
mm st, mul, help[55];
int main()
{
	scanf("%lld %d %d",&n,&m,&k);
	for( int i = 0 ; i < m ; i++ )for( int j = 0 ;  j < m ; j++ )mul.mat[i][j] = 1;
	for( int i = 0 ; i < k ; i++ ){
		char wo[3];
		int no[3];
		scanf("%s",wo);
		for( int j = 0 ; j < 2 ; j++ ){
			if( wo[j] < 'a' )no[j] = 26 + wo[j] - 'A';
			else no[j] = wo[j] - 'a';
		}
		mul.mat[no[0]][no[1]] = 0;
	}
	if( n == 1 ){
		printf("%d",m);
		return 0;
	}
	for( int i = 0 ; i < m ; i++ ){
		for( int j = 0 ; j < m ; j++ ){
			if( i == j )st.mat[i][j] = 1;
		}
	}
	n--;
	for( int i = 0 ; i < 52 ; i++ ){
		if( i == 0 )help[0] = mul;
		else help[i] = help[i-1] * help[i-1];
		if( n & ( long long )( 1LL << i ) ){
			st = st * help[i];
		}
	}
	long long ans = 0;
	for( int i = 0 ; i < m ; i++ ){
		for( int j = 0 ; j < m ; j++ ){
			ans = ( ans + st.mat[i][j] ) % mod;
		}
	}
	printf("%lld",ans);
	return 0;
}