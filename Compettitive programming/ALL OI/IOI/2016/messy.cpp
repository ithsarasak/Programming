#include <bits/stdc++.h>
#include "messy.h"

using namespace std;

vector<int> vec, p;
int n;
string element( int l, int r, int idx ) {
    string s( n, '1' );
    for( int i = l ; i <= r ; i++ ) s[i] = '0';
    s[idx] = '1';
    return s;
}

string question( vector<int> &v, int idx ) {
    string s( n, '1' );
    for( int i : v ) s[i] = '0';
    s[idx] = '1';
    return s;
}

void add( int l = 0, int r = n - 1 ) {
    if( l == r ) return ;
    int mid = l + r >> 1;
    for( int i = l ; i <= mid ; i++ ) add_element( element( l, r, i ) );
    add( l, mid ), add( mid + 1, r );
}

void solve( vector<int> &v, int l = 0, int r = n - 1 ) {
    if( l == r ) return void( p[v[0]] = l );
    vector<int> le, ri;
    for( int i : v ) {
        bool side = check_element( question( v, i ) );
        if( side ) le.emplace_back( i );
        else ri.emplace_back( i );
    }
    int mid = l + r >> 1;
    solve( le, l, mid ), solve( ri, mid + 1, r );
} 

vector<int> restore_permutation( int N, int w, int r ) {
    n = N;
    add(), compile_set();
    for( int i = 0 ; i < n ; i++ ) vec.emplace_back( i );
    p = vector<int> ( n, 0 );
    solve( vec );
    return p;
}