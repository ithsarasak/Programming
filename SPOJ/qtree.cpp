#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;

const int N = 1e4+100;
int t, rot[N], par[N], seg[4*N], dep[N], spi[N], pos[N], n;
vector<pii> g[N], V;

void update( int idx, int va, int l = 1, int r = n, int now = 1 ) {
	if( l > idx || r < idx || l > r ) return ;
	if( l == r ) {
		seg[now] = va;
		return ;
	}
	int mid = ( l + r ) >> 1;
	update( idx, va, l, mid, now * 2 ), update( idx, va, mid + 1, r, now*2+1 );
	seg[now] = max( seg[now*2], seg[now*2+1] );
	return ;
}

int query( int ll, int rr, int l = 1 , int r = n, int now = 1 ) {
	if( l > rr || r < ll || l > r || ll > rr )return 0;
	if( l >= ll && r <= rr )return seg[now];
	int mid = ( l + r ) >> 1;
	return max( query( ll, rr, l, mid, now*2 ), query( ll, rr, mid + 1, r, now*2+1 ) );
}

int pre( int now, int p ) {
	dep[now] = dep[p] + 1;
	par[now] = p;
	int sz = 1; pii ret( 0, -1 );
	for( pii v : g[now] ) if( v.x != p ) {
		int z = pre( v.x, now );
		sz += z;
		ret = max( ret, mp( z, v.x ) );
	}
	spi[now] = ret.y;
	return sz;
}

void dfs( int now, int p ) {
	for( pii v : g[now] ) if( v.x != p ) {
		update( pos[v.x], v.y );
		dfs( v.x, now );
	}
}

void hld() {
	for( int i = 1, idx = 0 ; i <= n ; i++ ) if( i != spi[par[i]] )
		for( int j = i ; j != -1 ; j = spi[j] )
			rot[j] = i, pos[j] = ++idx;
	dfs( 1, 1 );
}

void solve() {
	scanf("%d",&n);
	memset(dep, 0, sizeof dep);
	memset(par, 0, sizeof par);
	memset(rot, 0, sizeof rot);
	memset(pos, 0, sizeof pos);
	memset(spi, 0, sizeof spi);
	memset(seg, 0, sizeof seg);
	for(int i = 1; i < N; i++) g[i].clear();
	for( int i = 0, u, v, d ; i < n ; i++ ) {
		scanf("%d %d %d",&u,&v,&d);
		g[u].emplace_back( mp( v, d ) ), g[v].emplace_back( mp( u, d ) );
		V.emplace_back( mp( u, v ) );
	}
	pre( 1, 1 ), hld();
	char s[N];
	while( scanf("%s",s), s[0] != 'D' ) {
		int a, b;
		scanf("%d %d",&a,&b);
		if( s[0] == 'Q' ) {	
			int ans = 0;
			while( rot[a] != rot[b] ) {	
				if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
				ans = max( ans, query( pos[rot[a]], pos[a] ) );
				a = par[rot[a]];
			}
			if( dep[a] > dep[b] ) swap( a, b );
			ans = max( ans, query( pos[a]+1, pos[b] ) );
			printf("%d\n",ans); 
		}
		else {
			pii temp = V[a-1];
			if( dep[temp.x] < dep[temp.y] ) swap( temp.x, temp.y );
			update( pos[temp.x], b );
		}
	}
}
int main()
{
	scanf("%d",&t);
	while( t-- )solve();
	return 0;
}