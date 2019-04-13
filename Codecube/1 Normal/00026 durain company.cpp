#include<bits/stdc++.h>

using namespace std;
int n, dp[1000010], maxs;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        int f,t ;
        scanf("%d %d",&f,&t);
        dp[f] += 1;
        dp[t] -= 1;
    }
    for( int i = 1 ; i <= 1000000 ; i++ ){
        dp[i] += dp[i - 1];
        maxs = max( maxs, dp[i] );
    }
    printf("%d",maxs);
    return 0;
}
