#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long n, m, rai[N][N], mem[N][N][N][N], sum[N][N];

long long qs( int i, int j, int k, int l ) { return sum[k][l] - sum[i-1][l] - sum[k][j-1] + sum[i-1][j-1]; }

long long mcm( int sti, int stj, int endi, int endj ) {
    if( mem[sti][stj][endi][endj] != -1 ) return mem[sti][stj][endi][endj];
    if( sti == endi && stj == endj ) return mem[sti][stj][endi][endj] = 0;
    long long mi = 1e18;
    for( int i = sti ; i < endi ; i++ ) mi = min( mi, qs( sti, stj, endi, endj ) + mcm( sti, stj, i, endj ) + mcm( i + 1, stj, endi, endj ) );
    for( int i = stj ; i < endj ; i++ ) mi = min( mi, qs( sti, stj, endi, endj ) + mcm( sti, stj, endi, i ) + mcm( sti, i + 1, endi, endj ) );
    return mem[sti][stj][endi][endj] = mi;
}

int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) scanf("%lld",&rai[i][j]);

    for( int i = 0 ; i < 55 ; i++ ) for( int j = 0 ; j < 55 ; j++ ) 
        for( int k = 0 ; k < 55 ; k++ ) for( int l = 0 ; l < 55 ; l++ ) 
                    mem[i][j][k][l] = -1;   

    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) sum[i][j] = rai[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

    printf("%lld",mcm( 1, 1, n, m ));
    return 0;
}

