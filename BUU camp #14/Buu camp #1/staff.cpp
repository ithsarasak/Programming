#include<bits/stdc++.h>

using namespace std;
long long t, dp[1000010], staff[1000010], n;
int main()
{
    scanf("%lld",&t);
    while( t-- ){
        scanf("%lld",&n);
        for( int i = 0 ; i < 1000010 ; i++ ){
            dp[i] = 0;
            staff[i] = 0;
        }
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%lld",&staff[i]);
        }
        for( int i = 1 ; i <= n ; i++ ){
            dp[i] = ( long long )( i - 1 );
        }
        for( int i = 1 ; i <= n ; i++ ){
            dp[i] = min( dp[i] , dp[i - 1] + 1 );
            if( i + staff[i] <= n )
                dp[i + staff[i]] = min( dp[i] + 1, dp[i + staff[i]] );
        }
        printf("%lld\n",dp[n]);
    }
}
