#include <bits/stdc++.h>

using namespace std;

int pre( int now, int p ) {
    dep[now] = dep[p] + 1;
    pii mx = ( -1, 0 );
    for( int i : g[now] ) if( i != p ) {
        int x = pre( i );
        mx = max( mx, pii( x, i ) );
        sz[now] += x;
    }
    spi[now] = mx.y;
    return sz[now];
}

void hld( ) {
    for( int i = 1, idx ; i <= n ; i++ ) if( i != spi[i] ) {
        for( int j = i ; j != -1 ; j = spi[j] ) 
            rot[j] = i, pos[j] = ++idx;
    }
    for( int i = 1 ; i <= n ; i++ ) update( pos[i], i );
}
int main()
{
    return 0;
}