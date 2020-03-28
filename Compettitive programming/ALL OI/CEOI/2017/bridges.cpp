#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define x first
#define y second
 
using namespace std;
 
const int N = 1<<20;
const int M = 1e5 + 10;
const int K = 1e6;

const long long INF = 1e18;
bool chk[N<<1];
int n;
long long sum[M], h[M], dp[M];
pll seg[N<<1];
 
long long get( pll a, long long x ) { return a.x * x + a.y; }
 
void update( pll li, int l = 0, int r = K, int idx = 1 ) {
    if( !chk[idx] ) {
        chk[idx] = true, seg[idx] = li;
        return ;
    }
    if( get( li, l ) > get( seg[idx], l ) && get( li, r ) > get( seg[idx], r ) ) return ;
    if( get( li, l ) < get( seg[idx], l ) && get( li, r ) < get( seg[idx], r ) ) return void( seg[idx] = li );
    int mid = ( l + r ) >> 1;
    if( get( li, l ) < get( seg[idx], l ) ) swap( seg[idx], li );
    if( l == r ) return ;
    if( get( li, mid ) < get( seg[idx], mid ) ) swap( seg[idx], li ), update( li, l, mid, idx<<1 );
    else update( li, mid+1, r, idx<<1|1 );
}
 
long long query( long long x, int l = 0, int r = K, int idx = 1 ) {
    if( !chk[idx] ) return INF;
    if( l == r ) return get( seg[idx], x );
    int mid = ( l + r ) >> 1;
    if( x <= mid ) return min( query( x, l, mid, idx<<1 ), get( seg[idx], x ) );
    else return min( get( seg[idx], x ), query( x, mid + 1, r, idx<<1|1 ) );
}
 
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&h[i]);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%lld",&sum[i]);
        sum[i] += sum[i-1];
    }
    for( int i = 1 ; i <= n ; i++ ) {
        if( i != 1 ) dp[i] = query( h[i] ) + h[i] * h[i] + sum[i-1];
        //printf("%d %lld %lld %lld\n",i,query( h[i] ), sum[i-1],dp[i]);
        update( pll( -2LL*h[i], h[i]*h[i] - sum[i] + dp[i] ) );
        
    }
    //printf("\n");
    printf("%lld\n",dp[n]);
    return 0;
}