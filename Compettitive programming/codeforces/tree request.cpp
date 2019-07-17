#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 5e5+100;
int cnt[N][26], n, ver[N], st[N], ft[N], ans[N], hv[N], dep[N], ti, m;
vector<pii> query[N];
vector<int> g[N];
char s[N];

int pre( int now, int p ) {
	st[now] = ++ti, dep[now] = dep[p] + 1;
	ver[ti] = now;
	int sz = 1; pii ret( 0, -1 );
	for( int i : g[now] ) if( i != p ) {
		int z = pre( i, now );
		sz += z;
		ret = max( ret, pii( z, i ) );
	}
	hv[now] = ret.y;
	ft[now] = ti;
	return sz;
}

void sack( int now, int p, bool keep ) {
	for( int i : g[now] ) if( i != p && i != hv[now] ) sack( i, now, false );
	if( hv[now] != -1 ) sack( hv[now], now, true );
	cnt[dep[now]][s[now]-'a'+1] ^= 1;
	for( int u : g[now] ) if( u != p && u != hv[now] ) {
		for( int i = st[u] ; i <= ft[u] ; i++ ) cnt[dep[ver[i]]][s[ver[i]]-'a'+1] ^= 1;
	}
	for( pii i : query[now] ) {
		if( i.x < dep[now] ) ans[i.y] = 1;
		else {
			int co = 0;
			for( int c = 1 ; c <= 26 ; c++ ) if( cnt[i.x][c] != 0 ) co++;
			if( co >= 2 ) ans[i.y] = 0;
			else ans[i.y] = 1;
		}
	}
	if( !keep ) for( int i = st[now] ; i <= ft[now] ; i++ ) cnt[dep[ver[i]]][s[ver[i]]-'a'+1] ^= 1;
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 2, p ; i <= n ; i++ ) {
		scanf("%d",&p);
		g[p].emplace_back( i ), g[i].emplace_back( p );
	}
	scanf("%s",s+1);
	for( int i = 0, v, h ; i < m ; i++ ) {
		scanf("%d %d",&v,&h);
		query[v].emplace_back( pii( h, i ) );
	}
	pre( 1, 0 ), sack( 1, 0, 1 );
	for( int i = 0 ; i < m ; i++ ) {
		if( ans[i] ) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}