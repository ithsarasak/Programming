#include<bits/stdc++.h>

using namespace std;

vector< int > g[100010];
int i, n, k, t, dp[100010], maxi = 0;
int main()
{
    scanf("%d %d %d",&n,&k,&t);
    for( int i = 0 ; i < k ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        g[t].push_back( f );
    }
    for( int i = 1 ; i <= n ; i++ ){
        dp[i] = dp[i - 1] + 1;
        for( int j = 0 ; j < g[i].size() ; j++ ){
            dp[i] = min( dp[i] , dp[g[i][j]] + 1 );
        }
        //printf("%d ",dp[i]);
    }
    printf("%d\n",dp[n]);
    if( dp[n] <= t ){
        printf("1");
        return 0;
    }
    else{
        printf("0 ");
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( dp[i] <= t && maxi < i ){
            maxi = i;
        }
    }
    printf("%d",maxi);
    return 0;
}
