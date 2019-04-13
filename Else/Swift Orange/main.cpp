#include<stdio.h>
long long n, p, i, l = 0, r = 2000000000, mid, c[1000010];
int main()
{
    scanf("%lld %lld",&n,&p);
    for( i = 0 ; i < n ; i++ ){
        scanf("%lld",&c[i]);
    }
    while( l < r ){
        mid = ( l + r + 1 ) / 2;
        //printf("%lld %lld %lld ",l,r,mid);
        long long sum = 0;
        for( i = 0 ; i < n ; i++ ){
            sum += c[i] / mid;
        }
        //printf("%lld\n",sum);
        if( sum >= p ){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    long long sum = 0;
    for( i = 0 ; i < n ; i++ ){
        sum += c[i] / r;
    }
    if( sum == p ){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    printf("%lld",r);
    return 0;
}
