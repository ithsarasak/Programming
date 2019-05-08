#include <bits/stdc++.h>
#include "robots.h"
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

vector<pii> all;

int putaway( int a, int b, int t, int x[], int y[], int w[], int s[] ) {
    for( int i = 0 ; i < t ; i++ ) all.emplace_back( pii( w[i], s[i] ) );
    sort( all.begin(), all.end() ), sort( x, x + a ), sort( y, y + b );
    auto check = [&]( int mid ) {
        priority_queue<pii> q;
        vector<bool> chk( t );
        int j = 0;
        for( int i = 0 ; i < a ; i++ ) {
            int now = 0;
            while( j < t && all[j].x < x[i] ) q.emplace( pii( all[j].y, j ) ), j++;
            while( !q.empty() && now < mid ) chk[q.top().y] = 1, q.pop(), now++;
        }
        for( ; j < t ; j++ ) q.emplace( pii( all[j].y, j ) );
        for( int i = b - 1 ; i >= 0 ; i-- ) {
            int now = 0;
            while( now < mid && !q.empty() ) {
                pii temp = q.top(); q.pop();
                if( temp.x < y[i] ) now++, chk[temp.y] = 1;
            }
        }
        for( int i = 0 ; i < t ; i++ ) if( !chk[i] ) return false;
        return true;
    };
    int l = 0, r = t;
    while( l < r ) {
        int mid = ( l + r ) >> 1;
        if( check( mid ) ) r = mid;
        else l = mid + 1;
    }
    if( !check( l ) ) return -1;
    else return l;
}