#include<bits/stdc++.h>

using namespace std;
long long s, a, b, c;
int t;
int main()
{
    scanf("%d",&t);
    for( int i = 0 ; i < t ; i++ ){
        scanf("%lld %lld %lld %lld",&s,&a,&b,&c);
        long long help = (a+b)*(s/(c*a));
        s -= (c*a)*(s/(c*a));
        long long help2 = s / c;
        printf("%lld\n",help+help2);
    }
    return 0;
}
