#include <bits/stdc++.h>
#include "genlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi( argv[1] );
  if( n == 0 ) printf("1\n0\n");
  else if( n == 1 ) {
    int one = rnd.next( 1000, 100000 );
    int x = ( 1000000 / one );
    printf("%d\n",one);
    for( int i = 1 ; i <= one ; i++ ) printf("%d\n",rnd.next( 0, x ) );
  }
  else {
    int one = rnd.next( 1000, 100000 );
    printf("%d\n",one);
    for( int i = 1 ; i <= one ; i++ ) printf("%lld\n",rnd.next( 0LL, 1000000000000000 ) );
  }
}