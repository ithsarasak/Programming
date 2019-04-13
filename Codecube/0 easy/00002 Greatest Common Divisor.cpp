#include<bits/stdc++.h>

using namespace std;
long long n1, n2;
long long gcd( long long a, long long b )
{
    long long ans;
    for( long long i = 1 ; i <= b ; i += ans ){
        if( a % i == 0 && b % i == 0 ){
            ans = i;
        }
    }
    return ans;
}
int main()
{
    scanf("%lld %lld",&n1,&n2);
    if(!( n1 * n2 )){
        printf("%lld",max( n1 , n2 ));
        return 0;
    }
    printf("%lld\n",gcd( max( n1, n2 ), min( n1, n2 ) ) );
    return 0;
}

