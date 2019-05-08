#include<bits/stdc++.h>

using namespace std;
int sum, dp[100100], n, k;
int main()
{
    scanf("%d %d",&n,&k);
    if( k == 1 ){
        printf("1");
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    sum = 2;
    for( int i = 2 ; i <= n ; i++ ){
            //printf("%d ",sum);
        if( i <= k ){
            dp[i] = sum;
            sum *= 2;
            sum %= 2009;
        }
        else{
            sum -= dp[i-k-1];
            sum += 2009;
            sum %= 2009;
            dp[i] = sum;
            sum *= 2;
            sum %= 2009;
        }
    //printf("%d %d\n",sum,dp[i]);
    }
    printf("%d",dp[n]);
    return 0;
}
