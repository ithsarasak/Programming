#include "testlib.h"

using namespace std;

int main( int argc, char *argv[] ){
    registerValidation( argc, argv );
    int n = inf.readInt( 1, 1000000, "n" );
    inf.readEoln();
    for( int i = 1 ; i <= n ; i++ ) {
        int x = inf.readInt( 1, 10000, "x" );
        inf.readSpace();
        int y = inf.readInt( 1, 10000, "y" );
        inf.readEoln();
    }
    inf.readEof();
}