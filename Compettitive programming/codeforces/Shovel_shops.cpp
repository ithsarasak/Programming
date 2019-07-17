#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 2e5 + 100; 
int n, m, k;
long long cost[N], dp[N];
pii offer[N];

int main()
{
    memset( dp, 127, sizeof dp );
    dp[0] = 0;
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&cost[i]);
    sort( cost + 1, cost + 1 + n );
    for( int i = 1 ; i <= n ; i++ ) cost[i] += cost[i-1];
    for( int i = 1, x, y ; i <= m ; i++ ) {
        scanf("%d %d",&y,&x);
        offer[i] = pii( x, y );
    }
    // cout << endl;
    for( int i = 1 ; i <= k ; i++ ) {
        for( int j = 1 ; j <= m ; j++ ) {
            // cout << offer[j].x << " " << offer[j].y << endl;
            long long pay = 0;
            if( i >= offer[j].y ) pay = dp[i-offer[j].y] + cost[i] - cost[i-offer[j].y+offer[j].x];
            else pay = cost[i];
            // printf("%d\n",pay);
            dp[i] = min( dp[i], pay );
        }
    }
    // for( int i = 1 ; i <= k ; i++ ) cout << dp[i] << " ";
    printf("%lld",dp[k]);
    return 0; 
}