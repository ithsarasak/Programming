#include <bits/stdc++.h>
#define pii pair<int, int>
#define iii tuple<int, int, int>
#define t first
#define d second
#define mp make_pair
#define mt make_tuple
using namespace std;

const int N = 1e4 + 100;
int n, k, dp[N][2], chk[N], per[12], ans;
vector<iii> edge;
vector<pii> g[N];

void dfs( int u, int p  ) {	
	dp[u][0] = 0, dp[u][1] = 0;
	int sum = 0;
	for( pii v : g[u] ) if(v.t != p) {
		dfs( v.t, u );
		dp[u][0] += max( dp[v.t][0], dp[v.t][1] );
		sum += max( dp[v.t][0], dp[v.t][1] );
	}
	dp[u][1] = dp[u][0];
	if( !chk[u] ){
		for( pii v : g[u] ) {
			if( !chk[v.t] && v.t != p ) dp[u][1] = max( dp[u][1], sum-max( dp[v.t][0], dp[v.t][1] ) + v.d + dp[v.t][0] );
		}
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 0, u, v, d ; i < n - 1 ; i++ ) {
		scanf("%d %d %d",&u,&v,&d);
		g[u].emplace_back( mp( v, d ) ), g[v].emplace_back( mp( u, d ) );
	}
	for( int i = 0, u, v, d ; i < k ; i++ ) {
		scanf("%d %d %d",&u,&v,&d);
		edge.emplace_back( mt( u, v, d ) );
	}
	for(int bit = 0; bit < (1 << k); bit++) {
		int ret = 0;
		memset(chk, 0, sizeof chk);
		for(int i = 0; i < k; i++) if(bit >> i & 1) {
			int u, v, d;
			tie(u, v, d) = edge[i];
			if(chk[u] || chk[v]) continue;
			chk[u] = chk[v] = true;
			ret += d;
		}	
		dfs(1, 1);
		ans = max(ans, ret + max(dp[1][0], dp[1][1]));
	}
	printf("%d",ans);
	return 0;
}