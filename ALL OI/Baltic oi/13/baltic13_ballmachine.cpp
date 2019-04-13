#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+100;

vector<int> g[N];
int n, q, root, dp[N], pos[N], dep[N];
int par[N][18], has[N];
priority_queue<pii, vector<pii>, greater<pii>> Q;

int dfs( int u, int p ) {
	dp[u] = u, par[u][0] = p;
	dep[u] = dep[p] + 1;
	for(int i = 1; i <= 17; i++) par[u][i] = par[par[u][i-1]][i-1];
	for(int v : g[u]) if(v != p) dp[u] = min(dp[u], dfs(v, u));
	sort(g[u].begin(), g[u].end(), [&](const int &a, const int &b) {
		return dp[a] < dp[b];
	});
	return dp[u];
}

void get(int u, int p) {
	static int idx = 0;
	for(int v : g[u]) if( v != p ) get( v, u );
	pos[u] = ++idx;
}

int main()
{
	scanf("%d %d",&n,&q);
	for( int i = 1, p ; i <= n ; i++ ) {
		scanf("%d",&p);
		if( !p )root = i;
		else g[p].emplace_back( i ), g[i].emplace_back( p );
	}
	dfs( root, 0 );
	get( root, 0 );
	for(int i = 1; i <= n; i++) Q.emplace(pos[i], i);
	for(int i = 1; i <= q; i++) {
		int T, a;
		scanf("%d %d", &T, &a);
		if(T == 1) {
			int ret = -1;
			while(a--) {
				pii now = Q.top(); Q.pop();
				has[now.y] = true;
				ret = now.y;
			}
			printf("%d\n", ret);
		} 
		else {
			int x = a;
			for(int i = 17; ~i; i--) if(has[par[x][i]]) x = par[x][i];
			has[x] = false;
			Q.emplace(pos[x], x);
			printf("%d\n", dep[a] - dep[x]);
		}
	}

	return 0;
}