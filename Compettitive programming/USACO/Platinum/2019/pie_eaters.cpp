#include <bits/stdc++.h>

using namespace std;

const int N = 310;
long long dp[N][N], mx[N][N][N];
int n, m;

long long solve( int l, int r ) {
    long long &ret = dp[l][r];
    if( ret != -1 ) return ret;
    ret = 0;
    for( int i = l ; i < r ; i++ ) ret = max( ret, solve( l, i ) + solve( i+1, r ) );
    for( int i = l; i <= r ; i++ ) if( mx[i][l][r] ) {
        long long now = mx[i][l][r];
        if( l <= i-1 ) now += solve( l, i-1 );
        if( i + 1 <= r ) now += solve( i + 1, r );
        ret = max( ret, now );
    }
    return ret;
}

int main() 
{
    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);
    memset( dp, -1, sizeof dp );
    scanf("%d %d", &n, &m);
    for( int i = 1, l, r ; i <= m ; i++ ) {
        long long w;
        scanf("%lld %d %d",&w,&l,&r);
        for( int j = l ; j <= r ; j++ ) mx[j][l][r] = max( mx[j][l][r], w );
    }
    for( int k = 1 ; k <= n ; k++ ) for( int len = 1 ; len <= n ; len++ ) for( int i = 1, j = len ; j <= n ; i++, j++ ) if( i <= k && k <= j ) {
        if( i < n ) mx[k][i][j] = max( mx[k][i][j], mx[k][i+1][j] );
        if( j ) mx[k][i][j] = max( mx[k][i][j], mx[k][i][j-1] );
    }
    solve( 1, n );
    printf("%lld\n", dp[1][n]);
    return 0;
}