#include <bits/stdc++.h>
#define iii tuple<int, int, int>
 
using namespace std;
 
const int N = 405;
 
int n;
int cnt[3], dp[N][N][N][3];
char s[N];
vector<iii> vec[3];
 
int cost( int c, iii a, iii b ) {
    int ret = 0;
    if( c != 0 ) ret += max( 0, get<0>(b) - get<0>(a) );
    if( c != 1 ) ret += max( 0, get<1>(b) - get<1>(a) );
    if( c != 2 ) ret += max( 0, get<2>(b) - get<2>(a) );
    return ret;
}

int main()
{
    scanf("%d %s",&n,s);
    for( int i = 0, f ; i < n ; i++ ) {
        if( s[i] == 'R') f = 0;
        else if( s[i] == 'G' ) f = 1;
        else f = 2;
        cnt[f]++, vec[f].emplace_back( cnt[0], cnt[1], cnt[2] );
    }
    for( int i = 0 ; i <= cnt[0] ; i++ ) for( int j = 0 ; j <= cnt[1] ; j++ ) for( int k = 0 ; k <= cnt[2] ; k++ ) {
        if( !i && !j && !k ) continue;
        dp[i][j][k][0] = dp[i][j][k][1] = dp[i][j][k][2] = 1e9;
        if( i ) dp[i][j][k][0] = min( dp[i-1][j][k][1], dp[i-1][j][k][2] ) + cost( 0, vec[0][i-1], { i, j, k } );
        if( j ) dp[i][j][k][1] = min( dp[i][j-1][k][0], dp[i][j-1][k][2] ) + cost( 1, vec[1][j-1], { i, j, k } );
        if( k ) dp[i][j][k][2] = min( dp[i][j][k-1][0], dp[i][j][k-1][1] ) + cost( 2, vec[2][k-1], { i, j, k } );
    } 
    int ans = 1e9;
    for( int i = 0 ; i < 3 ; i++ ) ans = min( ans, dp[cnt[0]][cnt[1]][cnt[2]][i] );
    if( ans == 1e9 ) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}