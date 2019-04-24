#include <bits/stdc++.h>

using namespace std;

const int N = 510;
char s[N];
int dp[N][N], n;

int solve( int l, int r ) {
    if( dp[l][r] != -1 ) return dp[l][r];
    if( l == r ) return dp[l][r] = 1;
    if( l > r ) return dp[l][r] = 0;
    dp[l][r] = 1 + solve( l + 1, r );
    for( int i = l + 1 ; i <= n ; i++ ) if( s[l] == s[i] ) dp[l][r] = min( dp[l][r], solve( l + 1, i - 1 ) + solve( i, r ) );
    return dp[l][r];
}

int main() 
{
    memset( dp, -1, sizeof dp );
    scanf("%d %s",&n,&s[1]);
    solve( 1, n );
    printf("%d",dp[1][n]);
    return 0;
}