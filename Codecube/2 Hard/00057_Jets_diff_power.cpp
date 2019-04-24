#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9 + 500;
const int N = 2e5 +100;
int dp[150], mi[150], ma[150], num[N], n, a, ans = inf;

int choice( int x ) {
    if( x >= 0 ) return mi[min(100, x)] + a * x;
    else return inf;
}

int choice2( int x ) {
    if( x <= 100 ) return ma[max(0, x+1)] - a * x;
    else return inf;
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&num[i]);
    scanf("%d",&a);
    for( int i = 0 ; i <= 100 ; i++ ) {
        if( i + num[1] <= 100 ) dp[i] = i * i;
        else dp[i] = inf;
    }
    mi[0] = dp[0], ma[100] = dp[100] + a * 100;
    for( int j = 1 ; j <= 100 ; j++ ) mi[j] = min( mi[j-1], dp[j] - a * j );
    for( int j = 99 ; j >= 0 ; j-- ) ma[j] = min( ma[j+1], dp[j] + a * j );
    for( int i = 2 ; i <= n ; i++ ) {
        for( int j = 0 ; j <= 100 ; j++ ) {
            if( j + num[i] > 100 ) {
                dp[j] = inf;
                continue;
            }
            int cst = num[i] - num[i-1] + j;
            dp[j] = min( choice( cst ), choice2( cst ) ) + j * j;
        }
        mi[0] = dp[0], ma[100] = dp[100] + a * 100;
        for( int j = 1 ; j <= 100 ; j++ ) mi[j] = min( mi[j-1], dp[j] - a * j );
        for( int j = 99 ; j >= 0 ; j-- ) ma[j] = min( ma[j+1], dp[j] + a * j );
    }
    for( int i = 0 ; i <= 100 ; i++ ) ans = min( ans, dp[i] );
    printf("%d",ans);
    return 0;
}