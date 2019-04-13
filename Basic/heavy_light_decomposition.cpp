#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define x first
#define y second
 
using namespace std;
 
const int N = 1e5+5;
 
int n;
int dep[N], par[N], rot[N], pos[N], spi[N];
int t[N<<1];
vector<pii> V, g[N];
 
int proc(int u, int p) {
	par[u] = p, dep[u] = dep[p] + 1;
	int sz = 1; pii ret(0, -1);
	for(pii v : g[u]) if(v.x != p) {
		int z = proc(v.x, u);
		sz += z;
		ret = max(ret, pii(z, v.x));
	}
	spi[u] = ret.y;
	return sz;
}
 
void dfs(int u, int p) {
	for(pii v : g[u]) if(v.x != p) {
		t[pos[v.x] + N] = v.y;
		dfs(v.x, u);
	}
}
 
void hld() {
	for(int i = 1, idx = 0; i <= n; i++) if(spi[par[i]] != i)
		for(int j = i; j != -1; j = spi[j])
			rot[j] = i, pos[j] = ++idx;			
	dfs(1, 1);
	for(int i = N-1; i; i--) t[i] = max(t[i<<1], t[i<<1|1]);
}
 
void update(int x, int k) { for(t[x += N] = k; x != 1; x >>= 1) t[x>>1] = max(t[x], t[x^1]); }
 
int query(int l, int r) {
	int ret = 0;
	for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ret = max(ret, t[l++]);
		if(r & 1) ret = max(ret, t[--r]);
	}
	return ret;
}
 
void solve() {
	scanf("%d", &n);
	V.clear();
	memset(dep, 0, sizeof dep);
	memset(par, 0, sizeof par);
	memset(rot, 0, sizeof rot);
	memset(pos, 0, sizeof pos);
	memset(spi, 0, sizeof spi);
	memset(t, 0, sizeof t);
	for(int i = 1; i < N; i++) g[i].clear();
	for(int i = 1, a, b, c; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[a].emplace_back(b, c), g[b].emplace_back(a, c);
		V.emplace_back(a, b);
	}
	proc(1, 1), hld();
	char S[N];
	while(scanf(" %s", S), S[0] != 'D') {
		int a, b;
		scanf("%d %d", &a, &b);
		if(S[0] == 'Q') {
			int ret = 0;
			while(rot[a] != rot[b]) {
				if(dep[rot[a]] < dep[rot[b]]) swap(a, b);
				ret = max(ret, query(pos[rot[a]], pos[a]));
				a = par[rot[a]];
			}
			if(dep[a] > dep[b]) swap(a, b);
			ret = max(ret, query(pos[a]+1, pos[b]));
			printf("%d\n", ret);
		} else {
			pii now = V[a-1];
			if(dep[now.x] < dep[now.y]) swap(now.x, now.y);
			update(pos[now.x], b);
		}
	}
}
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) solve();
 
	return 0;
}
 