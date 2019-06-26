#include <bits/stdc++.h>

using namespace std;

int m, n, a, b, c, d;


void build( int i, int l, int r, int now = 1 ) {
    if( l == r ) {
        seg[i][now] = findsum( i + 1, l + 1, i + d, l + c );
    }
}
int main()
{
    scanf("%d %d %d %d %d %d",&m,&n,&a,&b,&c,&d);
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = 1 ; j <= m ; j++ ) {
            scanf("%d",&val[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + val[i][j];
        }
    }
    for( int i = 1 ; i <= n - b - 1 ; i++ ) {
        build( i, 1, m - a - 1 );
    }
    for( int i = 2 ; i <= n - b ; i++ ) {
        for( int j = 2 ; j <= m - a ; j++ ) {

        }
    }
    return 0;
}