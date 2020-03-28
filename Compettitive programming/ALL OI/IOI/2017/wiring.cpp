#include <bits/stdc++.h>
#include "wiring.h"
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

const int N = 2e5 + 10;
vector<pii> vec;
long long seg[2][N<<2], dp[N], n, sumr[N], suml[N], lenl[N], lenr[N], pre[N], pos[N];
vector<long long> plug[2];

void update( int t, int pos, long long val, int l = 1, int r = n, int idx = 1 ) {
    if( l == r ) return void( seg[t][idx] = val );
    int mid = l + r >> 1;
    if( pos <= mid ) update( t, pos, val, l, mid, idx<<1 );
    else update( t, pos, val, mid + 1, r, idx<<1|1);
    seg[t][idx] = min( seg[t][idx<<1], seg[t][idx<<1|1] );
}

long long query( int t, int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    if( ll > rr ) return 1e18;
    if( l > rr || r < ll ) return 1e18;
    if( l >= ll && r <= rr ) return seg[t][idx];
    int mid = l + r >> 1;
    return min( query( t, ll, rr, l, mid, idx<<1 ), query( t, ll, rr, mid + 1, r, idx<<1|1 ) );
}

long long min_total_length( vector<int> R, vector<int> B ) {
    fill( seg[0], seg[0] + 4*N, 1e18 );
    fill( dp, dp + N, 1e18 );
    n = R.size() + B.size();
    for( int i = 0 ; i < R.size() ; i++ ) plug[0].emplace_back( ( long long )R[i] );
    for( int i = 0 ; i < B.size() ; i++ ) plug[1].emplace_back( ( long long )B[i] );
    vec.emplace_back( -1e12, -1e12 ), vec.emplace_back( 1e12, 1e12 );
    for( int i : R ) vec.emplace_back( i, 0 );
    for( int i : B ) vec.emplace_back( i, 1 );
    sort( vec.begin(), vec.end() );
    for( int i = 1 ; i <= n ; i++ ) {
        if( vec[i].y == vec[i-1].y ) {
            lenl[i] = lenl[i-1] + 1;
            pre[i] = pre[i-1];
            suml[i] = suml[i-1] + vec[i].x; 
        }
        else {
            lenl[i] = 1;
            pre[i] = i;
            suml[i] = vec[i].x;
        }
    }
    for( int i = n ; i >= 1 ; i-- ) {
        if( vec[i].y == vec[i+1].y ) {
            lenr[i] = lenr[i+1] + 1;
            pos[i] = pos[i+1];
            sumr[i] = sumr[i+1] + vec[i].x; 
        }
        else {
            lenr[i] = 1;
            pos[i] = i;
            sumr[i] = vec[i].x;
        }
    }
    dp[0] = 0;
    for( int i = 1 ; i <= n ; i++ ) {
        int c = vec[i].y, o = vec[i].y^1;
		int idx = lower_bound( plug[o].begin(), plug[o].end(), vec[i].x ) - plug[o].begin();
		if( idx != plug[o].size() ) dp[i] = min( dp[i], dp[i-1] + plug[o][idx] - vec[i].x );
		if( idx ) dp[i] = min( dp[i], dp[i-1] + vec[i].x - plug[o][idx-1] );
        if( pre[i] != 1 ) {
            int l = pre[pre[i]-1];
            long long mx = vec[pre[i]-1].x;
            dp[i] = min( dp[i], query( 0, max( ( long long )l, pre[i] - lenl[i] ), pre[i]-1 ) + suml[i] - 1ll * lenl[i] * mx );
			dp[i] = min( dp[i], query( 1, l, pre[i] - lenl[i] - 1 ) + suml[i] - vec[pre[i]].x*lenl[i] );
		}
        update( 0, i, dp[i-1] - sumr[i] + lenr[i] * vec[pos[i]].x );
        update( 1, i, dp[i-1] - sumr[i] + vec[pos[i]+1].x*lenr[i] );
    }
    return dp[n];
}