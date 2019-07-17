#include <bits/stdc++.h>

using namespace std;
int ap[11000], ind[11000], low[11000], tim;
int n, m, ans;
vector<int> g[11000];
void dfs( int no, int p )
{
	if( ind[no] )return ;
	ind[no] = low[no] = ++tim;
	int child = 0;
	for( int i = 0 ; i < g[no].size() ; i++ ){
		if( !ind[g[no][i]] ){
			child++;
			dfs( g[no][i], no );
			low[no] = min( low[no], low[g[no][i]] );
			if( no != 1 && ind[no] <= low[g[no][i]] ){
				ap[no] = 1;
			} 
		}
		else{
			if( g[no][i] == p )continue;
			low[no] = min( low[no], ind[g[no][i]] );
		}
	}
	if( no == 1 && child > 1 )ap[no] = 1;	
}
int main()
{
	while( 1 ){
		tim = 0, ans = 0;
		memset( ind, 0, sizeof ind );
		memset( ap, 0, sizeof ap );
		memset( low, 0, sizeof low );
		for( int i = 0 ; i < 10100 ; i++ )g[i].clear();
		scanf("%d %d",&n,&m);
		if( n == 0 && m == 0 )break ;
		for( int i = 0 ; i < m ; i++ ){
			int f, t;
			scanf("%d %d",&f,&t);
			g[f].push_back( t );
			g[t].push_back( f );
		}
		dfs( 1, 0 );
		for( int i = 1 ; i <= n ; i++ ){
			if( ap[i] )ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}