#include<bits/stdc++.h>
#include "grader.h"
#include "cluedo.h"

using namespace std;
 
void Solve() {
    int a[3] = {1, 1, 1};
    while( 1 ) {
        int t = Theory( a[0], a[1], a[2] );
        if ( t == 0 ) return;
        else a[t - 1]++;
    }
}