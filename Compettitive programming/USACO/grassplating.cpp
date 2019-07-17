#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5 + 100;
int n, m, rot[N], dep[N], par[N], pos[N], spi[N];
long long seg[4*N], lz[4*N];
vector<int> g[N];

void push( int now, int l, int r ) {
	if( !lz[now] ) return ;
	seg[now] += lz[now] * ( long long )( r - l + 1 );
	if( l != r ) {
		lz[now<<1] += lz[now];
		lz[now<<1|1] += lz[now];
	}
	lz[now] = 0;
	return ;
}

void update( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
	push( now, l, r );
	if( l > rr || r < ll || l > r || ll > rr ) return ;
	if( l >= ll && r <= rr ) {
		seg[now] += ( long long )( r - l + 1 );
		if( l != r ) {
			lz[now<<1] += lz[now];
			lz[now<<1|1] += lz[now];
		}
		return ;
	}
	int mid = ( l + r ) >> 1;
	update( ll, rr, l, mid, now<<1 ), update( ll, rr, mid+1, r, now<<1|1 );
	seg[now] = seg[now<<1] + seg[now<<1|1];
	return ;
}

long long query( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
	push( now, l, r );
	if( l > rr || r < ll || l > r || ll > rr ) return 0;
	if( l >= ll && r <= rr ) return seg[now];
	int mid = ( l + r ) >> 1;
	return query( ll, rr, l, mid, now<<1 ) + query( ll, rr, mid+1, r, now<<1|1 );
}

int pre( int now, int p ) {
	dep[now] = dep[p] + 1, par[now] = p;
	int sz = 1;pii ret( 0, -1 );
	for( int i : g[now] ) if( i != p ) {
		int z = pre( i, now );
		sz += z;
		ret = max( ret, pii( z, i ) );
	}
	spi[now] = ret.y;
	return sz;
}

void hld() {
	for( int i = 1, idx = 0 ; i <= n ; i++ ) if( i != spi[par[i]] ){
		for( int j = i ; j != -1 ; j = spi[j] )
			rot[j] = i, pos[j] = ++idx;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 0, u, v ; i < n - 1 ; i ++ ) {
		scanf("%d %d",&u,&v);
		g[u].emplace_back( v ), g[v].emplace_back( u );
	}
	pre( 1, 1 ), hld();
	while( m-- ) {
		char op; int a, b;
		scanf(" %c %d %d",&op,&a,&b);
		if( op == 'P' ) {
			while( rot[a] != rot[b] ) {
				if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
				update( pos[rot[a]], pos[a] );
				a = par[rot[a]];
			}
			if( dep[a] > dep[b] ) swap( a, b );
			if( a != b ) update( pos[a] + 1, pos[b] );
		}
		else {
			long long ans = 0;
			while( rot[a] != rot[b] ) {
				if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
				ans += query( pos[rot[a]], pos[a] );
				a = par[rot[a]];
			}
			if( dep[a] > dep[b] )swap( a, b );
			if( a != b ) ans += query( pos[a]+1, pos[b] );
			printf("%lld\n",ans);
		}
	}
	return 0;
}