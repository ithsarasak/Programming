#include <bits/stdc++.h>
#define pii pair<int, long long>
#define x first
#define y second
using namespace std;

const int N = 1e5+100;
int n, q, dep[N], hv[N];
long long arr[N], va[N];
vector<pii> query[N];
vector<int> g[N];
map<int, long long> m;

int pre( int now, int p ) {
	dep[now] = dep[p] + 1;
	int sz = 1; pii ret( 0, -1 );
	for( int i : g[now] ) if( i != p ) {
		int z = pre( i, now );
		ret = max( ret, pii( z, i ) );
		sz += z;
	}
	hv[now] = ret.y;
	return sz;
}

void sack( int now, int p, map<int, long long> &m ) {
	if( hv[now] != -1 ) sack( hv[now], now, m );
	for( int i : g[now] ) if( i != p && i != hv[now] ) {
		map<int, long long> t;
		t.clear();
		sack( i, now, t );
		for( auto it = t.begin() ; it != t.end() ; it++ ) m[it->first] += it->second;
	}
	m[dep[now]]++;
	for( pii i : query[now] ) va[now] -= m[dep[now]+i.x] * i.y;
	return ;
}

void dfs( int now, int p ) {
	for( pii i : query[now] ) arr[dep[now]+i.x] += i.y;
	va[now] += arr[dep[now]];
	for( int i : g[now] ) if( i != p ) dfs( i, now );
	for( pii i : query[now] ) arr[dep[now]+i.x] -= i.y;
	return ;
}

int main()
{
	scanf("%d %d",&n,&q);
	for( int i = 0, a ; i < n ; i++ ) {
		scanf("%d %lld",&a,&va[i]);
		if( a != -1 ) g[a].emplace_back( i ), g[i].emplace_back( a );
	}
	for( int i = 0, x, y ; i < q ; i++ ) {
		long long b;
		scanf("%d %d %lld",&x,&y,&b);
		query[x].emplace_back( pii( y, b ) );
	}
	pre( 0, 0 ), sack( 0, 0, m ), dfs( 0, -1 );
	for( int i = 0 ; i < n ; i++ ) printf("%lld\n",va[i]);
	return 0;
}