#include <bits/stdc++.h>

using namespace std;

void print( char c, int x ) {
    printf("%c %d\n",c,x);
    fflush( stdout );
    return ;
}

int chk( int num ) {
    for( int i = 1 ; i <= 27 ; i++ ) if( num == ( 1 << i ) - 1 ) return 0;
    return 1;
}

int main()
{
    int x, y;
    while( 1 ) {
        scanf("%d %d",&x,&y);
        if( x == -1 ) return 0;
        int a = log2( x ), b = log2( y );
        if( chk( x ) && chk( y ) ) {
            if( x > 2 ) {
                if( chk( x - 1 ) ) print( 'H', x - 1 );
                else print( 'H', x - 2 );
            }
            else if ( y > 2 ) {
                if( chk( y - 1 ) ) print( 'V', y - 1 );
                else print( 'V', y - 2 );
            }
            else {
                if( x != 1 ) print( 'H', x - 1 );
                else print( 'V', y - 1 );
            }
        }
        else if( chk( x ) ) print( 'H', ( 1<<a ) - 1 );
        else if( chk( y ) ) print( 'V', ( 1<<b ) - 1 );
    }
}