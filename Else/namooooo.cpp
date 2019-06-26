#include <bits/stdc++.h>

using namespace std;

int table[8][8], ans, mark[20], cnt;

int cal( int i, int j ) {
    return table[i][j] * 1 + table[i][j+1] * 2 + table[i+1][j] * 4 + table[i+1][j+1] * 8;
}

void solve( int r, int c, int bit ) {
    if( r == 5 && c == 5 ) {
        table[r][c] = bit;
        memset( mark, 0, sizeof mark );
        // for( int i = 1 ; i <= 2 ; i++ ) {
        //     for( int j = 1 ; j <= 2 ; j++ ) {
        //         printf("%d ",table[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        //cnt++;
        for( int i = 1 ; i <= 4 ; i++ ) for( int j = 1 ; j <= 4 ; j++ ) mark[cal( i, j )]++;
        int cc = 0;
        for( int i = 0 ; i <= 15 ; i++ ) if( !mark[i] ) cc = 1;
        if( !cc ) ans++;
        return ;
    }
    table[r][c] = bit;
    int gr = r, gc = c;
    if( c == 5 ) gc = 1, gr++;
    else gc++;
    solve( gr, gc, 0 ), solve( gr, gc, 1 );
    return ;
}
int main()
{
    solve( 1, 1, 0 );
    solve( 1, 1, 1 );
    printf("%d" ,ans);
    return 0;
}