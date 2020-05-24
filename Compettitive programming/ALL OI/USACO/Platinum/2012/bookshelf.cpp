#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

long long l, t1[N*4], t2[N*4], lz[N*4], w[N], h[N], dp[N];
int n;
deque<int> dq;

void push( int l, int r, int idx ) {
    if( !lz[idx] ) return ;
    t2[idx] = lz[idx] + t1[idx];
    if( l != r ) lz[idx<<1] = lz[idx<<1|1] = lz[idx];
    return ;
}

void update( int ty, int ll, int rr, int va, int l = 1, int r = n, int idx = 1 ) {
    if( ty == 2 ) push( l, r, idx );
    if( l > rr || r < ll ) return ;
    if( l == r && ty == 1 ) return void( t1[idx] = va );
    if( l >= ll && r <= rr && ty == 2 ) {
        lz[idx] = va;
        push( l, r, idx );
        return ;
    }
    int mid = l + r >> 1;
    update( ty, ll, rr, va, l, mid, idx<<1 ), update( ty, ll, rr, va, mid+1, r, idx<<1|1 );
    if( ty == 2 ) t2[idx] = min( t2[idx<<1], t2[idx<<1|1] );
    if( ty == 1 ) t1[idx] = min( t1[idx<<1], t1[idx<<1|1] );
    return ;
}

long long query( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    push( l, r, idx );
    //if( ll > rr )
    if( l > rr || r < ll ) return 1e9;
    if( l >= ll && r <= rr ) return t2[idx];
    int mid = l + r >> 1;
    return min( query( ll, rr, l, mid, idx<<1 ), query( ll, rr, mid+1, r, idx<<1|1 ) );
}

int main()
{  
    fill( t1, t1+4*N, 1e9 ), fill( t2, t2+4*N, 1e9 );
    scanf("%d %lld",&n,&l);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld %lld",&h[i],&w[i]);
    for( int i = 1 ; i <= n ; i++ ) w[i] += w[i-1];
    dq.emplace_back( 0 ), update( 1, 1, 1, 0 );
    int now = 1;
    for( int i = 1 ; i <= n ; i++ ) {
        while( dq.size() > 1 && h[dq.back()] <= h[i] ) dq.pop_back();
        update( 2, dq.back() + 1, i, h[i] );
        while( w[i] - w[now-1] > l ) now++;
        dq.emplace_back( i );
        dp[i] = query( now, i );
        printf("%lld ",dp[i]);
        update( 1, i+1, i+1, dp[i] );
    }
    printf("%lld\n",dp[n]);
    return 0;
}