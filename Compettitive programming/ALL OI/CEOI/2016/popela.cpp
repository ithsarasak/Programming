#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e4 + 10;
const int K = 55;
int dp[K][N], last[N][K], t, n, s, va[N], mi[K];
int main()
{
    memset( dp, 127, sizeof dp );
    scanf("%d %d %d",&n,&t,&s);
    for( int i = 1 ; i <= t ; i++ ) {
        scanf("%d",&va[i]);
        va[i] += va[i-1];
    }
    for( int i = 0 ; i < n ; i++ ) {
        char score[N];
        scanf("%s",score);
        for( int j = 1 ; j <= t ; j++ ) {
            if( score[j-1] == '1' ) last[j][i] = last[j-1][i];
            else last[j][i] = j;
        }
    }
    for( int i = 1 ; i <= t ; i++ ) {
        last[i][n] = i;
        sort( last[i], last[i] + 1 + n );
    }
    dp[0][0] = 0;
    for( int i = 1 ; i <= s ; i++ ) {
        fill( mi, mi + K, 2000000000 );
        for( int j = 1 ; j <= t ; j++ ) {
            for( int k = 0 ; k <= n ; k++ ) {
                for( int l = last[j-1][k] ; l < last[j][k] ; l++ ) mi[k] = min( mi[k], dp[i-1][l] - va[l] * k );
                if( last[j][k] > 0 ) dp[i][j] = min( dp[i][j], mi[k] + va[j] * k );
            }

        }
        printf("%d\n",dp[i][t]);
    }
    return 0;
}