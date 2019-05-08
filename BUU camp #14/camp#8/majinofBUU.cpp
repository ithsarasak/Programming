#include <bits/stdc++.h>

using namespace std;
long long qs[100100], num[100100], mod = 1000000007 ;
int q, n;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%lld",&num[i]);
            qs[i] = qs[i-1] + num[i];
        }
        long long allsum = qs[1], ans = 0;
        for( int i = 2 ; i <= n ; i++ ){
            ans += allsum * num[i];
            allsum += qs[i];
            ans %= mod;
            allsum %= mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
