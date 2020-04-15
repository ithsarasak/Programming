#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int t, n;
long long a[N], b[N], d[N];
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        int n;
        scanf("%d",&n);
        long long sum = 0, ans = 1e18;
        for( int i = 1 ; i <= n ; i++ ) scanf("%lld %lld",&a[i],&b[i]);
        for( int i = 1 ; i <= n ; i++ ) {
            d[i] = max( 0LL, a[(i%n)+1] - b[i] );
            sum += d[i];
            //printf("%lld\n",d[i]);
        }
       /// printf("SUM : %lld\n",sum);
        for( int i = 1 ; i <= n ; i++ ) {
            int pv;
            if( i == 1 ) pv = n;
            else pv = i-1;
            //printf("%lld\n",a[i] + sum - d[pv] );
            ans = min( ans, a[i] + sum - d[pv] );
        }
        printf("%lld\n",ans);
    }
    return 0;
}