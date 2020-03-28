#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 5e4+10;
const int K = 6;

int k, n, m, o, dp[N][K][17][K], all;
int main()
{
    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < K ; j++ ) for( int x = 0 ; x < 17 ; x++ ) for( int y = 0 ; y < K ; y++ ) dp[i][j][x][y] = INF;
    scanf("%d %d %d %d",&k,&n,&m,&o);
    for( int i = 1 ; i <= m ; i++ ) {
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        dp[a/k][a%k][0][b%k] = c;
    }
    all = n / k;
    for( int z = 1 ; z < 16 ; z++ ) for( int i = 0 ; i < all ; i++ )  for( int x = 0 ; x < k ; x++ ) for( int y = 0 ; y < k ; y++ ) for( int j = 0 ; j < k ; j++ ) {
        if( i + (1<<(z-1)) <= all ) dp[i][x][z][y] = min( dp[i][x][z][y], dp[i][x][z-1][j] + dp[i+(1<<(z-1))][j][z-1][y] );
        //if( !i ) printf("%d ", dp[i][x][z][y] );
    }
    for( int i = 0 ; i < o ; i++ ) {
        int a, b;
        scanf("%d %d",&a,&b);
        if( a/k >= b/k ) {
            printf("-1\n");
            continue ;
        }
        int f = a%k, t = b%k;
        int ret[K];
        for( int j = 0 ; j < k ; j++ ) ret[j] = dp[a/k][f][0][j];
        a = a/k+1, b = b/k;
        for( int j = 15 ; j >= 0 ; j-- ) if( a + ( 1 << j ) <= b ) {
            int nret[K];
            for( int x = 0 ; x < K ; x++ ) nret[x] = INF;
            for( int x = 0 ; x < k ; x++ ) for( int y = 0 ; y < k ; y++ ) nret[y] = min( nret[y], ret[x] + dp[a][x][j][y] );
            a += ( 1 << j );
            for( int z = 0 ; z < k ; z++ ) ret[z] = nret[z];
        }
        printf("%d\n",ret[t] == INF ? -1 : ret[t]);
    }
    return 0;
}