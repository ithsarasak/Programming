#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int sq = 320;
int n, m, qu, chk[N], mx[N];
vector<int> g[N];
vector<pii> ans[N];
pii all[N];

void pre() {
    memset( mx, -1, sizeof mx );
    for( int i = 1 ; i <= n ; i++ ) ans[i].emplace_back( 0, i );
    for( int u = 1 ; u <= n ; u++ ) for( int v : g[u] ) {
        for( pii x : ans[u] ) mx[x.y] = max( mx[x.y], x.x + 1 );
        for( pii x : ans[v] ) mx[x.y] = max( mx[x.y], x.x );
        int p1 = 0, p2 = 0, ret = 0;
        while( p1 < ans[u].size() && p2 < ans[v].size() ) {
            if( ans[u][p1].x + 1 > ans[v][p2].x ) all[++ret] = pii( ans[u][p1].x + 1, ans[u][p1].y ), p1++;
            else all[++ret] = ans[v][p2++];
        }
        while( p1 < ans[u].size() ) all[++ret] = pii( ans[u][p1].x + 1, ans[u][p1].y ), p1++;
        while( p2 < ans[v].size() ) all[++ret] = ans[v][p2++];
        ans[v].clear();
        for( int i = 1 ; i <= ret ; i++ ) if( all[i].x == mx[all[i].y] ) {
            ans[v].emplace_back( all[i] );
            mx[all[i].y] = -1;
        }
        //printf("\n");
        while( ans[v].size() > sq ) ans[v].pop_back();
    }
}

int push( vector<int>&nope, int q ) {
    int dp[N];
    fill( dp, dp+N, -1e9 );
    for( int u = 1 ; u <= n ; u++ ){
        if( chk[u] && dp[u] == -1e9 ) continue;
        dp[u] = max( dp[u], 0 );
        for( int v : g[u] ) dp[v] = max( dp[v], dp[u] + 1 );
    }
    return dp[q] == -1e9 ? -1 : dp[q];
}

int main()
{
    scanf("%d %d %d",&n,&m,&qu);
    for( int i = 1, s, e ; i <= m ; i++ ) {
        scanf("%d %d",&s,&e);
        g[s].emplace_back( e );
    }
    pre();
    while( qu-- ) {
        int q, temp;
        vector<int> no;
        scanf("%d %d",&q,&temp);
        if( temp == 0 ) { printf("%d\n",ans[q][0].x); continue ; }
        for( int i = 1, a ; i <= temp ; i++ ) {
            scanf("%d",&a);
            chk[a] = 1;
            no.emplace_back( a );
        }
        if( temp >= sq ) printf("%d\n",push( no, q ) );
        else {
            int ch = 0;
            for( pii i : ans[q] ) if( !chk[i.y] ) { printf("%d\n",i.x); ch = 1; break; }
            if( !ch ) printf("-1\n");
        }
        for( int i : no ) chk[i] = 0;
    }
    return 0;
}