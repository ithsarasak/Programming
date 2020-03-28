#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

struct ss {
    long long mi, sum;
    friend ss operator +( const struct ss &a, const struct ss & b ) {
        ss c;
        c.mi = min( a.mi, b.mi ), c.sum = a.sum + b.sum;
        return c;
    }
}seg[4*N];
int n, q;
long long lz[4*N];

void push( int l, int r, int now ) {
    if( lz[now] == 0 ) return ;
    seg[now].mi += lz[now];
    seg[now].sum += lz[now] * ( r - l + 1 );
    if( l != r ) lz[now<<1] += lz[now], lz[now<<1|1] += lz[now];
    lz[now] = 0;
    return ;
}

void update( int ll, int rr, int va, int l = 1, int r = n, int now = 1 ) {
    push( l, r, now );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz[now] += va;
        push( l, r, now );
        return ;
    }
    int mid = ( l + r ) >> 1;
    update( ll, rr, va, l, mid, now << 1 ), update( ll, rr, va, mid + 1, r, now << 1 | 1 );
    seg[now] = seg[now<<1] + seg[now<<1|1];
    return ;
}

long long querym( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
    push( l, r, now );
    if( l > rr || r < ll ) return 1e18;
    if( l >= ll && r <= rr ) return seg[now].mi;
    int mid = ( l + r ) >> 1;
    return min( querym( ll, rr, l, mid, now << 1 ), querym( ll, rr, mid + 1, r, now << 1 | 1 ) );
}

long long querys( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
    push( l, r, now );
    if( l > rr || r < ll ) return 0LL;
    if( l >= ll && r <= rr ) return seg[now].sum;
    int mid = ( l + r ) >> 1;
    return querys( ll, rr, l, mid, now << 1 ) + querys( ll, rr, mid + 1, r, now << 1 | 1 ); 
}

int main()
{
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    scanf("%d %d",&n,&q);
    for( int i = 1 ; i <= n ; i++ ) {
        long long x;
        scanf("%lld",&x);
        update( i, i, x );
    }
    while( q-- ) {
        char c;
        int f, t;
        scanf(" %c %d %d",&c,&f,&t);
        if( c == 'M' ) printf("%lld\n",querym( f, t ));
        else if( c == 'P' ) {
            long long x;
            scanf("%lld\n",&x);
            update( f, t, x );
        }
        else printf("%lld\n",querys( f, t ));
    }
    return 0;
}