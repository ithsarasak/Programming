#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
int n, m, dp[N][N][810], ans;

int main()
{
    scanf("%d %d",&n,&m);
    memset( dp, -127, sizeof dp );
    dp[0][1][0] = dp[1][0][0] = 0;
    for( int i = 1, a ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) {
        scanf("%d",&a);
        int cnt2 = 0, cnt3 = 0;
        while( a % 2 == 0 ) cnt2++, a /= 2;
        while( a % 3 == 0 ) cnt3++, a /= 3;
        for( int k = cnt3 ; k <= 800 ; k++ ) dp[i][j][k] = cnt2 + ( dp[i-1][j][k-cnt3] > dp[i][j-1][k-cnt3] ? dp[i-1][j][k-cnt3] : dp[i][j-1][k-cnt3] ); 
    }
    for( int i = 0 ; i <= 800 ; i++ ) if( dp[n][m][i] >= i ) {
        //printf("%d %d\n",dp[n][m][i],i);
        ans = max( ans, i );
    }
    printf("%d",ans);
    return 0;
}