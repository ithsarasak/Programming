#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

struct data {
    long long m, c;
    int idx;
    data() { }
    data( long long m, long long c, int idx ) : m( m ), c( c ), idx( idx ) { } 
};

struct convex_hull {
    vector<data> vec;
    int ptr = 0;
    bool del( data l3, data l2, data l1 ) { return ( l1.c - l3.c ) * ( l3.m - l2.m ) <= ( l2.c - l3.c ) * ( l3.m - l1.m ); }
    void add( data d ) {
        while( vec.size() > 2 && del( vec[(int)vec.size()-2], vec.back(), d ) ) vec.pop_back();
        while( !vec.empty() && vec.back().m == d.m && vec.back().c <= d.c ) vec.pop_back();
        vec.emplace_back( d );
    }
    long long get( long long x, int pos ) { return vec[pos].m * x + vec[pos].c; }
    pll query( long long x ) {
        if( ptr >= vec.size() ) ptr = vec.size() - 1;
        while( ptr + 1 < vec.size() && get( x, ptr ) <= get( x, ptr + 1 ) ) ptr++;
        return pll( get( x, ptr ), vec[ptr].idx );
    }
    void clear() {
        vec.clear();
        ptr = 0;
    }
};

convex_hull hull;
int n, k, s[210][N];
long long dp[2][N], sum[N];

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%lld",&sum[i]);
        sum[i] += sum[i-1];
    }
    for( int i = 1 ; i <= k ; i++ ) {
        hull.clear();
        for( int j = 1 ; j <= n ; j++ ) {
            hull.add( data( sum[j-1], -1*sum[j-1]*sum[j-1] + dp[(i-1)%2][j-1], j-1 ) );
            tie( dp[i%2][j], s[i][j] ) = hull.query( sum[j] );
        }
    }
    printf("%lld\n",dp[k%2][n]);
    for( int i = k, z = n ; i > 0 ; i-- ) printf("%d ",z = s[i][z]);
    return 0;
}