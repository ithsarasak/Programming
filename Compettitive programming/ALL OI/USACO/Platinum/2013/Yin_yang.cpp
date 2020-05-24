#include <bits/stdc++.h>
#define pii pair<int, int>
#define t first
#define d second 
using namespace std;

const int N = 1e5+10;
int n, sz[N], dp[2][N], t[2][N], cnt[2*N];
bool chk[N];
int cou, book;
long long ans;
vector<pii> g[N];

int getsz( int now, int p ) {
	sz[now] = 1;
	for( pii i : g[now] ) if( i.t != p && !chk[i.t] ) sz[now] += getsz( i.t, now );
	return sz[now];
}

int find_cen( int now, int p, int all, pii &ret ) {
	int mx = all - sz[now];
	for( pii i : g[now] ) if( i.t != p && !chk[i.t] ) mx = max( mx, find_cen( i.t, now, all, ret ) );
	ret = min( ret, pii( mx, now ) );
	return sz[now];
}

void dfs(int u, int p, int len, bool fill) {
    bool m = (cnt[len + N] > 0);
    if(!fill) {
        if( len == 0 && m ) ++ans;
        if( t[1][N - len] == book ) ans += ( long long )dp[1][N - len];
        if((len == 0 || m) && t[0][N - len] == book) ans += ( long long )dp[0][N - len];
    } else {
        if(t[m][len + N] < book) t[m][len + N] = book, dp[m][len + N] = 1;
        else ++dp[m][len + N];
    }
    ++cnt[len + N];
    for(pii v : g[u]) if(v.t != p && !chk[v.t]) dfs(v.t, u, len + v.d, fill);
    --cnt[len + N];
}

void solve(int u) {
    ++book;
    if(getsz(u, u) <= 1) return;
    pii ret( 1e9, -1 );
    find_cen(u, u, sz[u], ret );
    u = ret.d;
    for(pii v : g[u]) if(!chk[v.t]) {
        dfs(v.t, u, v.d, 0);
        dfs(v.t, u, v.d, 1);
    }
    chk[u] = 1;
    for(pii v : g[u]) if(!chk[v.t]) solve(v.t);
}

int main()
{
	freopen("yinyang.in", "r", stdin);
	freopen("yinyang.out", "w",stdout);
	scanf("%d",&n);
	for( int i = 0, a, b, c ; i < n - 1 ; i++ ) {
		scanf("%d %d %d",&a,&b,&c);
		g[a].emplace_back( pii( b, c ? 1 : -1  ) ), g[b].emplace_back( pii( a, c ? 1 : -1 ) );
	}
	solve( 1 );
	printf("%lld",ans);
	return 0;
}