#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;
int n, st[N], dp[N], ind[N], child;
vector<int> g[N];

int dfs( int now, int p ) {
    if( ind[now] == 1 ) {
        child++;
        return dp[now] = 1;
    }
    int mi = 1e9, sum = 0;
    for( int u : g[now] ) if( u != p ) {
        int z = dfs( u, now );
        mi = min( mi, z ), sum += z;
    }
    if( st[now] ) return dp[now] = mi;
    else return dp[now] = sum;
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&st[i]);
    for( int i = 2, t ; i <= n ; i++ ) {
        scanf("%d",&t);
        ind[i]++, ind[t]++;
        g[i].emplace_back( t ), g[t].emplace_back( i );
    }
    dfs( 1, 0 );
    printf("%d",child-dp[1]+1);
    return 0;
}