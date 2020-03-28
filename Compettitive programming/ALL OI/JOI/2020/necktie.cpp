#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, a[N], b[N], temp[N];
int seg[2][N<<2];

void update( int t, int pos, int val, int l = 1, int r = n, int idx = 1 ) {
    if( l == r ) return void( seg[t][idx] = val );
    int m = l + r >> 1;
    if( pos <= m ) update( t, pos, val, l, m, idx<<1 );
    else update( t, pos, val, m + 1, r, idx<<1|1 );
    seg[t][idx] = max( seg[t][idx<<1], seg[t][idx<<1|1] );
    return ;
}

int query( int t, int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    //printf("t ll rr l r %d %d %d %d %d\n",t,ll,rr,l,r);
    if( rr < ll ) return -1e9;
    if( l > rr || r < ll ) return -1e9;
    if( l >= ll && r <= rr ) return seg[t][idx];
    int m = l + r >> 1;
    return max( query( t, ll, rr, l, m, idx<<1 ), query( t, ll, rr, m+1, r, idx<<1|1 ) );
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n + 1 ; i++ ) {
        scanf("%d",&a[i]);
        temp[i] = a[i];
    }
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&b[i]);
    sort( a+1, a+2+n ), sort( b+1, b+1+n );
    for( int i = 1 ; i <= n ; i++ ) update( 0, i, max( a[i]-b[i], 0 ) );
    for( int i = 2 ; i <= n+1 ; i++ ) update( 1, i-1, max( a[i]-b[i-1], 0 ) );
    for( int i = 1 ; i <= n+1 ; i++ ) {
        int idx = lower_bound( a, a+2+n, temp[i] ) - a;
        //printf("%d ",idx);
        //printf("%d\n",query( 0, 1, i-1) );
        printf("%d ",max( query( 0, 1, idx-1 ), query( 1, idx, n ) ) );
    }
    return 0;
}