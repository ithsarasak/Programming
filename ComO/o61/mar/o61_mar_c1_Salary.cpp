#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+100;
vector<int> g[N];
int n, A[N], hv[N];

int pre( int u, int p ) {
	int sz = 1; pii ret(0, -1);
	for( int v : g[u] ) if(v != p) {
		int z = pre( v, u );
		sz += z;
		ret = max( ret, pii( z, v ) );
	}
	hv[u] = ret.y;
	return sz;
}

void dfs( int u, int p, multiset<int> &s ) {
	if(hv[u] != -1) dfs( hv[u], u, s );
	for( int v : g[u] ) if( v != p && v != hv[u] ) {
		multiset<int> t;
		dfs( v, u, t );
		for( int x : t ) s.emplace(x);
	}
	s.emplace( A[u] );
	auto it = s.upper_bound( A[u] );
	if( it != s.end() ) s.erase( it );
	return ;
}

int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",A+i);
	}
	for( int i = 0, u, v ; i < n - 1 ; i++ ) {
		scanf("%d %d",&u,&v);
		u++, v++;
		g[u].emplace_back( v ), g[v]. emplace_back( u );
	}
	pre( 1, 0 );
	multiset<int> s;
	dfs( 1, 0, s );
	printf("%d\n", n - (int)s.size());

	return 0;
}