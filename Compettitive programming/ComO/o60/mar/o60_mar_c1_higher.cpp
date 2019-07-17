#include <bits/stdc++.h>

using namespace std;

int n, k, seg[4000100];

void up( int idx, int va, int l = 1, int r = n, int now = 1 ) {
	if( l > idx || r < idx || l > r ) return ;
	if( l == r ) {
		seg[now] = va;
		return ;
	}
	int mid = ( l + r ) >> 1;
	up( idx, va, l, mid, now*2 ), up( idx, va, mid + 1, r, now*2 + 1 );
	seg[now] = max( seg[now*2], seg[now*2+1] );
	return ;
}

int query( int ll, int rr, int l = 1, int r = n , int now = 1 ) {
	if( l > rr || r < ll || l > r ) return -1e9;
	if( l >= ll && r <= rr )return seg[now];
	int mid = ( l + r ) / 2;
	return max( query( ll, rr, l, mid, now*2 ), query( ll, rr, mid+1, r, now*2+1 ) );
}

int check( int x, int h, int d ) {
	//printf("%d %d %d %d\n",x,h,d,query( max( 1, x - d ), min( n, x + d ) ));
	if( h == query( max( 1, x - d ), min( n, x + d ) ) )return 1;
	else return 0;
}   

int main() 
{
	scanf("%d %d",&n,&k);
	for( int i = 1, x, h ; i <= k ; i++ ){
		scanf("%d %d",&x,&h);
		x++;
		up( x, h );
		int l = 0, r = n;
		while( l < r ){
			int m = ( l + r + 1 ) >> 1 ;
			if( check( x, h, m ) )l = m;
			else r = m - 1;
		}
		printf("%d\n",l);
	}
	return 0;
}
