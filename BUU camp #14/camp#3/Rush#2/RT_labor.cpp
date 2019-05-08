#include<bits/stdc++.h>
long long m, n, worker[1000010], i;
int main()
{
    scanf("%lld %lld",&m,&n);
    for( i = 0 ; i < m ; i++ ){
        scanf("%lld",&worker[i]);
    }
    long long l = 0;
    long long r = 1e18+1, mid;
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


