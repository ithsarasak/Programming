#include <bits/stdc++.h>

using namespace std;
int n, tt;
int go[1010], to[1010], mark[1010];
vector<int> g[1010];
queue<int> q;
int main()
{
	scanf("%d %d",&n,&tt);
	for( int i = 1 ; i <= n ; i++ )scanf("%d",&go[i]);
	for( int i = 1 ; i <= n ; i++ )scanf("%d",&to[i]);
	for( int i = 1 ; i <= n ; i++ ){
		if( !go[i] )continue;
		for( int j = i + 1 ; j <= n ; j++ ){
			if( go[j] )g[i].push_back( j );
		}
	}
	for( int i = n ; i >= 1 ; i-- ){
		if( !to[i] )continue;
		for( int j = i - 1 ; j >= 1 ; j-- ){
			if( to[j] )g[i].push_back( j );
		}
	}
	q.push( 1 );
	while( !q.empty() ){
		int t = q.front();
		//printf("%d\n",t);
		q.pop();
		mark[t] = 1;
		for( int i = 0 ; i < g[t].size() ; i++ ){
			if( !mark[g[t][i]] ){
				mark[g[t][i]] = 1;
				q.push( g[t][i] );
			}
		}
	}
	if( mark[tt] )printf("YES");
	else printf("NO");
	return 0;
}