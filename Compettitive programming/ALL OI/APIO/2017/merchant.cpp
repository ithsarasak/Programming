#include <bits/stdc++.h>

using namespace std;

const int N = 110;
long long d[N][N], g[N][N], cost[N][N], b[N][N*10], s[N][N*10];
int n, m, k;

int check( long long p ) {
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= n ; j++ ) 
        g[i][j] = d[i][j] * p - cost[i][j];
    for( int t = 1 ; t <= n ; t++ ) for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= n ; j++ ) if( i != j ) {
        g[i][j] = min( g[i][j], g[i][t] + g[t][j] );
    }
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= n ; j++ ) if( i != j && g[i][j] + g[j][i] <= 0 ) return 1;
    return 0;
}

int main()
{
    for( int i = 1 ; i < N ; i++ ) for( int j = 1 ; j < N ; j++ ) d[i][j] = 1e9;
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ) 
        for( int j = 1 ; j <= k ; j++ ) 
            scanf("%lld %lld",&b[i][j],&s[i][j]);
    for( int i = 1, u, v ; i <= m ; i++ ) {
        long long di;
        scanf("%d %d %lld",&u,&v,&di);
        d[u][v] = min( d[u][v], di );
    } 
    for( int i = 1 ; i <= n ; i++ ) d[i][i] = 0LL;
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= n ; j++ ) 
        for( int l = 1 ; l <= k ; l++ ) if( b[i][l] != -1LL && s[j][l] != -1LL ) {
            cost[i][j] = max( cost[i][j], s[j][l] - b[i][l] );
        }
    for( int t = 1 ; t <= n ; t++ ) for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= n ; j++ ) {
        d[i][j] = min( d[i][j], d[i][t] + d[t][j] );
    }
    long long l = 0, r = 1e9;
    while( r - l > 1 ) {
        long long mid = ( l + r ) / 2;
        if( check( mid ) ) l = mid;
        else r = mid;
    }
    printf("%lld",l);
    return 0;
}