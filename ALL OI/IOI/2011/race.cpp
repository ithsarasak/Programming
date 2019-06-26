#include <bits/stdc++.h>
#define pii pair<int ,int> 
#define x first
#define y second
using namespace std;

const int N = 2e5+100;
int n, dep[N], ver[N], st[N], ft[N], hv[N], ti, ans = 1e9;
map<long long, int> m;
vector<pii> g[N];
long long path[N], k;

int pre( int u, int p ) {
	st[u] = ++ti;
	ver[ti] = u, dep[u] = dep[p] + 1;
	int sz = 1; pii ret( 0, -1 );
	for( pii i : g[u] ) if( i.x != p ) {
		path[i.x] = path[u] + i.y;
		int z = pre( i.x, u );
		sz += z;
		ret = max( ret, pii( z, i.x ) );
	}
	hv[u] = ret.y;
	ft[u] = ti;
	return sz;
}

void sack( int now, int p, bool keep ) {
	for( pii i : g[now] ) if( i.x != p && i.x != hv[now] ) sack( i.x, now, 0 );
	if( hv[now] != -1 ) sack( hv[now], now, 1 );
	if( m[path[now]] == 0 ) m[path[now]] = dep[now];
	else m[path[now]] = min( dep[now], m[path[now]] );
	if( m[path[now]+k] != 0 ) ans = min( ans, m[path[now]+k] - dep[now] );
	// cout << "im here " << now << endl;
	// for( auto it = m.begin() ; it != m.end() ; it++ ) cout << it->first << " " << it->second << endl;
	for( pii u : g[now] ) if( u.x != p && u.x != hv[now] ) {
		for( int i = st[u.x] ; i <= ft[u.x] ; i++ ) if( m[2LL*path[now]+k-path[ver[i]]] != 0 ) {
			ans = min( ans, dep[ver[i]] + m[2LL*path[now]+k-path[ver[i]]] - 2*dep[now] );
		}
		for( int i = st[u.x] ; i <= ft[u.x] ; i++ ) {
			if( m[path[ver[i]]] == 0 ) m[path[ver[i]]] = dep[ver[i]];
			else m[path[ver[i]]] = min( dep[ver[i]], m[path[ver[i]]] );
		}
	}
	if( !keep ) m.clear();
}

int best_path( int N, int K, int H[][2], int L[] ) {
	n = N, k = K; 
	for( int i = 0 ; i < n - 1 ; i++ ) {
		g[H[i][0]+1].emplace_back( pii( H[i][1] + 1, L[i] ) );
		g[H[i][1]+1].emplace_back( pii( H[i][0] + 1, L[i] ) );
	}
	pre( 1, 0 ), sack( 1, 0, 1 );
	return ( ans != 1e9 ) ? ans : -1;
}