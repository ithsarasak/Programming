#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n, a[N];
long long dp[2][N], mod = 1e6 + 7, ans;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
    for( int i = 1 ; i <= n ; i++ ) dp[n%2][i] = 1;
    for( int i = n-1 ; i >= 1 ; i-- ) {
        dp[i%2][0] = dp[(i+1)%2][1];
        for( int j = 1 ; j <= i ; j++ ) dp[i%2][j] = ( dp[(i+1)%2][j+1] + dp[i%2][j-1] ) % mod;
        //printf("%d %lld\n",a[i+1]-1,dp[i%2][a[i+1]-2]);
        if( a[i+1] == 1 ) continue ;
        ans = ( ans + dp[i%2][a[i+1]-2] ) % mod;
    }
    printf("%lld",( ans+1 ) % mod);
    return 0;
}