#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10;
int n, m, cnt[N][N][2], ans;
char s[N][N];

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%s",&s[i][1]);
    }
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = 1 ; j <= m ; j++ ) {
            if( s[i][j-1] == 'R' && s[i][j] == 'G' && s[i][j+1] == 'W' ) cnt[i][j][0] = 1;
            if( s[i-1][j] == 'R' && s[i][j] == 'G' && s[i+1][j] == 'W' ) cnt[i][j][1] = 1;
        }
    }
    for( int now = 2 ; now <= n + m ; now++ ) {
        int dp[N][3], lst;
        fill_n( dp[0], N*3, 0 );
        for( int i = 1, j = now-i ; i <= n ; i++, j-- ) {
            if( j < 1 || j > m ) continue ;
            dp[i][0] = max({ dp[i-1][0], dp[i-1][1], dp[i-1][2] });
            if( cnt[i][j][0] ) dp[i][1] = max( dp[i-1][0], dp[i-1][1] ) + 1;
            if( cnt[i][j][1] ) dp[i][2] = max( dp[i-1][0], dp[i-1][2] ) + 1;
            lst = i;
        }
        ans += max({ dp[lst][0], dp[lst][1], dp[lst][2] });
    }
    printf("%d",ans);
    return 0;
}