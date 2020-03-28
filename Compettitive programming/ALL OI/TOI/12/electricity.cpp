#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 5e5 + 10;
int n, k, dp[N], cost[N];
deque<pii> dq;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&cost[i]);
    for( int i = 1 ; i <= n ; i++ ) {
        while( !dq.empty() && i - dq.front().y > k ) dq.pop_front();
        if( i != 1 ) dp[i] = dq.front().x + cost[i];
        else dp[i] = cost[i];
        while( !dq.empty() && dq.back().x > dp[i] ) dq.pop_back();
        dq.push_back( pii( dp[i], i ) );
    }
    printf("%d",dp[n]);
}