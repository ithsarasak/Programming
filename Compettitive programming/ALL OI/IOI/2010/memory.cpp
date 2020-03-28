#include <bits/stdc++.h>
#include "grader.h"
#include "memory.h"

using namespace std;

vector<int> pos[30];

void play(){
    for( int i = 1 ; i <= 25 ; i++ ) {
        pos[faceup( 2*i )-'A'].emplace_back( 2*i );
        pos[faceup( 2*i - 1 )-'A'].emplace_back( 2*i - 1 );
    }
    for( int i = 0 ; i < 25 ; i++ ) faceup( pos[i][0] ), faceup( pos[i][1] );
}