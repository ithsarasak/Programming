#include <bits/stdc++.h>
#define pii pair<int, int>
#define h first
#define pos second
using namespace std;

const int N = 1e5+100;
int n, w, mx = -1, seg[4*N], h[N];

void build( int l = 1, int r = n, int now = 1 ) {
	if( l == r ){
		seg[now] = h[l];
		return ;
	}
	int mid = ( l + r ) >> 1;
	build( l, mid, now<<1 ), build( mid+1, r, now<<1|1 );
	seg[now] = min( seg[now<<1], seg[now<<1|1] );
	return ;
}

int query( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
	if( l > rr || r < ll || l > r ) return 1e9;
	if( l >= ll && r <= rr ) return seg[now];
	int mid = ( l + r ) >> 1;
	return min( query( ll, rr, l, mid, now<<1 ), query( ll, rr, mid+1, r, now<<1|1 ) );
}

int main()
{
	scanf("%d %d",&n,&w);
	if( w == -10 ) return 0;
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&h[i]);
	}
	build();
	for( int i = w + 1 ; i <= n ; i++ ) {
		int mi = query( i - w, i );
		if( h[i-w-1] < mi && h[i+1] < mi ) mx = max( mx, mi );
	}
	printf("%d",mx);
	return 0;
}