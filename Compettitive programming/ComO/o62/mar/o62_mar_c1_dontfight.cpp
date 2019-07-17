#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define long long long 
using namespace std;

const int N = 3e5+100;
int n, hv[N], st[N], ft[N], ver[N], ti;
long va[N], ans = 1e15, sum[N];
vector<int> g[N];
multiset<long> s;

long ma3( long a, long b, long c ) { return max( a, max( b, c ) ); }

long mi3( long a, long b, long c ) { return min( a, min( b, c ) ); }

void cal1( long a, long b ) { ans = min( ans, ma3( sum[1] - a, a - b, b ) - mi3( sum[1] - a, a - b, b ) ); }

void cal2( long a, long b ) { ans = min( ans, ma3( sum[1] - a - b, a, b ) - mi3( sum[1] - a - b, a, b ) ); }

int pre( int now, int p ) {
	int sz = 1; pii ret( 0, -1 );
	sum[now] = va[now];
	st[now] = ++ti;
	ver[ti] = now;
	for( int i : g[now] ) if( i != p ) {
		int z = pre( i, now );
		sz += z;
		sum[now] += sum[i];
		ret = max( ret, pii( z, i ) );
	}
	ft[now] = ti, hv[now] = ret.y;
	return sz;
}

void think( multiset<long> &s, int now, long j, bool type ) {
	multiset<long>::iterator it1, it2, it3;
	it3 = it2 = s.lower_bound( ( sum[now]-j )>>1 );
	if( it2 == s.end() ) it2--;
	else it3++;
	it1 = it2;
	if( it2 != s.begin() ) it1--;
	if( !type ) cal1( sum[now], *it1 ), cal1( sum[now], *it2 );
	else cal2( j, *it1 ), cal2( j, *it2 );
	if( it3 != s.end() ) {
		if( !type ) cal1( sum[now], *it3 ); 
		else cal2( j, *it3 ); 
	}
	return ;
}

void sack( int now, int p, bool keep ) {
	for( int i : g[now] ) if( i != p && i != hv[now] ) sack( i, now, false  );
	if( hv[now] != -1 ) sack( hv[now], now, true );
	for( int u : g[now] ) if( u != p && u != hv[now] ) {
		for( int i = st[u] ; i <= ft[u] ; i++ ) think( s, 1, sum[ver[i]], true );
		for( int i = st[u] ; i <= ft[u] ; i++ ) s.insert( sum[ver[i]] );
	}
	s.insert( sum[now] );
	if( now != 1 ) think( s, now, 0, false );
	if( !keep ) s.clear();
	return ;
}

int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&va[i]);
	for( int i = 0, u, v ; i < n-1 ; i ++ ) {
		scanf("%d %d",&u,&v);
		g[u].emplace_back( v ), g[v].emplace_back( u );
	}
	pre( 1, 0 ), sack( 1, 0, true ); 
	printf("%lld",ans);
	return 0;
}