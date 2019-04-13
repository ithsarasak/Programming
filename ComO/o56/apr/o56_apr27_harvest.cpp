#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first 
#define y second
using namespace std;

const int N = 1e5;
const long long mod = 1e9+9;
int n, par[N], rot[N], pos[N], q, e, dep[N], spi[N];
long long seg[4*N], lz[4*N];
vector<int> g[N];

void push( int now, int l, int r ) {
	if( lz[now] != 1 ) {
		// printf("%d %lld %d %d\n",now,lz[now],l,r);
		seg[now] = ( seg[now] * lz[now] ) % mod;
		if( l != r ){
			lz[now<<1] = ( lz[now<<1] * lz[now] ) % mod;
			lz[now<<1|1] = ( lz[now<<1|1] * lz[now] ) % mod;
		}
		lz[now] = 1;
	}
	return ;
}
void build( int l = 1, int r = n, int now = 1 ) {
	if( l == r ) {
		seg[now] = 1;
		return ;
	}
	int mid = ( l + r ) >> 1;
	build( l, mid, now<<1 ), build( mid+1, r, now<<1|1 );
	seg[now] = ( seg[now<<1] + seg[now<<1|1] ) % mod;
	return ;
}

void update( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
	// printf("%d %d\n",l,r);
	push( now, l, r );
	if( l > rr || r < ll || l > r ) return ;
	if( l >= ll && r <= rr ) {
		seg[now] = ( seg[now] * 2LL ) % mod;
		if( l != r ){
			lz[now<<1] = ( lz[now<<1] * 2LL ) % mod;
			lz[now<<1|1] = ( lz[now<<1|1] * 2LL ) % mod;
		}
		return ;
	}
	int mid = ( l + r ) >> 1;
	update( ll, rr, l, mid, now<<1 ), update( ll, rr, mid+1, r, now<<1|1 );
	seg[now] = ( seg[now<<1] + seg[now<<1|1] ) % mod;
	return ;
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
	for( int i = 1, idx = 0; i <= n ; i++ ) if( i != spi[par[i]] ) {
		for( int j = i ; j != -1 ; j = spi[j] )
			rot[j] = i, pos[j] = ++idx;
	}
	build();
	return ;
}

int main()
{
	fill( lz, lz+4*N-1, 1 );
	scanf("%d",&n);
	for( int i = 0, u, v ; i < n - 1 ; i++ ) {
		scanf("%d %d",&u,&v);
		u++, v++;
		g[u].emplace_back( v ), g[v].emplace_back( u );
	}
	pre( 1, 1 ), hld();
	scanf("%d %d",&q,&e);
	for( int i = 0, op, a, b ; i < q+e ; i++ ) {
		scanf("%d",&op);
		if( op ) {
			push( 1, 1, n );
			printf("%lld\n",seg[1]);
		}
		else{
			scanf("%d %d",&a,&b);
			a++, b++;
			while( rot[a] != rot[b] ) {
				if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
				update( pos[rot[a]], pos[a] );
				a = par[rot[a]];
			}
			if( dep[a] > dep[b] ) swap( a, b );
			update( pos[a], pos[b] );
		}
	}
	return 0;
}