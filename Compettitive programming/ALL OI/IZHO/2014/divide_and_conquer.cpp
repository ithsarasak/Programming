#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
long long inf = 1e9;
long long n, t[N*4];
long long h[N], sum[N], gold[N], ans;
vector<long long> coord;

int get( int x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + 1; }

void build( int l = 1, int r = coord.size(), int idx = 1 ) {
    t[idx] = inf;
    if( l == r ) return ;
    int mid = l + r >> 1;
    build( l, mid, idx<<1 ), build( mid+1, r, idx<<1|1 );
}

void update( int x, long long va, int l = 1, int r = coord.size(), int idx = 1 ) {
    if( l > x || r < x ) return ;
    if( l == r ) return void( t[idx] = min( t[idx], va ) );
    int mid = l + r >> 1;
    update( x, va, l, mid, idx<<1 ), update( x, va, mid+1, r, idx<<1|1 );
    t[idx] = min( t[idx<<1], t[idx<<1|1] );
    return ;
}

long long query( int ll, int rr, int l = 1, int r = coord.size(), int idx = 1 ) {
    if( l > rr || r < ll ) return inf;
    if( l >= ll && r <= rr ) return t[idx];
    int mid = l + r >> 1;
    return min( query( ll, rr, l, mid, idx<<1 ), query( ll, rr, mid+1, r, idx<<1|1 ) );
}

int main()
{
    scanf("%lld",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%lld %lld %lld",&h[i],&gold[i],&sum[i]);
        sum[i] += sum[i-1], gold[i] += gold[i-1];
        coord.emplace_back( sum[i-1] - h[i] );
    }
    sort( coord.begin(), coord.end() );
    coord.resize( unique( coord.begin(), coord.end() ) - coord.begin() );
    build();
    /*for( long long i : coord ) printf("%lld ",i);
    printf("\n");*/
    for( int i = 1 ; i <= n ; i++ ) {
        int idx = upper_bound( coord.begin(), coord.end(), sum[i] - h[i] ) - coord.begin(), idx2 = get( sum[i-1] - h[i] );
        update( idx2, ( long long )i );
        long long qu = query( 1, idx );
        ans = max( ans, gold[i] - gold[qu - 1] );
    }
    printf("%lld",ans);
    return 0;
}