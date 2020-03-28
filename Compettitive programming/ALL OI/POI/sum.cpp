#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
int n, a[N], k;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&a[i]);
        int x[i] = a[i] % a[1];
        int gc = gcd( )
    for( int i = 2 ;  i <= n ; i++ ) {
        int cost = a[i] / a[1], shit = a[i] % a[1];
        for( int j = 1 ; j < a[1] && j + a[1] <= 50000 ; j++ ) {
            dp[j] = min( dp[j], dp[(j-shit+a[1])%a[1]] + cost );
        }
    }
    return 0;
}