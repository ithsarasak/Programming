#include "grader.h"
#include <bits/stdc++.h>
 
using namespace std;
 
// int Guess( int now ) {
//     printf("%d\n",now);
//     int ret;
//     scanf("%d",ret);
//     return ret;
// }

int HC( int n ){
    Guess( 1 );
    int l = 1, r = n, prev = 1, ver = 1;
    while( l < r ) {
        if( ver == 0 ) {
            int now = Guess( l );
            int mid = ( l + r ) >> 1;
            if( now == 0 ) return ( prev + l ) / 2;
            else if( now == 1 ) {
                r = ( l + r + 1 ) / 2 - 1;
                prev = l, ver = 0;
            } 
            else {
                l = mid + 1;
                Guess( prev );
            }
        }
        else {
            int now = Guess( r );
            int mid = ( l + r ) >> 1;
            if( now == 0 ) return ( prev + r ) / 2;
            else if( now == 1 ) {   
                l = mid + 1;
                prev = r, ver = 1;
            } 
            else {
                r = ( l + r + 1 ) / 2 - 1;
                Guess( prev );
            }
        }
    }
    return l;
}

// int main() {
//     HC( 100 );
// }