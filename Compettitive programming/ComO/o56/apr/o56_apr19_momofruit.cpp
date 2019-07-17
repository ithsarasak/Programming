#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+100;

vector<long long> coord;
long long sum[N], va[N], mx;
int dp[N], seg[4*N], n;
int get( int x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + 1; }

void update( int idx, int va, int l = 1, int r = coord.size(), int now = 1 ) {
	if( l > idx || r < idx || l > r ) return ;
	if( l == r ) return void( seg[now] = max( seg[now], va ) );
	int mid = ( l + r ) >> 1;
	update( idx, va, l, mid, now<<1 ), update( idx, va, mid+1, r, now<<1|1 );
	seg[now] = max( seg[now<<1], seg[now<<1|1] );
	return ;
}

int query( int ll, int rr, int l = 1, int r = coord.size(), int now = 1 ) {
	if( l > rr || r < ll || l > r ) return -1e9;
	if( l >= ll && r <= rr ) return seg[now];
	int mid = ( l + r ) >> 1;
	return max( query( ll, rr, l, mid, now<<1 ), query( ll, rr, mid+1, r, now<<1|1 ) );
}

int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%lld",&va[i]);
		sum[i] = sum[i-1] + va[i];
		coord.emplace_back( sum[i] );
	}
	sort( coord.begin(), coord.end() );
	coord.resize( unique( coord.begin(), coord.end() ) - coord.begin() );
	update( get( va[1] ), va[1] > 0 ? 1 : 0 );
	// printf("s%d\n",seg[1]);
	mx = max( mx, va[1] );
	for( int i = 2 ; i <= n ; i++ ) {
		int x = get( sum[i-1]+va[i] ) - 1, ret;
		if( sum[i] <= 0 ) ret = -1;
		else ret = query( 1, x );
		dp[i] = ret + 1;
		// printf("%d %d %lld\n",x,ret,sum[i]);
		update( get( sum[i] ), dp[i] );
		mx = max( mx, sum[i] );
	} 
	// printf("\n");
	// for( int i = 1 ; i <= n ; i++ ) printf("%d ",dp[i]);
	// printf("\n");
	printf("%d",dp[n]);
	return 0;
}