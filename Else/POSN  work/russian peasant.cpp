#include<bits/stdc++.h>
long long n1, n2, sum;
int main()
{
    scanf("%lld %lld",&n1,&n2);
    while( n1 != 1 ){
        if( n1 % 2 == 1 ){
            sum += n2;
        }
        n2 *= 2;
        n1 /= 2;
    }
    sum += n2;
    printf("%lld",sum);
    return 0;
}
