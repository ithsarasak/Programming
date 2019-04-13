#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+100;
int n, m, ans;
set<int> g[N];
vector<pii> ed;
map<set<int>, int> ma;
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 0, u, v ; i < m ; i++ ) {
		scanf("%d %d",&u,&v);
		g[u].insert( v ), g[v].insert( u );
		ed.emplace_back( pii( u, v ) );
	}
	for( int i = 1 ; i <= n ; i++ ) ma[g[i]]++;
	for( auto it = ma.begin() ; it != ma.end() ; it++ ) ans += ( it->second-1 ) * ( it->second ) / 2;
	ma.clear();
	for( pii i : ed ) {
		g[i.x].erase( i.y ), g[i.y].erase( i.x );
		ma[g[i.x]]++, ma[g[i.y]]++;
		ans += ma[g[i.x]] / 2;
		ma[g[i.x]] = 0, ma[g[i.y]] = 0;
		g[i.x].insert( i.y ), g[i.y].insert( i.x );
	}
	printf("%d",ans);
	return 0;
}