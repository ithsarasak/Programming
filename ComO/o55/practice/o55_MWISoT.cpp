#include <bits/stdc++.h>

using namespace std;
struct mm{
	int self, child;
}mic[100100];
int n, w[100100];
vector<int> g[100100];
void dfs( int now, int p )
{
	for( int i = 0 ; i < g[now].size() ; i++ ){
		if( g[now][i] == p )continue ;
		dfs( g[now][i], now );
		mic[now].self += mic[g[now][i]].child;
		mic[now].child += max( mic[g[now][i]].child, mic[g[now][i]].self );
	}
	mic[now].self += w[now];
	return ;
}
int main()
{
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )scanf("%d",&w[i]);
	for( int i = 0 ; i < n - 1 ; i ++ ){
		int f, t;
		scanf("%d %d",&f,&t);
		g[f].push_back( t );
		g[t].push_back( f );
	}
	dfs( 0, -1 );
	printf("%d",max( mic[0].child, mic[0].self ) );
	return 0;
}