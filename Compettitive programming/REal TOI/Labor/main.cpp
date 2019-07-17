#include<bits/stdc++.h>
int m, n, worker[1000010], i;
int main()
{
    scanf("%d %d",&m,&n);
    for( i = 0 ; i < m ; i++ ){
        scanf("%d",&worker[i]);
    }
    long long l = 0;
    long long r = 500000000000000000, mid;
    while( l < r ){
        mid = ( l + r ) >> 1;
        long long sum = 0;
        for( i = 0 ; i < m ; i++ ){
            sum += mid / ( long long )worker[i];
        }
        //printf("%lld\n",mid);
        if( sum >= n ){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%lld",r);
    return 0;
}
