#include<bits/stdc++.h>

using namespace std;

long long n, bucket[1000010], a;
long long sum;
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i++ ){
        int t;
        scanf("%d",&t);
        bucket[t]++;
    }
    scanf("%lld",&a);
    for( int i = 0 ; i <= a / 2 ; i++ ){

        if( a - i <= 100000 ){
            if( a - i == i ){
                sum += ( long long )(( bucket[i]  * ( bucket[i] - 1 ) )/ 2 );
            }
            else{
                sum += ( long long )( bucket[i] * bucket[a - i] );
            }
        }
    }
    printf("%lld",sum);
    return 0;
}
