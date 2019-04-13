#include<bits/stdc++.h>

using namespace std;
int n;
int ma[250][250], dp[250][250];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            scanf("%d",&ma[i][j]);
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            dp[i][j] = max( dp[i-1][j-1] + ma[i][j], max( dp[i-1][j], dp[i][j-1] ) );
        }
    }
    printf("%d",dp[n][n]);
    return 0;
}
