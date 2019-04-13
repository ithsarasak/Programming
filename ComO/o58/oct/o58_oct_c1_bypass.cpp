#include <bits/stdc++.h>

using namespace std;
struct pa{
	int no;
	long long va;
};
struct dd{
	pa first;
	pa second;
}dp[100100];
struct ee{
	int f, t;
};
long long child[100100], n, ans;
vector<ee> e;
vector<int> g[100100];
void dfs( int now, int p )
{
	for( int i = 0 ; i < g[now].size() ; i++ ){
		if( g[now][i] == p )continue;
		dfs( g[now][i], now );
		child[now] += child[g[now][i]];
		if( child[g[now][i]] > dp[now].first.va ){
			dp[now].second = dp[now].first;
			dp[now].first.va = child[g[now][i]];
			dp[now].first.no = g[now][i];
		}
		else if( child[g[now][i]] > dp[now].second.va ){
			dp[now].second.va = child[g[now][i]];
			dp[now].second.no = g[now][i];
		}
	}
	child[now] += 1;
	if( n - child[now] > dp[now].first.va ){
			dp[now].second = dp[now].first;
			dp[now].first.va = n - child[now];
			dp[now].first.no = p;
	}
	else if( n - child[now] > dp[now].second.va ){
		dp[now].second.va = n - child[now];
		dp[now].second.no = p;
	}
	return ;
}
int main()
{
	scanf("%lld",&n);
	for( int i = 0 ; i < n - 1 ; i ++ ){
		int f, t;
		scanf("%d %d",&f,&t);
		e.push_back({ f, t });
		g[f].emplace_back( t );
		g[t].emplace_back( f );	
	}
	dfs( 1, 0 );
	for( int i = 0 ; i < e.size() ; i++ ){
		long long a, b;
		int f = e[i].f, t = e[i].t;
		if( dp[f].first.no == t )a = dp[f].second.va;
		else a = dp[f].first.va;
		if( dp[t].first.no == f )b = dp[t].second.va;
		else b = dp[t].first.va;
		ans = max( ans, a*b );
	}
	printf("%lld",ans);
	return 0;
}