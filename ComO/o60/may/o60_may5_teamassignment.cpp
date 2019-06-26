#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, l, u, seg[4*N], dp[N], num[N], pos[N];

void update( int idx, int va, int l = 1, int r = n, int now = 1 ) {
    if( l > idx || r < idx || l > r ) return ;
    if( l == r ) return void( seg[now] = va );
    int mid = ( l + r ) >> 1;
    update( idx, va, l, mid, now << 1 ), update( idx, va, mid + 1, r, now << 1 | 1 );
    seg[now] = max( seg[now<<1], seg[now<<1|1] );
    return ;
}

int query( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
    if( l > rr || r < ll || l > r ) return -1;
    if( l >= ll && r <= rr ) return seg[now];
    int mid = ( l + r ) >> 1;
    return max( query( ll, rr, l, mid, now << 1 ), query( ll, rr, mid + 1, r, now << 1 | 1 ) );
}

bool chk( int mid ) {
    pos[0] = -1e9;
    //cout << "mid: " << mid << endl;
    memset( seg, 0, sizeof seg );
    for( int i = 1 ; i <= n ; i++ ) {
        if( num[i] >= mid ) pos[i] = i;
        else pos[i] = pos[i-1];
        //printf("%d ",pos[i]);
    }
    //printf("\n");
    for( int i = 1 ; i <= n ; i++ ) {
        if( i < l ) dp[i] = -1;
        else if( pos[i] >= max( 1, i - u + 1 ) ){
            if( i <= u ) dp[i] = 1;
            else dp[i] = query( max( 1, i - u ), min( i - l, pos[i] - 1 ) );
        }
        else dp[i] = -1;
        update( i, dp[i] );
    }
    //for( int i = 1 ; i <= n ; i++ ) printf("%d ",dp[i]);
    //printf("\n");
    if( dp[n] == -1 ) return false;
    else return true;
}

bool ok() {
    int m = n % l, x = n / l, diff = u - l;
    if( !m || diff * x >= m ) return true;
    else return false;
}

int main()
{
    scanf("%d %d %d",&n,&l,&u);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&num[i]);
    int l = 0, r = 1e9 + 10;
    bool valid = false;
    while( l < r ) {
        int mid = ( l + r + 1 ) >> 1;
        if( chk( mid ) ) l = mid, valid = true;
        else r = mid - 1;
    }
    if(!valid) return !printf("-1\n");
    printf("%d",l);
    return 0;
}