#include<bits/stdc++.h>

using namespace std;
long long dp[10010] ,n;
int main()
{
    dp[0] = 1;
    scanf("%lld",&n);
    for( long long i = 1 ; i <= n ; i++ ){
        for( long long j = 1 ; j <= i ; j++ ){
            dp[i] += dp[j - 1] * dp[i - j];
            dp[i] %= 909091;
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
