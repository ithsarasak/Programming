#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, q, dif[N], dif2[N], t1[4*N], t2[4*N], x[N], y[N];

int getd( int i, int j ) { return abs( x[i] - x[j] ) + abs( y[i] - y[j] ); }

void up( int x, int ty, int va, int l = 1, int r = n, int idx = 1 ) {
    if( l > x || r < x ) return ;
    if( l == r ) {
        if( !ty ) return void( t1[idx] = va );
        else return void( t2[idx] = va );
    }
    int mid = l + r >> 1;
    up( x, ty, va, l, mid, idx<<1 ), up( x, ty, va, mid+1, r, idx<<1|1 );
    if( !ty ) t1[idx] = t1[idx<<1] + t1[idx<<1|1];
    else t2[idx] = max( t2[idx<<1], t2[idx<<1|1] );
    return ;
}


int query1( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    if( ll > rr ) return 0;
    if( l > rr || r < ll ) return 0;
    if( l >= ll && r <= rr ) return t1[idx];
    int mid = l + r >> 1;
    return query1( ll, rr, l, mid, idx<<1 ) + query1( ll, rr, mid + 1, r, idx<<1|1 );
}

int query2( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    if( ll > rr ) return 0;
    if( l > rr || r < ll ) return -1e9;
    if( l >= ll && r <= rr ) return t2[idx];
    int mid = l + r >> 1;
    return max( query2( ll, rr, l, mid, idx<<1 ), query2( ll, rr, mid+1, r, idx<<1|1 ) );
}

int main()
{
   freopen( "marathon.in", "r", stdin );
    freopen( "marathon.out", "w", stdout );
    scanf("%d %d",&n,&q);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d %d",&x[i],&y[i]);
        if( i > 1 ) {
            dif[i-1] = getd( i-1, i );
            up( i-1, 0, dif[i-1] );
        }
        if( i > 2 ) {
            dif2[i-1] = getd( i-2, i );
            up( i-1, 1, dif[i-2] + dif[i-1] - dif2[i-1] );
        }
    }
    while( q-- ) {
        char c;
        int a, b, d;
        scanf(" %c %d %d",&c,&a,&b);
        if( c == 'Q' ) printf("%d\n",query1( a, b-1 ) - max( query2( a+1, b-1 ), 0 ) );
        else {
            scanf("%d",&d);
            x[a] = b, y[a] = d;
            dif[a-1] = getd( a-1, a ), dif[a] = getd( a, a+1 );
            up( a-1, 0, dif[a-1] ), up( a, 0, dif[a] );
            if( a >= 2 ) up( a, 1, dif[a-1] + dif[a] - dif2[a] );
            if( a <= n-1 ) up( a, 1, dif[a-1] + dif[a] - dif2[a] );
            if( a > 2 ) {
                dif2[a-1] = getd( a-2, a );
                up( a-1, 1, dif[a-2] + dif[a-1] - dif2[a-1] );
            }
            if( a < n-1 ) {
                dif2[a+1] = getd( a, a+2 );
                up( a+1, 1, dif[a] + dif[a+1] - dif2[a+1] );
            }
        }
    }
    return 0;
}