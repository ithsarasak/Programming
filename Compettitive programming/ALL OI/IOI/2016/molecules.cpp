#include <bits/stdc++.h>
#include "molecules.h"
#define pii pair<int, int>
#define x first 
#define y second

using namespace std;

vector<pii> v;
vector<int> ans;

vector<int> find_subset( int l, int u, vector<int> w ) {
    for( int i = 0 ; i < w.size() ; i++ ) v.emplace_back( pii( w[i], i ) );
    sort( v.begin(), v.end() );
    int ll = 0, rr = 0;
    long long sum = 0;
    while( ll < w.size() ) {
        while( rr < w.size() && sum < l ) sum += ( long long ) v[rr++].x;
        if( sum >= l && sum <= u ) {
            for( int i = ll ; i < rr ; i++ ) ans.emplace_back( v[i].y );
            return ans;
        }
        sum -= ( long long ) v[ll++].x;
    }
    return {};
}