#include<stdio.h>

using namespace std;

int i,j, maxs;
int dp[10100], num[10100];
int amount;
int main()
{
    scanf("%d",&amount);
    for( i = 1 ; i <= amount ; i++ ){
        scanf("%d",&num[i]);
    }
    dp[1] = 1;
    maxs = 1;
    for( i = 2 ; i <= amount ; i++ ){
        for( j = 1 ; j < i ; j++ ){
            if( num[j] < num[i] && dp[j] + 1 > dp[i] ){
                dp[i] = dp[j] + 1;
            }
        }
        if( dp[i] == 0 ){
            dp[i]++;
        }
        if( maxs < dp[i] ){
            maxs = dp[i];
        }
    }
    printf("%d",maxs);
    return 0;
}
