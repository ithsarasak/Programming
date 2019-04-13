#include<bits/stdc++.h>

using namespace std;
long long n, m;
long long cow[5100], dp[5100], price[100010];
int main()
{
    memset( dp, 127, sizeof dp );
    scanf("%lld %lld",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&cow[i]);
    }
    for( int i = 1 ; i <= m ; i++ ){
        scanf("%lld",&price[i]);
    }
    for( int i = m - 1 ; i >= 1 ; i-- ){
        price[i] = min( price[i], price[i + 1] );
    }
    dp[0] = 0;
    sort( cow + 1 , cow + n + 1 );
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= i ; j++ ){
            dp[i] = min( price[cow[i]-cow[j]+1] + dp[j-1], dp[i] );
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
