#include <bits/stdc++.h>

using namespace std;
int n, m;
struct mm{
	int mat[310][310];
	mm operator*( const mm &b ){
		mm c;
		for( int i = 0 ; i < n ; i++ ){
			for( int j = 0 ; j < n ; j++ ){
				int sum = -1e9;
				for( int k = 0 ; k < n ; k++ )sum = max( sum, mat[i][k]+b.mat[k][j] );
				c.mat[i][j] = sum;
			}
		}
		return c;
	}
}mul[10], graph, t;
mm cal( int x )
{
	x--;
	mm tt = mul[0];
	for( int i = 9 ; i >= 0 ; i-- ){
		if( x & ( 1 << i ) ){
			tt = tt * mul[i];
		}
	}
	return tt;
}
int check( int x )
{
	t = cal( x );
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			if( t.mat[i][j] > 0 && i == j ){
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < m ; j++ ){
			if( i == j )t.mat[i][j] = 1;
		}
	}
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			if( i == j )graph.mat[i][j] = 0;
			else graph.mat[i][j] = -1e9;
		}
	}
	for( int i = 0 ; i < m ; i++ ){
		int a, b, c, d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		graph.mat[a-1][b-1] = c;
		graph.mat[b-1][a-1] = d;
	}
	mul[0] = graph;
	for( int i = 1 ; i <= 9 ; i++ )mul[i] = mul[i-1]*mul[i-1];
	int l = 1, r = n;
	if( !check( n ) ){
		printf("0");
		return 0;
	}
	while( l < r ){
		int mid = ( l + r ) / 2;
		if( check( mid ) ){
			r = mid;
		} 
		else l = mid + 1;
	}
	printf("%d",l);
	return 0;
}