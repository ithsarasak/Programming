#include<bits/stdc++.h>
#define mod 1000007
using namespace std;
int n, va[600], dp[50010], m;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&va[i]);
    }
    dp[0] = 1;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = m ; j >= va[i] ; j-- ){
            dp[j] += dp[j-va[i]];
            dp[j] %= mod;
        }
        /*for( int j = 0 ; j <= m ; j++ ){
            printf("%d ",dp[j]);
        }
        printf("\n");*/
    }
    printf("%d",dp[m]);
    return 0;
}
