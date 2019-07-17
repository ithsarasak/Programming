#include<stdio.h>
int m, n, worker[1000000], i;
long long l, r, mid, min = 1000000000010;
int f( long long k )
{
    long long sum = 0;
    for( int i = 0 ; i < m ; i++ ){
        sum += k / worker[i];
    }
    if( sum >= n ){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    scanf("%d",&m);
    for( i = 0 ; i < m ; i++ ){
        scanf("%d",&worker[i]);
        if( min > worker[i] ){
            min = worker[i];
        }
    }
    scanf("%d",&n);
    l = 0;
    r = min * n;
    while( l < r ){
        mid = ( l + r ) / 2;
        printf("%lld %lld %lld\n",l, r, mid);
        if( f(mid) == 0 ){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    printf("%lld",r);
    return 0;
}
