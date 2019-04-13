#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define x first 
#define y second

using namespace std;

const int N = 1e6 + 100;
int n, deg[N];
long long dm[N], ans;
pll par[N], dp[N];
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		long long p, w;
		scanf("%lld %lld",&p,&w);
		par[i] = pll( p, w );
		deg[p]++;
	}
	queue<int> q;
	for( int i = 1 ; i <= n ; i++ ) if( !deg[i] ) q.emplace( i );
	while( !q.empty() ) {
		int now = q.front();
		q.pop();
		dm[now] = max( dm[now], dp[now].x + dp[now].y );
		dm[par[now].x] = max( dp[par[now].x].x, dm[now] );
		long long path = dp[now].x + par[now].y;
		if( path > dp[par[now].x].x ) swap( path, dp[par[now].x].x );
		if( path > dp[par[now].x].y ) swap( path, dp[par[now].x].y );
		if( !--deg[par[now].x] ) q.emplace( par[now].x );
	}
	for( int i = 1 ; i <= n ; i++ ) if( deg[i] ) {
		int p = i;
		vector<pll> cyc;
		deque<pll> q;
		while( deg[p] ) {
			deg[p]--;
			cyc.emplace_back( pll( p, par[p].y ) );
			p = par[p].x;
		}
		long long ret = 0, dis = cyc[0].y, trash = 0;
		for( pll v : cyc ) ret = max( ret, max( dm[v.x], dp[v.x].x + dp[v.x].y ) );
		for( int i = 1 ; i < cyc.size() ; i++ ) {
			while( !q.empty() && q.back().x < dis + dp[cyc[i].x].x ) q.pop_back();
			q.emplace_back( pll( dis + dp[cyc[i].x].x, cyc[i].x ) );
			dis += cyc[i].y;
		}
		ret = max( ret, dp[cyc[0].x].x + q.front().x );
		for( int i = 0 ; i < cyc.size() - 1 ; i++ ) {
			if( q.front().y == cyc[i + 1].x ) q.pop_front();
			while( !q.empty() && q.back().x < dis + dp[cyc[i].x].x ) q.pop_back();
			q.emplace_back( pll( dis + dp[cyc[i].x].x, cyc[i].x ) );
			dis += cyc[i].y, trash += cyc[i].y;
			ret = max( ret, dp[cyc[i+1].x].x + q.front().x - trash );
		}
		ans += ret;
	}
	printf("%lld",ans);
	return 0;
}