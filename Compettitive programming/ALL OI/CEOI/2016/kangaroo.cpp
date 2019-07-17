#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int mod = 1e9 + 7;    
int n, s, e;
long long dp[N][N];

long long solve( int i, int j ) {
    if( dp[i][j] != -1 ) return dp[i][j];
    if( j == 0 ) return dp[i][j] = 0;
    if( i == 1 ) return dp[i][j] = j == 1 ? 1 : 0;
    if( i == s || i == e ) return dp[i][j] = ( solve( i-1, j-1 ) + solve( i-1, j ) ) % mod;
    return dp[i][j] = ( solve( i-1, j+1 ) * j + solve( i-1, j-1 ) * ( j - ( i > s ? 1 : 0 ) - ( i > e ? 1 : 0 ) ) ) % mod;
}
int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%d %d %d",&n,&s,&e);
    printf("%lld",solve( n, 1 ));
    return 0;
}