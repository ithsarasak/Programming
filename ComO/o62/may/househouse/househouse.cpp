#include <bits/stdc++.h>
#include "househouse.h"

using namespace std;

int c, m;
int main()
{
    househouse_init( c, m );
    if( c >= m ) {
        for( int i = 0 ; i <= m ; i++ ) househouse_pay( 1 );
    }
    else if( c * 2 >= m ) {
        int dif = ( m - c ) >> 1;
        for( int i = 0 ; i < dif ; i++ ) househouse_pay( 1 );
        househouse_pay( c );
    }
    else {
        for( int i = 0 ; i < ( c >> 1 ) ; i++ ) househouse_pay( 1 );
        househouse_pay( c );
    }
}