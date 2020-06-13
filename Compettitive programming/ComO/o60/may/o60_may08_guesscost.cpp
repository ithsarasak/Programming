#include <bits/stdc++.h>

using namespace std;

const int N = 310;
int n, dp[N][N], cost[N];

int solve( int l, int r ) {
    if( l > r ) return 0;
    int &now = dp[l][r];
    if( now != -1 ) return now;
    now = 1e9;
    for( int i = l ; i <= r ; i++ ) now = min( now, max( solve( l, i-1 ), solve( i+1, r ) ) + cost[i] );
    //printf("%d %d %d\n",l,r,now);
    return now;
}

int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&cost[i]);
    printf("%d",solve( 1, n ));
    return 0;
}