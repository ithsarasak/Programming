#include<bits/stdc++.h>
using namespace std;
const int inf = 1<<21;
int n, w[610][610], i, j;
int dp[650];
int main()
{
    scanf("%d", &n);
    for( i = 1 ; i <= 2 * n ; i++ )
        for( j = 1 ; j <= 2 * n ; j++ )
            scanf ("%d",&w[i][j]);
    dp[2 * n] = 0;
    for( i = 2 * n - 1 ; i >= 2 ; i-- ){
        dp[i] = inf;
        for( j = i + 1 ; j <= 2 * n ; j++ )
            dp[i] = min( dp[i] , dp[j] + w[j][i] );
    }
    printf("%d\n", dp[2]);
    return 0;
}

