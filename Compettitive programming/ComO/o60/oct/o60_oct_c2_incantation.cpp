#include <bits/stdc++.h>

using namespace std;

const int N = 150;
struct mm{
	long long mat[N][N];
	mm() { }
	friend mm operator*( const mm &a, const mm &b ) {
		mm c;
		memset( c.mat, 0, sizeof c.mat );
		for( int k = 0 ; k < 100 ; k++ ) for( int i = 0 ; i < 100 ; i++ ) for( int j = 0 ; j < 100 ; j++ ) {
			if( a.mat[i][k] && b.mat[k][j] ) c.mat[i][j] = max( c.mat[i][j], a.mat[i][k] + b.mat[k][j] );
		}
		return c;
	}
}mul, st;
int n, k;
long long mx;
mm power( int po ) {
	if( po == 1 ) return mul;
	mm c = power( po / 2 );
	if( po % 2 ) return mul * c * c;
	else return c * c;
}
int main()
{
	scanf("%d %d",&n,&k);
	if( k == 1 ) {
		long long a, b;
		scanf("%lld %lld",&a,&b);
		printf("%lld",n*max( a, b ));
		return 0;
	}
	for( int i = 0 ; i < 1<<k ; i++ ) {
		scanf("%lld",&mul.mat[i/2][i%(1<<(k-1))]);
	}
	st = power( n-k+1 );
	// for( int i = 0 ; i < 1<<(k-1) ; i++ ) {
	// 	for( int j = 0 ; j < 1<<(k-1) ; j++ ) {
	// 		printf("%lld ",st.mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for( int i = 0 ; i < 100 ; i++ ) for( int j = 0 ; j < 100 ; j++ ) mx = max( mx, st.mat[i][j] );
	printf("%lld",mx);
	return 0;
}