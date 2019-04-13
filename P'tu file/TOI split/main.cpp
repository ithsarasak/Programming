#include<stdio.h>

int cases, i , j , k;
bool dp[101][60001];
int main()
{
    scanf("%d",&cases);
    for( i = 0 ; i < cases ; i++ ){
        int n;
        int sum = 0;
        scanf("%d",&n);
        int score[n];
        for( j = 0 ; j < n ; j++ ){
            scanf("%d",&score[j]);
            sum += score[j];
        }
        for( j = 0 ; j <= n ; j++ ){
            dp[j][0] = true;
        }

        for( j = 1 ; j <= sum ; j++ ){
            dp[0][j] = false;
        }

        for ( j = 1 ; j <= n ; j++ ){
            for ( k = 1 ; k <= sum ; k++ ){
                if( score[j - 1] <= k ){
                    if( dp[ j - 1 ][ k ] < dp[ j - 1 ][ k - score[j - 1]] ){
                        dp[j][k] = dp[ j - 1 ][ k - score[j - 1]];
                    }
                    else{
                        dp[j][k] = dp[ j - 1 ][ k ];
                    }
                }
                else{
                    dp[j][k] = dp[ j - 1 ][ k ];
                }
            }
        }

        int diff;
        for( j = sum / 2 ; j >= 0 ; j-- ){
            if( dp[n][j] == true ){
                diff = sum - ( 2 * j );
                break;
            }
        }
        printf("Case #%d: %d\n",i + 1 ,diff);
    }
    return 0;
}
