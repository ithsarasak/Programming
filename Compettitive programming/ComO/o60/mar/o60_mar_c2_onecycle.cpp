#include <bits/stdc++.h>
#define iii tuple<int, int, int>
#define pii pair<int, int>
#define t first
#define d second
#define mp make_pair
#define mt make_tuple

using namespace std;

const int N = 3e3 + 300;
int n, lv[N], par[N], dis[N][N], path[N];
vector<iii> edge, ans, trash;
vector<pii> g[N];
int mic[15][N];

int findroot( int now ) {
	if( par[now] == now ) return now;
	else return par[now] = findroot( par[now] );
}

void dfs( int now, int p, int d ) {
	lv[now] = lv[p] + 1;
	path[now] = path[p] + d;
	mic[0][now] = p;
	for( int i = 0 ; i < g[now].size() ; i++ ) {
		if( g[now][i].t != p )dfs( g[now][i].t, now, g[now][i].d );
	}
	return ;
}

int lca( int a, int b ) {
	int sum = 0;
	if( lv[a] > lv[b] ) swap( a, b );
	for( int i = 12 ; i >= 0 ; i-- ) {
		if( lv[mic[i][b]] < lv[a] ) continue;
		b = mic[i][b];
	}
	if( a == b )return a;
	for( int i = 12 ; i >= 0 ; i-- ) {
		if( mic[i][b] == mic[i][a] ) continue;
		b = mic[i][b], a = mic[i][a];
	}
	return mic[0][a];
}

int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = 1 ; j <= n ; j++ ) {
			if( i == j ) continue;
			scanf("%d",&dis[i][j]);
			if(i < j) edge.emplace_back( mt( dis[i][j], i, j ) );
		}
	}
	sort( edge.begin(), edge.end() );
	iota(par, par+N, 0);
	for( int i = 0, a, b, c ; i < edge.size() ; i++ ) {
		tie( a, b, c ) = edge[i];
		int t1 = findroot( b ), t2 = findroot( c );
		if( t1 != t2 ) {
			par[t1] = t2;
			ans.emplace_back( mt( min( b, c ), max( b, c ), a ) );
			g[b].emplace_back( mp( c, a ) ), g[c].emplace_back( mp( b, a ) );
		}
		else trash.emplace_back( edge[i] );
	}
	dfs( 1, 0, 0 );
	for( int i = 1 ; i <= 12 ; i++ ) {
		for( int j = 1 ; j <= n ; j++ ) {
			mic[i][j] = mic[i-1][mic[i-1][j]];
		}
	}
	for( int i = 0, a, b, c ; i < trash.size() ; i++ ) {
		tie( a, b, c ) = trash[i];
		int temp = lca( b, c );
		if( path[b] + path[c] - 2*path[temp] > dis[b][c] ) {
			ans.emplace_back( mt( min( b, c ), max( b, c ), a ) );
			break;
		}
	}
	sort( ans.begin(), ans.end() );
	for( int i = 0, a, b, c ; i < ans.size() ; i++ ) {
		tie( a, b, c ) = ans[i];
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}