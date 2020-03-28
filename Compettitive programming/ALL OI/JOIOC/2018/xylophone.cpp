#include <bits/stdc++.h>
#include "xylophone.h"

using namespace std;

const int N = 5e3 + 10;
int a[N], df[N], st[N], mul = 1, mn, mx, pmn, pmx;

void solve( int n ) {
    for( int i = 1 ; i < n ; i++ ) df[i+1] = query( i, i + 1 );
    for( int i = 2 ; i < n ; i++ ) {
        int dif = query( i-1, i+1 );
        if( dif == df[i] + df[i+1] ) st[i] = 1;
        else st[i] = -1;
    }
    pmx = 1, pmn = 1;
    for( int i = 2 ; i <= n ; i++ ) {
        a[i] = a[i-1] + ( mul * df[i] );
        mul *= st[i];
        if( a[i] > mx ) mx = a[i], pmx = i;
        if( a[i] < mn ) mn = a[i], pmn = i;
    }
    if( pmn > pmx ) {
        for( int i = 1 ; i <= n ; i++) a[i] *= -1;
        swap( mn, mx );
        mn *= -1, mx *= -1;
    }
    for( int i = 1 ; i <= n ; i++ ) answer( i, a[i] + -1*mn + 1 );
}
