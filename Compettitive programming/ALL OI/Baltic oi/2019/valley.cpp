#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int n, S, q, E, in[N], out[N], pos[N], dep[N], par[N][20], s[N], e[N], shop[N];
long long d[N], dp[N], ans[N][20];
vector<pii> g[N];
void dfs( int u, int p ) {
    static int idx = 0;
    in[u] = ++idx, pos[idx] = u;
    dep[u] = dep[p] + 1, par[u][0] = p;
    if( shop[u] ) dp[u] = d[u];
    for( pii v : g[u] ) if( v.x != p ) {
        d[v.x] = d[u] + v.y;
        dfs( v.x, u );
        dp[u] = min( dp[u], dp[v.x] );
    }
    out[u] = idx;
}

int main()
{
    fill_n( dp, N, 1e18 ), fill_n( ans[0], N * 20, 1e18 );
    scanf("%d %d %d %d",&n,&S,&q,&E);
    for( int i = 1 ; i < n ; i++ ) {
        long long dd;
        scanf("%d %d %lld",&s[i],&e[i],&dd);
        g[s[i]].emplace_back( pii( e[i], dd ) ), g[e[i]].emplace_back( pii( s[i], dd ) );
    }
    for( int i = 1, ss ; i <= S ; i++ ) {
        scanf("%d",&ss);
        shop[ss] = 1;
    }
    dfs( E, 0 );
    for( int i = 1 ; i <= n ; i++ ) if( dp[i] != 1e18 ) ans[i][0] = dp[i] - 2*d[i];
    for( int i = 1 ; i <= 17 ; i++ ) {
        for( int j = 1 ; j <= n ; j++ ) {
            par[j][i] = par[par[j][i-1]][i-1];
            ans[j][i] = min( ans[j][i-1], ans[par[j][i-1]][i-1] );
        }
    }
    for( int i = 1, a, b ; i <= q ; i++ ) {
        scanf("%d %d",&a,&b);
        int now = dep[s[a]] > dep[e[a]] ? s[a] : e[a];
        if( in[now] > in[b] || out[b] > out[now] ) {
            printf("escaped\n");
            continue;
        }
        int dist = dep[b] - dep[now], u = b;
        long long an = 1e18;
        for( int i = 17 ; i >= 0 ; i-- ) if( dist >> i & 1 ) {
            an = min( an, ans[u][i] );
            u = par[u][i];
        }
        an = min( an, ans[u][0] );
        if( an >= 1e18 ) printf("oo\n");
        else printf("%lld\n", an + d[b]);
    }
    return 0;
}