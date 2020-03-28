#include "testlib.h"

using namespace std;

int main( int argc, char *argv[] ){
    registerValidation( argc, argv );
    int n = inf.readInt( 0, 100000, "n" );
    inf.readEoln();
    for( int i = 1 ; i <= n ; i++ ) {
        long long x = inf.readLong( 0, 1000000000000000, "x" );
        inf.readEoln();
    }
    inf.readEof();
}