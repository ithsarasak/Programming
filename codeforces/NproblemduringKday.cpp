#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 10;
long long n, k, ans[N];

int main()
{
    scanf("%lld %lld",&n,&k);
    if( n < ( k * ( k + 1 ) ) / 2 ) {
        printf("NO");
        return 0;
    }
    n -= ( k * ( k + 1 ) ) / 2;
    long long cnt = n / k;
    n %= k;
    for( long long i = 1 ; i <= k ; i++ ) ans[i] = i + cnt;
    //for( long long i = 1 ; i <= k ; i++ ) cout << ans[i] << " ";
    //cout << endl;
    for( long long i = k ; i >= 2 && n ; i-- ) {
        long long x = ans[i-1] * 2 - ans[i];
        //cout << n << " " << x << " " << ans[i] << " " << ans[i-1] << endl;
        if( n <= x ) {
            ans[i] += n;
            n = 0;
        }
        else n -= x, ans[i] += x;
    }
    if( n > 0 ) printf("NO");
    else {
        printf("YES\n");
        for( long long i = 1 ; i <= k ; i++ ) printf("%lld ",ans[i]);
    }
    return 0;
}