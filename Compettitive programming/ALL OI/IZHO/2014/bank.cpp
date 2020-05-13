#include <bits/stdc++.h>

using namespace std;

const int N = 21;
int dp[N][1<<N], n, m, a[N], b[N];
vector<int> bit[N];

int solve( int p, int mask ) {
    if( p == n ) return 1;
    if( dp[p][mask] != -1 ) return dp[p][mask];
    dp[p][mask] = 0;
    for( int x : bit[p] ) {
        if( !( x&mask ) && solve( p+1, mask|x ) ) return dp[p][mask] = 1;
    }
    return 0;
}

int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
    for( int i = 0 ; i < m ; i++ ) scanf("%d",&b[i]);
    for( int i = 0 ; i < ( 1<<m ) ; i++ ) {
        int sum = 0;
        for( int j = 0 ; j < m ; j++ ) if( i & ( 1<<j ) ) sum += b[j];
        for( int j = 0 ; j < n ; j++ ) if( a[j] == sum ) bit[j].emplace_back( i );
    }
    if( solve( 0, 0 ) ) printf("YES\n");
    else printf("NO\n");
    return 0;
}