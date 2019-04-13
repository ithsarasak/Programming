#include <bits/stdc++.h>

using namespace std;
int n, k, dp[3300][3300], va[3300], ans = 3e6;
void op( int i )
{
    for( int j = 2 ; j < k ; j++ ){
        dp[i][j] = min( dp[i][j], dp[i][j-1] );
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&va[i]);
    }
    for( int i = 1 ; i <= k ; i++ ){
        for( int j = 1 ; j < i ; j++ ){
            dp[i][j] = va[i] + va[i-j];
        }
        op( i );
    }
    for( int i = k + 1 ; i <= n ; i++ ){
        for( int j = 1 ; j < k ; j++ ){
            dp[i][j] = va[i] + dp[i-j][k-j];
        }
        op( i );
    }
    int i = n, j = k-1;
    while( i >= n - k + 2 ){
        ans = min( ans, dp[i][j] );
        i--, j--;
    }
    printf("%d",ans);
    return 0;
}