#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

const int N = 2e5 + 10;

vector<vi> ccs, g;
int n, m, q;
int lca[19][N], pre[N], low[N], dep[N], dp[N], id[N];
bool cut[N], art[N];

void find_component( int u, int p ) {
    static int idx = 0;
    static stack<int> s;
    pre[u] = low[u] = ++idx;
    s.emplace( u );
    int chk = 0;
    for( int v : g[u] ) if( !pre[v] ) {
        find_component( v, u );
        chk++;
        low[u] = min( low[u], low[v] );
        if( !p && chk > 1 || p && low[v] >= pre[u] ) art[u] = true;
        if( low[v] >= pre[u] ) {
            ccs.emplace_back( vi() );
            ccs.back().emplace_back( u );
            while( ccs.back().back() != v ) ccs.back().emplace_back( s.top() ), s.pop();
        }
    } else if( v != p ) low[u] = min( low[u], pre[v] );
}

void gen_bct() {
    g.clear(), g.emplace_back( vi() );
    for( int i = 1 ; i <= n ; i++ ) if( art[i] ) {
        cut[id[i] = g.size()] = true;
        g.emplace_back( vi() );
    }
    for( vi &cc : ccs ) {
        g.emplace_back( vi() );
        for( int v : cc ) {
            if( art[v] ) g[id[v]].emplace_back( (int)g.size()-1 ), g[(int)g.size()-1].emplace_back( id[v] );
            else id[v] = (int)g.size() - 1;
        }
    }
}

void init_lca( int u, int p ) {
    dep[u] = dep[p] + 1, lca[0][u] = p, dp[u] = dp[p] + cut[u];
    for( int i = 1 ; i <= 18 ; i++ ) lca[i][u] = lca[i-1][lca[i-1][u]];
    for( int v : g[u] ) if( v != p ) init_lca( v, u );
}

int find_lca( int a, int b ) {
    if( dep[a] < dep[b] ) swap( a, b );
    for( int i = 18 ; i >= 0 ; i-- ) if( dep[lca[i][a]] >= dep[b] ) a = lca[i][a];
    if( a == b ) return a;
    for( int i = 18 ; i >= 0 ; i-- ) if( lca[i][a] != lca[i][b] ) a = lca[i][a], b = lca[i][b];
    return lca[0][a];
}

int main()
{
    scanf("%d %d %d",&n,&m,&q);
    g.resize( n + 1 );
    for( int i = 1, a, b ; i <= m ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    find_component( 1, 0 );
    gen_bct();
    init_lca( 1, 0 );
    for( int i = 1, a, b ; i <= q ; i++ ) {
        scanf("%d %d",&a,&b);
        a = id[a], b = id[b];
        if( a == b ) {
            printf("1\n");
            continue ;
        }
        int c = find_lca( a, b );
        int ans = dp[a] + dp[b] - dp[c] - dp[lca[0][c]] - 1;
        ans += !cut[a] + !cut[b];
        printf("%d\n",ans);
    }
    return 0;
}