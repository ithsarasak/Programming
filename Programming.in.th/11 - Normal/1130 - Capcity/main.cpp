#include<stdio.h>
#include<stdlib.h>

long long sum[1000010], one, two, da, mn, i, dat[10010] , j, n, t, sol[10010], sol2[10010];
int compare( const void *a , const void *b )
{
    return ( *( long long *)a - *( long long *)b );
}
int main()
{
    sum[1] = 1;
    for( i = 2 ; i <= 1000000 ; i++ ){
        sum[i] = ( sum[i - 1] * i )  % 49999;
    }
    scanf("%lld",&n);

    for( i = 0 ; i < n ; i++ ){
        scanf("%lld",&dat[i]);
    }
    qsort( dat , n , sizeof( long long ) , compare );

    if( n == 2 ){
        printf("%lld",( dat[1] - dat[0] ) % 49999 );
        return 0;
    }
    else{
        t = sum[n - 2];
        for( i = 0 ; i <= t * ( n - 1 ) ; i += t ){
            one = ( ( i % 49999 ) * ( dat[j] % 49999 ) ) % 49999;
            two = ( ( ( t * ( n - j - 1 ) ) % 49999 ) * dat[j] ) % 49999;
            one %= 49999;
            two %= 49999;
            sol[j] = one;
            sol2[j] = two;
            j++;
        }
        for( i = 0 ; i < n ; i++ ){
            da += sol[i];
            mn += sol2[i];
            da %= 49999;
            mn %= 49999;
        }
        printf("%lld",( ( ( da - mn ) % 49999 ) + 49999 ) % 49999 );
        return 0;
    }
}
