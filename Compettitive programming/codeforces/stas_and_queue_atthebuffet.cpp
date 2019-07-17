#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

long long dif[N], n, ans;
int main()
{
    scanf("%lld",&n);
    for( long long i = 1, a, b ; i <= n ; i++ ) {
        scanf("%lld %lld",&a,&b);
        ans += b * n - a;
        dif[i] = a - b;
    }
    sort( dif + 1, dif + 1 + n, greater<int>() );
    for( long long i = 1 ; i <= n ; i++ ) ans += i * dif[i]; 
    printf("%lld",ans);
    return 0;
}