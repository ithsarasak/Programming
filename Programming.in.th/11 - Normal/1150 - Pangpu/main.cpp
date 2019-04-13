#include<bits/stdc++.h>

using namespace std;

int dp[2][60010], i, j, n, pang[1010];
int main()
{
    scanf("%d",&n);
    for( i = 0 ; i < n ; i ++ ){
        scanf("%d",&pang[i]);
    }
    sort( pang , pang + n );
    dp[0][30000] = 1;
    for( i = 0 ; i <= 60000 ; i++ ){
        if( i - 30000 == pang[0] ){
                dp[0][i] = 1;
        }
        else{
            dp[0][i] = 0;
        }
    }
    for( i = 1 ; i < n ; i++ ){
        for( j = 0 ; j <= 60000 ; j++ ){
            dp[0][30000] = 1;
            int temp = j - 30000;
            if( dp[0][j] == 1 ){
                dp[1][j] = 1;
            }
            else if( ( temp + 60001 ) - pang[i] <= 30000 ){
                if( dp[0][( temp + 60001 ) - pang[i] + 30000] == 1 ){
                    dp[1][j] = 1;
                }
                else{
                    dp[1][j] == 0;
                }
            }
            else if( ( temp - 60001 ) - pang[i] >= -30000 ){
                if( dp[0][( temp - 60001 ) - pang[i] + 30000] ){
                    dp[1][j] = 1;
                }
                else{
                    dp[1][j] == 0;
                }
            }
            else if( temp - pang[i] >= -30000 && temp - pang[i] <= 30000 ){
                if( dp[0][temp - pang[i] + 30000] == 1 ){
                    dp[1][j] = 1;
                }
                else{
                    dp[1][j] == 0;
                }
            }
            else{
                dp[1][j] = 0;
            }
        }
        for( j = 0 ; j <= 60000 ; j++ ){
            dp[0][j] = dp[1][j];
        }
    }
    for( i = 60000 ; i >= 0 ; i-- ){
        if( dp[0][i] == 1 ){
            break;
        }
    }
    if( i - 30000 >= 0 )
        printf("%d",i - 30000);
    else
        printf("0");
    return 0;
}
