#include<bits/stdc++.h>

using namespace std;
int dp[200010], n, k, stairs[200010], maxl, q;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        for( int i = 0 ; i <= 200000 ; i++ ){
            dp[i] = 0;
            stairs[i] = 0;
        }
        scanf("%d %d",&n,&k);
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&stairs[i]);
        }
        dp[1] = 1;
        maxl = 1;
        for( int i = 2 ; i <= n ; i++ ){
            dp[i] = dp[i - 1];
            while( stairs[i] - stairs[maxl] > k ){
                maxl++;
            }
            dp[i] -= dp[maxl - 1];
            dp[i] += dp[i - 1];
            dp[i] += 95959;
            dp[i] %= 95959;
        }
        printf("%d\n",( dp[n] - dp[n - 1] + 95959 )% 95959);
    }
    return 0;
}
