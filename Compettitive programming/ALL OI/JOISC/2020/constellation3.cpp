#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 2e5 + 10;

vector<int> peak[N];
int par[N], l[N], r[N], chk[N], n, k;
long long seg[4*N], lz[4*N], sum;
vector<pii> starx[N], stary[N];

int find( int x ) { return x == par[x] ? x : par[x] = find( par[x] ); }

void merge( int a, int b ) {
    a = find( a ), b = find( b );
    if( a == b ) return ;
    par[b] = a, l[a] = min( l[a], l[b] ), r[a] = max( r[a], r[b] );
}

void push( int l, int r, int idx ) {
    if( lz[idx] != 0 ) {
        seg[idx] += lz[idx];
        if( l != r ) lz[idx<<1] += lz[idx], lz[idx<<1|1] += lz[idx];
        lz[idx] = 0;
    }
}

void update( int ll, int rr, long long va, int l = 1, int r = n, int idx = 1 ) {
    push( l, r, idx );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz[idx] += va, push( l, r, idx );
        return ;
    }
    int mid = l + r >> 1;
    update( ll, rr, va, l, mid, idx<<1 ), update( ll, rr, va, mid+1, r, idx<<1|1 );
    seg[idx] = max( seg[idx<<1], seg[idx<<1|1] );
}

long long query( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    push( l, r, idx );
    if( l > rr || r < ll ) return -1e9;
    if( l >= ll && r <= rr ) return seg[idx];
    int mid = l + r >> 1;
    return max( query( ll, rr, l, mid, idx<<1 ), query( ll, rr, mid+1, r, idx<<1|1 ) );
}

int main()
{
    iota( par, par+N, 0 ), iota( l, l+N, 0 ), iota( r, r+N, 0 );
    scanf("%d",&n);
    for( int i = 1, temp ; i <= n ; i++ ) {
        scanf("%d",&temp);
        peak[temp+1].emplace_back( i );
    }
    scanf("%d",&k);
    for( int i = 1, x, y, c ; i <= k ; i++ ) {
        scanf("%d %d %d",&x,&y,&c);
        sum += ( long long )c;
        starx[x].emplace_back( y, c );
    }
    for( int i = 1 ; i <= n ; i++ ) if( !starx[i].empty() ){
        sort( starx[i].begin(), starx[i].end() );
        int now = 0;
        for( pii t : starx[i] ) if( t.y > now ) {
            stary[t.x].emplace_back( i, t.y - now );
            now = t.y;
        }
    }
    for( int i = 1 ; i <= n+1 ; i++ ) {
        for( int x : peak[i] ) {
            //printf("%d %d\n",i,x);
            long long val = 0, var = 0;
            int parl = find( x-1 ), parr = find( x+1 );
            if( x > 1 && chk[x-1] ) val += query( l[parl], r[parl] );
            if( x < n && chk[x+1] ) var += query( l[parr], r[parr] );
            if( x > 1 && chk[x-1] ) update( l[parl], r[parl], var );
            if( x < n && chk[x+1] ) update( l[parr], r[parr], val );
            update( x, x, val + var );
            if( x > 1 && chk[x - 1] ) merge( x - 1, x );
            if( x < n && chk[x + 1] ) merge( x, x + 1 );
            chk[x] = 1;
        }
        for( pii x : stary[i] ) update( x.x, x.x, ( long long )x.y );
    }
    printf("%lld",sum-seg[1]);
    return 0;
}