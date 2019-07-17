#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define long long long
using namespace std;

const int N = 1e5+100;
int n;
long dom[N], c[N];
int ti, st[N], ft[N], hv[N], cnt[N], ver[N], mx[N];
vector<int> g[N];

int pre( int now, int p ) {
	st[now] = ++ti;
	ver[ti] = now;
	int sz = 1; pii ret( 0, -1 );
	for( int i : g[now] ) if( i != p ) {
		int z = pre( i, now );
		sz += z, ret = max( ret, pii( z, i ) );
	}
	hv[now] = ret.y;
	ft[now] = ti;
	return sz;
}

void sack( int now, int p, bool keep ) {
	for( int i : g[now] ) if( i != p && i != hv[now] ) sack( i, now, 0 );
	if( hv[now] != -1 ) {
		sack( hv[now], now, 1 );
		mx[now] = mx[hv[now]];
		dom[now] = dom[hv[now]];
	}
	cnt[c[now]]++;
	if( cnt[c[now]] > mx[now] ) {
		dom[now] = 0;
		mx[now] = cnt[c[now]];
	}
	if( cnt[c[now]] == mx[now] ) dom[now] += c[now];
	for( int u : g[now] ) if( u != p && u != hv[now] ){
		for( int i = st[u] ; i <= ft[u] ; i++ ) {
			cnt[c[ver[i]]]++;
			if( cnt[c[ver[i]]] > mx[now] ) {
				dom[now] = 0;
				mx[now] = cnt[c[ver[i]]];
			}
			if( cnt[c[ver[i]]] == mx[now] ) dom[now] += c[ver[i]];
		}
	}
	if( !keep ) {
		for( int i = st[now] ; i <= ft[now] ; i++ ) cnt[c[ver[i]]]--;
	}
	return ;
}
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) scanf("%d",&c[i]);
	for( int i = 0, u, v ; i < n - 1 ; i++ ) {
		scanf("%d %d",&u,&v);
		g[u].emplace_back( v ), g[v].emplace_back( u );
	}
	pre( 1, 0 ), sack( 1, 0, 1 );
	for( int i = 1 ; i <= n ; i++ ) printf("%lld ",dom[i]);
	return 0;
}