#include<bits/stdc++.h>

using namespace std;

int n, i, t, dp[500010], mark[500010];
vector< int > v[500010];
int ans[2];
int dfs( int u )
{
    mark[u] = 1;
    dp[u] = 1;
    for( int j = 0 ; j < v[u].size() ; j++ ){
        if( mark[v[u][j]] == 0 ){
            int f = v[u][j];
            dfs( f );
            dp[u] = max( dp[u] , 1 + dp[f] );
            //printf("%d\n",dp[u]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for( i = 1 ; i < n ; i++ ){
        scanf("%d",&t);
        v[i].push_back( t );
        v[t].push_back( i );
    }
    mark[0] = 1;
    for( i = 0 ; i < v[0].size() ; i++ ){
        dfs( v[0][i] );
        if( dp[v[0][i]] > ans[0] ){
            ans[1] = ans[0];
            ans[0] = dp[v[0][i]];
        }
        else if( dp[v[0][i]] > ans[1] ){
            ans[1] = dp[v[0][i]];
        }
    }
    printf("%d",ans[0] + ans[1]);
    return 0;
}
