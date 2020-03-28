#include <bits/stdc++.h>
#include "library.h"

using namespace std;
int n;
int ask( vector<int> v ) {
    if( !(int)v.size() ) return 0;
    vector<int> vec(n);
    for( int &x : vec ) x = 0;
    for( int x : v ) vec[x-1] = 1;
    return Query( vec );
}
 
void eras( vector<int> &v, int i ) {
    vector<int>::iterator it;
    for( it = v.begin() ; it != v.end() ; it++ ) if( *it == i ) break;
    v.erase( it );
}
 
void Solve( int n_ ) 
{
    n = n_;
    if( n == 1 ) {
        Answer({1});
        return ;
    }
    vector<int> ans(n);
    vector<int> left;
    for( int i = 1 ; i <= n ; i++ ) left.emplace_back( i );
    for( int i = 1 ; i <= n ; i++ ) {
        vector<int> v;
        for( int j = 1 ; j <= n ; j++ ) if( i != j ) v.emplace_back( j );
        if( ask( v ) == 1 ) {
            ans[0] = i;
            eras( left, i );
            break ;
        }
    }
    for( int i = 1 ; i < n ; i++ ) {
        int l = 0, r = left.size() - 1; 
        while( l < r ) {
            int m = l + r >> 1;
            vector<int> vv;
            for( int j = 0 ; j <= m ; j++ ) vv.emplace_back( left[j] );
            for( int j = 0 ; j < i ; j++ ) vv.emplace_back( ans[j] );  
            int a = vv.size() - ask( vv );
            eras( vv, ans[i-1] );
            int b = vv.size() - ask( vv );
            if( a - b == 2 || ( i == 1 && a-b == 1 ) ) r = m;
            else l = m + 1;
        }
        ans[i] = left[l];
        eras( left, ans[i] );
    }
    Answer( ans );
}