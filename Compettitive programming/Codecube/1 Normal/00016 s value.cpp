#include<bits/stdc++.h>

using namespace std;
long long ans;
long long num[2010], n;
int main()
{
    scanf("%lld",&n);
    n *= 2;
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&num[i]);
    }
    sort( num, num + n );
    for( int i = 0 ; i < n / 2 ; i++ ){
        ans += ( long long )( num[i] * num[n - i - 1] );
    }
    printf("%lld",ans);
    return 0;
}
