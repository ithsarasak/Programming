#include <bits/stdc++.h>
#include "game.h"

using namespace std;

const int N = 15e2 + 10;
int cnt[N];
void initialize( int n ) {}

int hasEdge( int u, int v ) { 
    if( u < v ) swap( u, v );
    cnt[u]++;
    if( cnt[u] == u ) return 1;
    else return 0;
}