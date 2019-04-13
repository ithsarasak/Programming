#include<bits/stdc++.h>

using namespace std;

int n, num[100010], ans;
int gcd( int a, int b )
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
    scanf("%d",&n);
    for( int i = 0 ; i< n ; i++ ){
        scanf("%d",&num[i]);
    }
    ans = gcd( max( num[0], num[1] ), min( num[0], num[1] ) );
    for( int i = 2 ; i < n ; i++ ){
        if( num[i] != 0 ){
            if( num[i] % ans == 0 ){
                continue;
            }
            else if( ans % num[i] == 0 ){
                ans = num[i];
            }
            else
                ans = gcd( max( ans, num[i] ), min( ans, num[i] ) );
        }
    }
    long long sum = 0;
    for( int i = 0 ; i < n ; i++ ){
        sum += ( long long )( num[i] / ans );
    }
    printf("%lld\n",sum);
    return 0;
}
