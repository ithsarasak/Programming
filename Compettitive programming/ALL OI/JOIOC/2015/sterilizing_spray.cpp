#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, q;
long long seg[N<<2], k;

void update( int pos, long long val, int l = 1, int r = n, int idx = 1 ) {
    if( l > pos || r < pos ) return ;
    if( l == r ) return void( seg[idx] = val );
    int m = l + r >> 1;
    if( pos <= m ) update( pos, val, l, m, idx<<1 );
    else update( pos, val, m+1, r, idx<<1|1 );
    seg[idx] = seg[idx<<1] + seg[idx<<1|1];
}

void spray( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    if( k == 1 ) return ;
    if( !seg[idx] ) return ;
    if( l > rr || r < ll ) return ;
    if( l == r ) return void( seg[idx] /= k );
    int m = l + r >> 1;
    spray( ll, rr, l, m, idx<<1 ), spray( ll, rr, m+1, r, idx<<1|1 );
    seg[idx] = seg[idx<<1] + seg[idx<<1|1];
}

long long query( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    if( l > rr || r < ll ) return 0;
    if( l >= ll && r <= rr ) return seg[idx];
    int m = l + r >> 1;
    return query( ll, rr, l, m, idx<<1 ) + query( ll, rr, m+1, r, idx<<1|1 );
}

int main()
{
    scanf("%d %d %lld",&n,&q,&k);
    for( int i = 1 ; i <= n ; i++ ) {
        long long a;
        scanf("%lld",&a);
        update( i, a );
    }
    while( q-- ) {
        int t, a, b;
        scanf("%d %d %d",&t,&a,&b);
        if( t == 1 ) update( a, ( long long )b );
        else if( t == 2 ) spray( a, b );
        else printf("%lld\n",query( a, b ));
    }
    return 0;
}