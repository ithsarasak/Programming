#include<bits/stdc++.h>

using namespace std;
long long q, r, c, ans, ma[1010][1010], dp[1010][1010][5];
int main()
{
    scanf("%lld",&q);
    while( q-- ){
        memset( dp, 0, sizeof dp );
        ans = 0;
        scanf("%lld %lld",&r,&c);
        for( int i = 1 ; i <= r ; i++ ){
            for( int j = 1 ; j <= c ; j++ ){
                scanf("%lld",&ma[i][j]);
                for(int k=0;k<3;k++){
                    dp[i][j][0] = max( dp[i][j][0], max( dp[i-1][j][k] , dp[i][j-1][k] ) );
                }
                dp[i][j][1] = max( dp[i-1][j][0] , dp[i][j-1][0] ) + ma[i][j];
                dp[i][j][2] = max( dp[i-1][j][1] , dp[i][j-1][1] ) + ma[i][j];
                ans = max( ans, max( dp[i][j][2], max( dp[i][j][1], dp[i][j][0] ) ) );
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
