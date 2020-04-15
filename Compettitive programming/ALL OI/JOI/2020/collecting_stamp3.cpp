#include <bits/stdc++.h>

using namespace std;

const int N = 2e2 + 10;
int n, l, pos[N], t[N], ans;
long long dp[N][N][N][2];

long long d( int a, int b ) { return min( abs( pos[b] - pos[a] ), l - abs( pos[b] - pos[a] ) ); }
int main()
{
    scanf("%d %d",&n,&l);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&pos[i]);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&t[i]);
    pos[n+1] = l;
    for( int k = 0 ; k <= n ; k++ ) for( int i = 0 ; i <= n ; i++ ) for( int j = n+1 ; j >= 1 ; j-- ) {
        if( j <= i || ( !k && !i && j == n+1 ) ) continue;
        dp[i][j][k][0] = dp[i][j][k][1] = 1e18;
        if( i ) dp[i][j][k][0] = min( dp[i][j][k][0], min( dp[i-1][j][k][0] + d( i-1, i ), dp[i-1][j][k][1] + d( j, i ) ) );
        if( j != n+1 ) dp[i][j][k][1] = min( dp[i][j][k][1], min( dp[i][j+1][k][0] + d( i, j ), dp[i][j+1][k][1] + d( j+1, j ) ) );
        if( k ) {
            if( i ) {
                long long T = min( dp[i-1][j][k-1][0] + d( i-1, i ), dp[i-1][j][k-1][1] + d( j, i ) );
                if( T <= t[i] ) dp[i][j][k][0] = min( dp[i][j][k][0], T );
            }
            if( j <= n ) {
                long long T = min( dp[i][j+1][k-1][0] + d( i, j ), dp[i][j+1][k-1][1] + d( j+1, j ) );
                if( T <= t[j] ) dp[i][j][k][1] = min( dp[i][j][k][1], T );
            }
        }
        if( dp[i][j][k][0] != 1e18 || dp[i][j][k][1] != 1e18 ) ans = k;
    }
    printf("%d",ans);
    return 0;
}