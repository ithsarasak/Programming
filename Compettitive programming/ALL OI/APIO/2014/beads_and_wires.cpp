#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 2e5 + 10;

int dp[N][2][2], va[N], n;
vector<pii> g[N];

void dfs( int u, int p ) {
    int cnt = g[u].size();
    if( u != 1 ) cnt--;
    if( cnt == 0 ) return void( dp[u][0][1] = dp[u][1][0] = dp[u][1][1] = -1e9 );
    int temp = -1e9;
    pii mx01( -1e9, 0 ), mx02( -1e9, 0 ), mx11( -1e9, 0 ), mx12( -1e9, 0 );
    vector<pii> vec, vec2;
    for( pii x : g[u] ) if( x.x != p ) {
        int v = x.x;
        dfs( v, u );
        int mx = max( dp[v][0][0], dp[v][0][1] + x.y );
        pii now1( dp[v][0][0] + x.y - mx, v ), now2( dp[v][1][0] + x.y - mx, v ); 
        dp[u][0][0] += mx, dp[u][0][1] += mx, dp[u][1][1] += mx;
        temp = max( temp, -1*mx + max( dp[v][1][0] , dp[v][1][1] + x.y ) );
        if( mx01.x < now1.x ) swap( mx01, now1 );
        if( mx02.x < now1.x ) swap( mx02, now1 );
        if( mx11.x < now2.x ) swap( mx11, now2 );
        if( mx12.x < now2.x ) swap( mx12, now2 );
    }
    dp[u][1][0] = dp[u][0][0] + temp;
    if( cnt > 0 ) dp[u][0][1] += mx01.x, dp[u][1][1] += mx11.x;
    if( cnt > 1 ) {
        dp[u][1][0] = max( dp[u][1][0], dp[u][0][0] + mx01.x + mx02.x );
        if( mx01.y == mx11.y ) dp[u][1][0] = max( dp[u][1][0], dp[u][0][0] + max( mx01.x + mx12.x, mx11.x + mx02.x ) );
        else dp[u][1][0] = max( dp[u][1][0], dp[u][0][0] + mx01.x + mx11.x );
    }
    //printf("%d : 00: %d 01: %d 10: %d 11: %d\n",u,dp[u][0][0],dp[u][0][1],dp[u][1][0],dp[u][1][1]);
}

int main()
{
    scanf("%d",&n);
    for( int i = 1, a, b, c ; i < n ; i++ ) {
        scanf("%d %d %d",&a,&b,&c);
        g[a].emplace_back( b, c ), g[b].emplace_back( a, c );
    }
    dfs( 1, 0 );
    printf("%d",max( dp[1][1][0], dp[1][0][0] ));
    return 0;
}