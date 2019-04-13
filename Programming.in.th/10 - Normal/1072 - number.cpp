#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100;
int num[N], n, q, shi, rev;

int tran( int pos ) {
	if( !rev ) return ( pos - shi + n ) % n;
	else return ( n - 1 - pos + shi ) % n;
}

int main()
{
	scanf("%d %d",&n,&q);
	for( int i = 0 ; i < n ; i++ ) scanf("%d",&num[i]);
	for( int i = 0, x, y ; i < q ; i++ ) {
		char c;
		scanf(" %c %d",&c,&x);
		x--;
		if( c == 'a' ) {
			scanf("%d",&y);
			y--;
			int a = tran( x ), b = tran( y );
			swap( num[a], num[b] );
		}
		else if( c == 'b' ) {
			scanf("%d",&y);
			int a = tran( x );
			num[a] = y;
		}
		else if( c == 'c' ) {
			x++;
			shi = ( n - shi + x ) % n;
			rev ^= 1;
		}
		else {
			printf("%d\n",num[tran( x )]);
		}
	}
	return 0;
}