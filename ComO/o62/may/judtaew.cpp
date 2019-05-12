#include <bits/stdc++.h>

using namespace std;

const int N = 25e2 + 10;
int n, k, dp[N][4][N];
vector<int> coord;

int get( int x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + 1; }
int get2( int x ) { return upper_bound( coord.begin(), coord.end(), x ) - coord.begin(); }

int query( int ll, int rr, int ver, int l = 1, int r = n, int now = 1 ) {
    if( l > rr || l < rr || l > r ) return 0;
    if( l >= ll && r <= rr ) return seg[ver][now];
    int mid = ( l + r ) >> 1;
    return ( query( ll, rr, ver, l, mid, now << 1 ) + query( ll, rr, ver, mid + 1, r, now << 1 | 1 ) ) % mod;
}

void update( int idx, int ver, int va, int l = 1, int r = n, int now = 1 ) {
    if( l > idx || r < idx || l > r ) return ;
    if( l == r ) return void( seg[ver][now] = va );
    int mid = ( l + r ) >> 1;
    seg[ver][now] = ( seg[ver][now<<1] + seg[ver][now<<1|1] ) % mod;
    return ;
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&h[i]);
        coord.emplace_back( h[i] );
    }
    sort( coord.begin(), coord.end() );
    for( int l = 1 ; l <= k ; l++ ) {
        for( int j = 1 ; j <= 3 ; j++ ) {
            for( int i = 1 ; i <= n ; i++ ) {
                if( k > i ) dp[i][j][l] = 0;
                else dp[i][j][l] = query( get( h[i] - k ), get2( h[i] + k ), j );
                update( i, j, dp[i][j][l-1] );
            }
        }
        memset( seg, 0, sizeof seg );
    }
    printf("%d",dp[n][3][])
    return 0;
}