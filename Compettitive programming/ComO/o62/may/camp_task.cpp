#include <bits/stdc++.h>

using namespace std;

const int N = 25e4 + 10;
struct ww {
    int f, t;
    long long w;
    bool operator<( const ww &k ) const {
        return t < k.t;
    }
}work[N];
int n;
long long dp[N][2], seg[4*N];
vector<int> coord;

int query( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
    if( l > rr || r < ll || l > r ) return 0;
    if( l >= ll && r <= rr ) return seg[now];
    int mid = ( l + r ) >> 1;
    return max( query( ll, rr, l, mid, now << 1 ), query( ll, rr, mid + 1, r, now << 1 | 1 ) );
}

void update( int idx, int va, int l = 1, int r = n, int now = 1 ) {
    if( l > idx || r < idx || l > r ) return ;
    if( l == r ) return void( seg[now] = va );
    int mid = ( l + r ) >> 1;
    update( idx, va, l, mid, now << 1 ), update( idx, va, mid + 1, r, now << 1 | 1 );
    seg[now] = max( seg[now<<1], seg[now<<1|1] );
    return ;
}

int get( int x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + 1; }

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d %d %lld",&work[i].f,&work[i].t,&work[i].w);
        coord.emplace_back( work[i].t );
    }
    sort( work + 1, work + 1 + n ), sort( coord.begin(), coord.end() );
    for( int i = 1 ; i <= n ; i++ ) {
        int idx = get( work[i].f );
        //printf("%d\n",idx);
        if( idx == i ) {
            dp[i][0] = dp[i-1][0] + work[i].w, dp[i][1] = dp[i-1][1] + work[i].w;
            continue ;
        }
        dp[i][0] = max( dp[idx-1][0] + work[i].w, dp[i-1][0] );
        dp[i][1] = max( work[i].w + dp[idx-1][1], max( dp[i-1][1], max( dp[idx-1][0] + work[i].w + query( idx, i - 1 ), dp[i-1][0] + work[i].w ) ) );
        update( i, work[i].w );
    }
    printf("%lld",max( dp[n][0], dp[n][1] ) );
    return 0;
}