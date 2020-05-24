#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int n, k, sum[N], dp[N];
multiset<int> se, pre[N];
char s[N];

int f( char c ) { return c == 'H' ? 1 : -1; }
int main()
{
    freopen("redistricting.in", "r", stdin);
    freopen("redistricting.out", "w", stdout);
    scanf("%d %d %s",&n,&k,&s[1]);
    for( int i = 1 ; i <= n ; i++ ) sum[i] = sum[i-1] + f( s[i] );
    se.insert( 0 ), pre[0].insert( 0 );
    for( int i = 1 ; i <= n ; i++ ) {
        int mn = *( se.begin() );
        if( *( pre[mn].begin() ) < sum[i] ) dp[i] = mn;
        else dp[i] = mn + 1;
        se.insert( dp[i] ), pre[dp[i]].insert( sum[i] );
        if( i - k >= 0 ) se.erase( se.find( dp[i-k] ) ), pre[dp[i-k]].erase( pre[dp[i-k]].find( sum[i-k] ) );
    }
    printf("%d",dp[n]);
    return 0;
}