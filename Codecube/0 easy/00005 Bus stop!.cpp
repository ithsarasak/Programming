#include<bits/stdc++.h>

using namespace std;
long long n, num[100010];
long long lcm;
long long gcd( long long a , long long b )
{
    if( a % b == 0 ) return b;
    else return gcd( b , a % b );
}
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&num[i]);
    }
    lcm = ( num[0] * num[1] ) / gcd( max( num[0], num[1] ), min( num[0], num[1] ) );
    for( int i = 2 ; i < n ; i++ ){
        lcm = ( lcm * num[i] ) / gcd( max( lcm, num[i] ), min( lcm, num[i] ) );
    }
    printf("%lld",lcm);
    return 0;
}
