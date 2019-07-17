#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
int n, m;
long long fen[N][N], fen2[2*N][N], base[N][N];

void up( int r, int c, long long va ) {
    for( int i = r ; i < N ; i += ( i & -i ) ) for( int j = c ; j < N ; j += ( j & -j ) ) fen[i][j] += va;
}

void up2( int r, int c, long long va ) {
    for( int i = r ; i < 2*N ; i += ( i & -i ) ) for( int j = c ; j < N ; j += ( j & -j ) ) fen2[i][j] += va;
}

long long query( int r1, int c1, int r2, int c2 ) {
    long long ret = 0, ret2 = 0;
    for( int i = r2 ; i > 0 ; i -= ( i & -i ) ) for( int j = c2 ; j > 0 ; j -= ( j & -j ) ) ret += fen[i][j];
    for( int i = r2 ; i > 0 ; i -= ( i & -i ) ) for( int j = c1 - 1 ; j > 0 ; j -= ( j & -j ) ) ret2 += fen[i][j];
    return ret - ret2;
}

long long query2( int r1, int c1, int r2, int c2 ) {
    long long ret = 0, ret2 = 0, ret3 = 0, ret4 = 0;
    for( int i = r2 ; i > 0 ; i -= ( i & -i ) ) for( int j = c2 ; j > 0 ; j -= ( j & -j ) ) ret += fen2[i][j];
    for( int i = r1 - 1 ; i > 0 ; i -= ( i & -i ) ) for( int j = c2 ; j > 0 ; j -= ( j & -j ) ) ret2 += fen2[i][j];
    for( int i = r2 ; i > 0 ; i -= ( i & -i ) ) for( int j = c1 - 1 ; j > 0 ; j -= ( j & -j ) ) ret3 += fen2[i][j];
    for( int i = r1 - 1 ; i > 0 ; i -= ( i & -i ) ) for( int j = c1 - 1 ; j > 0 ; j -= ( j & -j ) ) ret4 += fen2[i][j];
    return ret - ret2 - ret3 + ret4;
}

int findrow( int r, int c ) { return r + c - 1; }

int findcolumn( int r, int c ) {
    int rowinit = min( n, findrow( r, c ) );
    //printf("findcolumn : %d %d  = %d %d\n",r,c,rowinit,rowinit - r + 1);
    return rowinit - r + 1 + max( 0, findrow( r, c ) - n );
}

int main()
{
    scanf("%d %d",&n,&m);
    while( m-- ) {
        int t, a, b, c;
        scanf("%d %d %d %d",&t,&a,&b,&c);
        if( t == 1 ) {
            long long allsum = query( 1, b - c + 1, a, b );
            int rr = findrow( a - 1, b - c + 1 ), cc = findcolumn( a - 1, b - c + 1 );
            int r2 = findrow( a, b - c + 1 ), c2 = findcolumn( a, b - c + 1 );
            int r3 = findrow( a - c + 1, b ), c3 = findcolumn( a - c + 1, b );
            //printf("%d %d %d %d %d %d\n",rr,cc,r2,c3,r3,c3);
            long long half = query2( r2, c2, r3, c3 ) / 2;
            long long trash = query2( 1, cc, rr, cc + c - 1 );
            printf("%lld\n",allsum - trash - half );
        }
        else {
            long long va = ( long long )c;
            int row = findrow( a, b ), column = findcolumn( a, b );
            up( a, b, -1*base[a][b] ), up2( row, column, -1*base[a][b] );
            base[a][b] = va;
            up( a, b, base[a][b] ), up2( row, column, base[a][b] );
        }
    }
    return 0;
}