#include<bits/stdc++.h>

using namespace std;
long long n, m, ans;
int main()
{
    scanf("%lld %lld",&n,&m);
    printf("%lld ",max( (long long)0,n-(2*m)) );
    long long l = 0,i;
    for( i = 0 ; i <= n ; i++ ){
        if( m <= (i*(i-1))/2 ){
            ans = n - i;
            break;
        }
    }
    if( m > (i*(i-1))/2 )ans++;
    printf("%lld",ans);
    return 0;
}
