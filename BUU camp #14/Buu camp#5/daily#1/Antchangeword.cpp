#include<bits/stdc++.h>

using namespace std;
int q, dp[1010][1010];
char w1[1010], w2[1010];
int main()
{
    scanf("%d",&q);
    while( q-- ){
        memset( dp, 0, sizeof dp );
        scanf("%s",w1 + 1);
        scanf("%s",w2 + 1);
        int len1 = strlen( w1 + 1 );
        int len2 = strlen( w2 + 1 );
        for( int i = 1 ; i <= len1 ; i++ ){
            dp[i][0] = i;
        }
        for( int i = 1 ; i <= len2 ; i++ ){
            dp[0][i] = i;
        }
        for( int i = 1 ; i <= len1 ; i++ ){
            for( int j = 1 ; j <= len2 ; j++ ){
                if( w1[i] == w2[j] ){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min( dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1] ) ) + 1;
                }
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
}
