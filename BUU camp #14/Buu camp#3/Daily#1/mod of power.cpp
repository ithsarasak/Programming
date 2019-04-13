#include<bits/stdc++.h>

using namespace std;
long long q, a, b, c;
long long dv( long long num )
{
    if( num == 1 ){
        return a % c;
    }
    long long te = (dv(num/2)*dv(num/2))%c;
    if( num % 2 ) te*=a;
    return te%c;
}
int main()
{
    scanf("%lld",&q);
    while( q-- ){
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("%lld\n",dv( b ));
    }
    return 0;
}
