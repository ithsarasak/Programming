#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 10;
int n, m;
long long a[N], dp[N][105];

void solve( int d, int l, int r, int optl, int optr ) {
    if( l > r ) return ;
    int mid = l + r >> 1, idx;
    dp[mid][d] = 1e18;
    for( int i = optl ; i <= min( mid, optr ) ; i++ ) {
        long long now = dp[i][d-1] + ( mid - i ) * ( a[mid] - a[i] );
        //printf("now i : %lld %d\n",now,i);
        if( now < dp[mid][d] ) dp[mid][d] = now, idx = i;
    }
    //printf("%d %lld %d %d %d\n",mid,dp[mid][d],idx,optl,optr);
    solve( d, l, mid-1, optl, idx );
    solve( d, mid+1, r, idx, optr );
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&a[i]), a[i] += a[i-1];
    for( int i = 1 ; i <= n ; i++ ) dp[i][0] = i * a[i];
    for( int i = 1 ; i <= m ; i++ ) solve( i, 1, n, 1, n );
    printf("%lld",dp[n][m]);
}