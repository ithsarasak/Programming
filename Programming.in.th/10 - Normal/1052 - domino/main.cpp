#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+100;
int n, seg[4*N], h[N], ranger[N], rangel[N], dpr[N], dpl[N], minpos, mx, lz[4*N];
vector<int> pos;
char c;

void push( int l, int r, int now ) {
    if( !lz[now] ) return ;
    seg[now] += lz[now];
    if( l != r ) lz[now<<1] += lz[now], lz[now<<1|1] += lz[now];
    lz[now] = 0;
    return ;
}

void up( int ll, int rr, int va, int l = 1, int r = n, int now = 1 ) {
    push( l, r, now );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        seg[now] += va;
        if( l != r ) lz[now<<1] += va, lz[now<<1|1] += va;
        return ;
    }
    int mid = ( l + r ) >> 1;
    up( ll, rr, va, l, mid, now<<1 ), up( ll, rr, va, mid + 1, r, now<<1|1 );
    seg[now] = max( seg[now<<1], seg[now<<1|1] );
    return ;
}

int query( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
    push( l, r, now );
    if( l > rr || r < ll || l > r ) return -1e9;
    if( l >= ll && r <= rr ) return seg[now];
    int mid = ( l + r ) >> 1;
    return max( query( ll, rr, l, mid, now<<1 ), query( ll, rr, mid+1, r, now<<1|1 ) );
}

int main()
{
    scanf("%d",&n);
    for( int i = 0, x ; i < n ; i++ ) {
        scanf("%d %d",&x,&h[i]);
        pos.emplace_back( x );
    }
    for( int i = 0 ; i < n - 1 ; i++ ) {
        int idx = lower_bound( pos.begin(), pos.end(), pos[i] + h[i] ) - pos.begin() + 1;
        idx--;
        ranger[i+1] = idx;
    }
    for( int i = n-1 ; i > 0 ; i-- ) {
        int idx = upper_bound( pos.begin(), pos.end(), pos[i] - h[i] ) - pos.begin() + 1;
        rangel[i+1] = idx;
    }
    dpl[1] = 1;
    up( 1, 1, 1 );
    mx = 1, minpos = 1, c = 'L';
    for( int i = 2 ; i <= n ; i++ ) {
        dpl[i] = max( query( rangel[i], i ) + 1, i - rangel[i] + 1 );
        up( i, i, dpl[i] );
        up( 1, i-1, 1 );
        if( dpl[i] > mx ) mx = dpl[i], minpos = i;
    }
    memset( seg, 0, sizeof seg );
    memset( lz, 0, sizeof lz );
    dpr[n] = 1;
    up( n, n, 1 );
    for( int i = n - 1 ; i >= 1 ; i-- ) {
        dpr[i] = max( query( i, ranger[i] ) + 1, ranger[i] - i + 1 );
        up( i, i, dpr[i] );
        up( i+1, n, 1 );
        if( dpr[i] > mx ) mx = dpr[i], minpos = i, c = 'R';
        else if( dpr[i] == mx && i < minpos ) minpos = i, c = 'R';
    }
    printf("%d %c",minpos,c);
    return 0;
}