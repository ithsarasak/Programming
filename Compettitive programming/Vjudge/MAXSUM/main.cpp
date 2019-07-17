#include<bits/stdc++.h>

long long i, n, num[100010];
long long mf = -3000000000, mn = 0;
int main()
{
    scanf("%lld",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%lld",&num[i]);
    }
    for( i = 0 ; i < n ; i++ ){
        mn += ( long long )num[i];
        if( mf < mn ){
            mf = mn;
        }
        if( mn < 0 ){
            mn = 0;
        }
    }
    printf("%lld\n",mf);
    return 0;
}
