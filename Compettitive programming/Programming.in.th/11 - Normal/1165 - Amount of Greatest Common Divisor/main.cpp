#include<stdio.h>
#include<climits>
long long num[11], i, j, factor = 1;
int amount;
long long min = INT_MAX;
long long gcd( long long a , long long b )
{
    if( a == 0 ){
        return b;
    }
    if( b == 0 ){
        return a;
    }
    gcd( b % a , a );
}
int main()
{
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ ){
        scanf("%lld",&num[i]);
    }
    num[1] = gcd( num[0], num[1] );
    for( i = 2 ; i < amount ; i++ ){
        num[i] = gcd( num[i-1], num[i] );
    }
    long long bgcd = num[amount-1];
    //printf("%lld\n",bgcd);
    while(bgcd > 1){
        for( i = 2 ; i <= bgcd ; i++ ){
            if( bgcd % i == 0 ){
                long long cnt = 0;
                while( bgcd % i == 0){
                    bgcd /= i;
                    cnt++;
                }
                factor *= (cnt + 1);
            }
            if( i == bgcd ){
                factor *= 2;
                break;
            }
        }
    }
    printf("%lld",factor);
    return 0;
}
