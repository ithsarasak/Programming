#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int n, m, k, col[N];
long long dp[N][40], ans;
vector<int> g[N];

long long solve( int u, int bit ) {
    long long &ret = dp[u][bit];
    if( ret != -1 ) return ret;
    ret = 1;
    for( int v : g[u] ) if( ( 1<<col[v] ) & bit ) ret += solve( v, bit - ( 1<<col[v] ) );
    return ret;
}

int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&col[i]);
        col[i]--;
    }
    for( int i = 1, a, b ; i <= m ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    for( int i = 1 ; i <= n ; i++ ) ans += solve( i, (1<<k)-(1<<col[i])-1 ) - 1;
    printf("%lld",ans);
    return 0;
}