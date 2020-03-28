#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
int n, p, q, now, prev, dp[N][N], vec[N];

bool chk( int m ) {
    for( int i = 0 ; i <= p ; i++ ) for( int j = 0 ; j <= q ; j++ ) {
        if( !i && !j ) continue ;
        dp[i][j] = 0;
        if( i ) dp[i][j] = upper_bound( vec + 1, vec + 1 + n, vec[dp[i-1][j]+1] + m - 1 ) - vec - 1;
        if( j ) dp[i][j] = max( ( long int )dp[i][j], upper_bound( vec + 1, vec + 1 + n, vec[dp[i][j-1]+1] + m + m - 1 ) - vec - 1 );
        if( dp[i][j] == n ) return true;
    }
    return false;
}

int main()
{
    scanf("%d %d %d",&n,&p,&q);
    if( p + q >= n ) return !printf("1");
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&vec[i]);
    } 
    sort( vec + 1, vec + 1 + n );
    int l = 1, r = 1e9;
    while( l < r ) {
        int m = l + r >> 1;
        if( chk( m ) ) r = m;
        else l = m + 1;
    }
    printf("%d",l);
    return 0;
}