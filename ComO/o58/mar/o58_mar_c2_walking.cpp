#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e6 + 100;
const int M = 6e3 + 100;
int seg[4*N], n, k, ans = 1e9, va[M], chk[M], sz[M];
vector<int> g[M];

void update( int idx, int va, int l = 1, int r = 1e6, int now = 1 ) {
	if( l == r ) {
		if(va != 6e6+10) seg[now] = min( seg[now], va );
		else seg[now] = va;
		return ;
	}
	int mid = ( l + r ) >> 1;
	if(idx <= mid)update( idx, va, l, mid, now<<1 );
	else update( idx, va, mid+1, r, now<<1|1 );
	seg[now] = min( seg[now<<1], seg[now<<1|1] );
	return ;
}


int query( int ll, int rr, int l = 1, int r = 1e6, int now = 1 ) {
	if( l > rr || r < ll || l > r )return 1e9;
	if( l >= ll && r <= rr ) return seg[now];
	int mid = ( l + r ) >> 1;
	return min( query( ll, rr, l, mid, now<<1 ), query( ll, rr, mid + 1, r, now<<1|1 ) );
}

int getsz( int now, int p ) {
	sz[now] = 1;
	for( int i : g[now] ) if( i != p && !chk[i] ) {
		int z = getsz( i, now );
		sz[now] += z;
	}
	return sz[now];
}

int find_cen( int now, int p, int all, pii &ret ) {
	int mx = all - sz[now];
	for( int i : g[now] ) if( i != p && !chk[i] ) mx = max( mx, find_cen( i, now, all, ret ) );
	ret = min( ret, pii( mx, now ) );
	return sz[now];
}

void dfs( int now, int p, int cen, int sum, int use, bool fill ) {
	if( sum + va[cen] >= k ) {
		ans = min( ans, use ) ;
		if( fill ) update( k, use );
		return ;
	}
	if( !fill )ans = min( ans, query( k-sum-va[cen], 1e6 ) + use ); 
	else update( sum, use );
	for( int i : g[now] ) if( i != p && !chk[i] ) dfs( i, now, cen, sum + va[i], use + 1, fill );
	return ;
}

void clear( int now, int p, int sum  ) {
	update( sum, 6e6 + 10 );
	for( int i : g[now] ) if( i != p && !chk[i] ) clear( i, now, sum + va[i] );
	return ;
}
 
void solve( int u ) {
	getsz( u, u );
	pii ret( sz[u] + 1, -1 );
	find_cen( u, u, sz[u], ret);
	u = ret.y;
	for( int i : g[u] ) if( !chk[i] ) {
		dfs( i, u, u, va[i], 1, 0 );
		dfs( i, u, u, va[i], 1, 1 );
	}
	for( int i : g[u] ) if( !chk[i] ) clear(i, u, va[i] );
	chk[u] = true;
	for( int i : g[u] ) if( !chk[i] ) solve( i );
}
int main()
{
	fill(seg, seg + 4*N, 6e6+10 );
	scanf("%d %d",&n,&k);
	for( int i = 1 ; i <= n ; i++ ) scanf("%d",&va[i]);
	for( int i = 0, u, v ; i < n - 1 ; i++ ) {
		scanf("%d %d",&u,&v);
		u++, v++;
		g[u].emplace_back( v ), g[v].emplace_back( u );
	}
	solve( 1 );	
	printf("%d", ans != 1e9 ? ans : -1 );
	return 0;
}