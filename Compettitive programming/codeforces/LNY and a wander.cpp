#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> g[100100], ans;
int visit[100100];
priority_queue<int> q;
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 0 ; i < m ; i++ ){
		int s, t;
		scanf("%d %d",&s,&t);
		g[s].push_back( t );
		g[t].push_back( s );
	}
	q.push( -1 );
	while( !q.empty() ){
		int t = -1*q.top();
		q.pop();
		ans.push_back( t );
		visit[t] = 1;
		for( int i = 0 ; i < g[t].size() ; i++ ){
			if( !visit[g[t][i]] ){
				visit[g[t][i]] = 1;
				q.push( -1*g[t][i] );
			}
		}
	}
	for( int i = 0 ; i < n ; i++ )printf("%d ",ans[i]);
	return 0;
}