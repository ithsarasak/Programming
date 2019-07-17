#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 100, mod = 5e3;
int n;
int fw[N][N];
void up( int x, int y ) {
	for( int i = x ; i < N ; i += ( i & -i ) ){
		for( int j = y ; j < N ;  j += ( j & -j ) ){
			fw[i][j] += 1;
		}
	}
	return ;
}

int query( int x, int y ) {
	int sum = 0, sum2 = 0;
	for( int i = x ; i > 0 ; i -= ( i & -i ) ){
		for( int j = N - 1 ; j > 0 ; j -= ( j & -j ) ) {
			sum += fw[i][j];
		}
	}
	for( int i = x ; i > 0 ; i -= ( i & -i ) ){
		for( int j = y - 1 ; j > 0 ; j -= ( j & -j ) ){
			sum2 += fw[i][j];
		}
	}
	return sum - sum2;
}

int main()
{
	scanf("%d",&n);
	for( int i = 0, p, h ; i < n ; i++ ){
		scanf("%d %d",&p,&h);
		printf("%d\n",query( p - h + mod, p + h ) ); 
		up( p - h + mod , p + h );
	}
	return 0;
}