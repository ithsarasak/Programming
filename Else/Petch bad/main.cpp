#include<bits/stdc++.h>
int n, b, city[500010], l, r = 2000000000, i, mid;
int main()
{
    scanf("%d %d",&n,&b);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&city[i]);
    }
    l = 0;
    while( l < r ){
        mid = ( l + r ) / 2;
        long long sum = 0;
        for( i = 0 ; i < n ; i++ ){
            if( city[i] % mid == 0 ){
                sum += ( long long )city[i] / mid;
            }
            else{
                sum += ( ( long long )city[i] / mid ) + 1;
            }
        }
        if( sum <= b ){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d",r);
    return 0;
}
