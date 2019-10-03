#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+100;

int seg[4*N], n, ans;

void up( int idx, int va, int l = 1, int r = n, int now = 1 ){
    // printf("l %d r %d idx %d\n",l,r,idx);
    if( l > idx || r < idx || l > r ) return ;
    if( l == r ) return void( seg[now] = min( seg[now], va ) );
    int mid = ( l + r ) >> 1;
    up( idx, va, l, mid, now<<1 ), up( idx, va, mid+1, r, now<<1|1 );
    seg[now] = min( seg[now<<1], seg[now<<1|1] );
    return ;
}

int query( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
    if( l > rr || r < ll || l > r ) return 1e9;
    if( l >= ll && r <= rr ) return seg[now];
    int mid = ( l + r ) >> 1;
    return min( query( ll, rr, l, mid, now<<1 ), query( ll, rr, mid+1, r, now<<1|1 ) ); 
}

int main()
{
    memset( seg, 127, sizeof seg );
    scanf("%d",&n);
    for( int i = 1, num ; i <= n ; i++ ) {
        scanf("%d",&num);
        int a = 1e9, b = 1e9;
        if( num > 1 ) a = query( 1, num - 1 );
        if( num < n ) b = query( num + 1, n );
        // printf("%d %d %d\n",i,a,b);
        // printf("%d\n",seg[1]);
        ans = max( ans, max( i - a, i - b ) );
        up( num, i );
    }
    printf("%d",ans);
    return 0;
}