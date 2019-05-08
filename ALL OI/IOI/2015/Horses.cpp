#include <bits/stdc++.h>
#include "horses.h"

using namespace std;

const int N = 1 << 19;
const int mod = 1e9 + 7;

struct node{
    double log;
    long long va;
    node() : log( 0 ), va( 1 ) { }
    node( double log, long long va ) : log( log ), va( va ) { }
    friend node operator+( const node &a, const node &b ) {
        node ret;
        ret.log = a.log + b.log;
        ret.va = ( a.va * b.va ) % mod;
        return ret;
    }
    friend bool operator<( const node &a, const node &b ) {
        return make_pair( a.log, a.va ) < make_pair( b.log, b.va );
    }
} seg[N<<1], lz[N<<1];

int n, x[N], y[N];
node a[N];

void build( int l = 1, int r = n, int now = 1 ) {
    if( l == r ) return void( seg[now] = a[l-1] );
    int mid = ( l + r ) >> 1;
    build( l, mid, now << 1 ), build( mid + 1, r, now << 1 | 1 );
    seg[now] = seg[now<<1] < seg[now<<1|1] ? seg[now<<1|1] : seg[now<<1];
    return ;
}

void push( int now, int l, int r ) {
    seg[now] = seg[now] + lz[now];
    if( l != r ) {
        lz[now<<1] = lz[now<<1] + lz[now];
        lz[now<<1|1] = lz[now<<1|1] + lz[now];
    }
    lz[now] = node( 0, 1 );
    return ;
}

void update( int ll, int rr, node k, int l = 1, int r = n, int now = 1 ) {
    push( now, l, r );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz[now] = lz[now] + k;
        push( now, l, r );
        return ;
    }
    int mid = ( l + r ) >> 1;
    update( ll, rr, k, l, mid, now << 1 ), update( ll, rr, k, mid + 1, r, now << 1 | 1 );
    seg[now] = seg[now<<1] < seg[now<<1|1] ? seg[now<<1|1] : seg[now<<1]; 
}

int init( int N, int X[], int Y[] ) {
    n = N;
    node cul( 0, 1 );
    for( int i = 0 ; i < n ; i++ ) {
        x[i] = X[i], y[i] = Y[i];
        cul = cul + node( ( double )log2( x[i] ), x[i] );
        a[i] = cul + node( ( double )log2( y[i] ), y[i] );
    }
    build();
    return seg[1].va;
}

long long modpower( long long base, long long power ) {
    long long ret = 1;
    for( ; power ; power >>= 1 ) {
        if( power & 1 ) ret = ( ret * base ) % mod;
        base = ( base * base ) % mod;
    }
    return ret;
}

int updateX( int pos, int val ) {
    double ll = ( double )log2( val ) - ( double )log2( x[pos] );
    long long vc = ( long long )( 1ll * val * modpower( x[pos], mod - 2 ) ) % mod;
    x[pos] = val;
    update( pos + 1, n, node( ll, vc ) );
    return seg[1].va;
}

int updateY( int pos, int val ) {
    double ll = ( double )log2( val ) - ( double )log2( y[pos] );
    long long vc = ( long long )( 1ll * val * modpower( y[pos], mod - 2 ) ) % mod;
    y[pos] = val;
    update( pos + 1, pos + 1, node( ll, vc ) );
    return seg[1].va;
}

// int main()
// {
//     int n, m, x[N], y[N];
//     scanf("%d %d",&n,&m);
//     for( int i = 0 ; i < n ; i++ ) scanf("%d",&x[i]);
//     for( int i = 0 ; i < n ; i++ ) scanf("%d",&y[i]);
//     cout << init( n, x, y );
// }