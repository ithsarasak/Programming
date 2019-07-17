#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+100;
int n, rot[N], par[N], sz[N], dep[N], spi[N], pos[N], seg[4*N], va[N], q, k, m, a1, a2;
vector<int> g[N];

void update( int idx, int va, int l = 1, int r = n, int now = 1 ) {
	if( l > idx || r < idx || l > r ) return ;
	if( l == r ) {
		seg[now] = va;
		return ;
	}
	int mid = ( l + r ) >> 1;
	update( idx, va, l, mid, now<<1 ), update( idx, va, mid + 1, r, now<<1|1 );
	seg[now]  = min( seg[now<<1], seg[now<<1|1] );
	return ;
}

int query( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
	if( l > rr || r < ll || l > r ) return 1e9;
	if( l >= ll && r <= rr ) return seg[now];
	int mid = ( l + r ) >> 1;
	return min( query( ll, rr, l, mid, now<<1 ), query( ll, rr, mid+1, r, now<<1|1 ) );
}

int pre( int now, int p ) {
	sz[now] = 1; pii ret( 0, -1 );
	par[now] = p, dep[now] = dep[p] + 1;
	for( int i : g[now] ) if( i != p ) {
		int z = pre( i, now );
		sz[now] += z;
		ret = max( ret, pii( z, i ) );
	}
	spi[now] = ret.y;
	return sz[now];
}

void hld() {
	for( int i = 1, idx = 0 ; i <= n ; i++ ) if( i != spi[par[i]] )
		for( int j = i ; j != -1 ; j = spi[j] )
			rot[j] = i, pos[j] = ++idx;
	for( int i = 1 ; i <= n ; i++ ) update( pos[i], va[i] );
	return ;
}

int query_hld( int a, int b ) {
	if( a == b ) return 0;
	int ret = 1e9;
	while( rot[a] != rot[b] ) {
		if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
		ret = min( ret, query( pos[rot[a]], pos[a] ) );
		a = par[rot[a]];
		// printf("%d %d\n",a,b);
	}
	if( dep[a] > dep[b] ) swap( a, b ); 
	if( a != b ) ret = min( ret, query( pos[a] + 1, pos[b] ) );
	return ret;
}

int main()
{
	scanf("%d",&n);
	for( int i = 2, p; i <= n ; i++ ) {
		scanf("%d %d",&p,&va[i]);
		p++;
		g[i].emplace_back( p ), g[p].emplace_back( i );
	}
	pre( 1, 1 ), hld();
	scanf("%d %d %d %d %d",&q,&k,&m,&a1,&a2);
	for( int i = 0 ; i < q ; i++ ) {
		a1++, a2++;
		int x = query_hld( a1, a2 );
		printf("%d\n",x); 
		a2--;
		a1 = a2, a2 = ( ( ( a2*k+x ) % m ) % n );
	} 
	return 0;
}