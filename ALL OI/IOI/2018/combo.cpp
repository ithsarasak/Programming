#include <bits/stdc++.h>
#include "combo.h"

using namespace std;

string ans = "";
vector<char> c;

string guess_sequence( int n ) {
    if( press( "AB" ) ) {
        if( press( "A" ) ) ans += 'A';
        else ans += 'B'; 
    }
    else {
        if( press( "X" ) ) ans += 'X';
        else ans += "Y";
    }
    if( n == 1 ) return ans;
    if( ans[0] != 'A' ) c.emplace_back( 'A' );
    if( ans[0] != 'B' ) c.emplace_back( 'B' );
    if( ans[0] != 'X' ) c.emplace_back( 'X' );
    if( ans[0] != 'Y' ) c.emplace_back( 'Y' );
    for( int i = 2 ; i < n ; i++ ) {
        string p = ans + c[0] + c[0] + ans + c[0] + c[1] + ans + c[0] + c[2] + ans + c[1];
        int ret = press( p );
        if( ret > i ) ans += c[0];
        else if( ret == i ) ans += c[1];
        else ans += c[2];
    }
    if( press( ans + c[0] ) == n ) ans += c[0];
    else if( press( ans + c[1] ) == n ) ans += c[1];
    else ans += c[2];
    return ans;
}