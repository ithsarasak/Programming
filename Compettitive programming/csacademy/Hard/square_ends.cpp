#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define m first 
#define c second 

using namespace std;

const int N = 1e6 + 10;
const int K = 1e2 + 10;
pll seg[4*N]; 
int n, k, chk[N];
long long a[N], dp[K][N];

long long get( pll a, long long x ) { return a.m*x + a.c; }
long long p2( long long num ) { return num * num; }
void update( pll li, long long s, int idx = 1, int l = 1, int r = N - 9 ) {
    if( s != chk[idx] ) 
        chk[idx] = s;
        return void( seg[idx] = li );
    }
    if( get( li, l ) <= get( seg[idx], l ) && get( li, r ) <= get( seg[idx], r ) ) return void( seg[idx] = li );
    else if( get( li, l ) >= get( seg[idx], l ) && get( li, r ) >= get( seg[idx], r ) ) return ;
    if( l == r ) return ;
    if( get( li, l ) < get( seg[idx], l ) ) swap( seg[idx], li ); 
    int mid = ( l + r ) >> 1;
    if( get( li, mid ) >= get( seg[idx], mid ) ) update( li, s, idx << 1 | 1, mid + 1, r );
    else swap( seg[idx], li ), update( li, s, idx << 1, l, mid );
    return ;
}

long long query( int pos, int s, int l = 1, int r = N - 9, int idx = 1 ) {
    if( chk[idx] != s ) return 1e18;
    if( l == r ) return get( seg[idx], pos );
    int mid = ( l + r ) >> 1;
    if( pos <= mid ) return min( query( pos, s, l, mid, idx << 1 ), get( seg[idx], pos ) );
    else return min( get( seg[idx], pos ), query( pos, s, mid + 1, r, idx << 1 | 1 ) ); 
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&a[i]);
    for( int i = 1 ; i <= n ; i++ ) dp[1][i] = p2( a[i] - a[1] );
    for( int i = 2 ; i <= k ; i++ ) {
        for( int j = i ; j <= n ; j++ ) {
            update( pll( -2*a[j], p2( a[j] ) + dp[i-1][j-1] ), i );
            dp[i][j] = query( a[j], i ) + p2( a[j] );
        }
    }
    printf("%lld",dp[k][n]);
    return 0;
}