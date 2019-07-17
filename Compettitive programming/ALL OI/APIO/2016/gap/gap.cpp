#include "gap.h"
#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> ans;
long long findGap( int T, int N ) {
    long long ret = 0;
    n = ( long long )N;
    long long l = 0, r = 1e18, mn, mx;
    if( T == 1 ) {
        for( int i = 0 ; i < ( n + 1 ) / 2 ; i++ ) {
            MinMax( l, r, &mn, &mx );
            ans.emplace_back( mn );
            if( mn != mx ) ans.emplace_back( mx );
            l = mn + 1, r = mx - 1;
        }
        sort( ans.begin(), ans.end() );
        for( int i = 0 ; i < ( int )ans.size() - 1 ; i++ ) ret = max( ret, ans[i+1] - ans[i] );
        return ret;
    }
    MinMax( 0, 1e18, &l, &r );
    long long seg = ( r - l ) / ( n - 1 );
    ans.emplace_back( l );
    for( long long i = 0 ; i < n - 1 ; i++ ) {
        long long L = l + 1 + i * seg, R;
        if( i == n - 2 ) R = r;
        else R = l + ( i + 1 ) * seg;
        MinMax( L, R, &mn, &mx );
        if( mn != -1 && mx != -1 ) ans.emplace_back( mn ), ans.emplace_back( mx );
    } 
    sort( ans.begin(), ans.end() );
    for( int i = 0 ; i < ( int )ans.size() - 1 ; i++ ) ret = max( ret, ans[i+1] - ans[i] );
    return ret;
}
