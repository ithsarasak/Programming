#include <bits/stdc++.h>
#include "genlib.h"
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int gen;
  int x = atoi( argv[1] );
  int a = atoi( argv[2] );
  if( x == 1 ) gen = 1000;
  else gen = 1000000;
  int n = rnd.next( 1, gen );
  printf("%d\n",n);
  for( int i = 1 ; i <= n ; i++ ) {
      int a = rnd.next( 1, 9999 );
      int b = 10000 - a;
      printf("%d %d\n",a,b);
  }
}