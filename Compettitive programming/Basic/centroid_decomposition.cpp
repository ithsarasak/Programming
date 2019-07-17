#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;

int n, k, cnt, ans;
int sz[N], chk[N];
int dp[N], book[N];
vector<int> g[N];

int getsz(int u, int p) {
	sz[u] = 1;
	for(int v : g[u]) if(v != p && !chk[v]) sz[u] += getsz(v, u);
	return sz[u];
}

int find_cen(int u, int p, int all, pii &ret) {
	int mx = all - sz[u];
	for(int v : g[u]) if(v != p && !chk[v]) mx = max(mx, find_cen(v, u, all, ret));
	ret = min(ret, pii(mx, u));
	return sz[u];
}

void dfs(int u, int p, int len, bool fill) {
	if(len > k) return;
	if(!fill) {
		if(len == k) ++ans;
		if(book[k-len] == cnt) ans += dp[k-len];
	} else {
		if(book[len] < cnt) dp[len] = 1;
		else ++dp[len];
		book[len] = cnt;
	}
	for(int v : g[u]) if(v != p & !chk[v]) dfs(v, u, len+1, fill);
}

void solve(int u) {
	getsz(u, u);
	pii ret(sz[u]+1, -1);
	find_cen(u, u, sz[u], ret);
	u = ret.y;
	++cnt;
	for(int v : g[u]) if(!chk[v]) {
		dfs(v, u, 1, 0);
		dfs(v, u, 1, 1);
	}
	chk[u] = true;
	for(int v : g[u]) if(!chk[v]) solve(v);	
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1, a, b; i < n; i++) {
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	solve(1);
	printf("%d\n", ans);

	return 0;
}