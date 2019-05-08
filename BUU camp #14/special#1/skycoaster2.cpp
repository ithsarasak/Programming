#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int t, n, ans;
long long c, dp[N], a[N], b[N], sum, start = -1;

int main()
{
    scanf("%d",&t);
    while( t-- ) {
        memset( dp, 0, sizeof dp ), ans = 1, sum = 0, start = -1;
        scanf("%d %lld",&n,&c);
        for( int i = 0 ; i < n ; i++ ) scanf("%lld",&a[i]);
        for( int i = 0 ; i < n ; i++ ) scanf("%lld",&b[i]);
        for( int i = 0 ; i < 2*n ; i++ ) {
            if( start == -1 && i >= n ) break;
            if( start == i % n ) break;
            sum = min( c, sum + a[i%n] ) - b[i%n];
            if( sum < 0 ) start = -1, sum = 0;
            else if( start == -1 ) start = i;
        }
        if( start == -1 ) {
            printf("0\n");
            continue ;
        }
        dp[start] = 0;
        for( int idx = ( start - 1 + n ) % n ; idx != start ; idx = ( idx - 1 + n ) % n ) {
            //cout << idx << endl; 
            if( b[idx] > c ) break;
            dp[idx] = max( 0LL, b[idx] - min( c, a[idx] ) + dp[(idx+1)%n] );
            if( !dp[idx] ) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}