#include <bits/stdc++.h>

using namespace std;

const int N = 51;
long long dp[N][N][N][N], last1[30][N], last2[30][N], last3[30][N], last4[30][N], last[N][N][N][N];
int len1, len2, len3, len4, q;
char all[5][N];
int main()
{
    scanf("%d",&q);
    while( q-- ) {
        memset( dp, 0, sizeof dp ), memset( last1, 0, sizeof last1 ), memset( last2, 0, sizeof last2 ), memset( last3, 0, sizeof last3 ), memset( last4, 0, sizeof last4 );
        memset( last, 0, sizeof last );
        for( int i = 1 ; i <= 4 ; i++ ) scanf("%s",&all[i][1]);
        len1 = strlen( &all[1][1] ), len2 = strlen( &all[2][1] ), len3 = strlen( &all[3][1] ), len4 = strlen( &all[4][1] );
        for( int i = 1 ; i <= len1 ; i++ ) for( int j = 0 ; j < 26 ; j++ ) {
            if( all[1][i] - 'a' == j ) last1[j][i] = i;
            else last1[j][i] = last1[j][i-1];
        }
        for( int i = 1 ; i <= len2 ; i++ ) for( int j = 0 ; j < 26 ; j++ ) {
            if( all[2][i] - 'a' == j ) last2[j][i] = i;
            else last2[j][i] = last2[j][i-1];
        }
        for( int i = 1 ; i <= len3 ; i++ ) for( int j = 0 ; j < 26 ; j++ ) {
            if( all[3][i] - 'a' == j ) last3[j][i] = i;
            else last3[j][i] = last3[j][i-1];
        }
        for( int i = 1 ; i <= len4 ; i++ ) for( int j = 0 ; j < 26 ; j++ ) {
            if( all[4][i] - 'a' == j ) last4[j][i] = i;
            else last4[j][i] = last4[j][i-1];
        }
        for( int i = 1 ; i <= len1 ; i++ ) for( int j = 1 ; j <= len2 ; j++ )
                for( int k = 1 ; k <= len3 ; k++ ) for( int l = 1 ; l <= len4 ; l++ ) {
                        if( all[1][i] == all[2][j] && all[2][j] == all[3][k] && all[3][k] == all[4][l] ) {
                            int c = all[1][i] - 'a';
                            dp[i][j][k][l] = 2 * dp[i-1][j-1][k-1][l-1] - last[last1[c][i-1]][last2[c][j-1]][last3[c][k-1]][last4[c][l-1]] + 1;
                            last[i][j][k][l] = dp[i][j][k][l] - dp[i-1][j-1][k-1][l-1] + last[last1[c][i-1]][last2[c][j-1]][last3[c][k-1]][last4[c][l-1]]; 
                        }
                        else {
                            dp[i][j][k][l] = ( dp[i-1][j][k][l] + dp[i][j-1][k][l] + dp[i][j][k-1][l] + dp[i][j][k][l-1] ) -
                            ( dp[i-1][j-1][k][l] + dp[i-1][j][k-1][l] + dp[i-1][j][k][l-1] + dp[i][j-1][k-1][l] + dp[i][j-1][k][l-1] + dp[i][j][k-1][l-1] ) +
                            ( dp[i-1][j-1][k-1][l] + dp[i-1][j-1][k][l-1] + dp[i-1][j][k-1][l-1] + dp[i][j-1][k-1][l-1] ) -
                            ( dp[i-1][j-1][k-1][l-1] );
                        }
                }
        printf("%lld\n",dp[len1][len2][len3][len4]);
    }
    return 0;
}