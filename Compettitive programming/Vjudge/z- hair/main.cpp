#include<stdio.h>
int n, m, k, i ,j ,first, mid, last = 1000000, hair[2010];
int main()
{
    scanf("%d %d %d",&n,&k,&m);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&hair[i]);
    }
    int t = 0;
    while( first <= last ){
        t = 0;
        mid = ( first + last ) / 2;
        //printf("%d %d %d\n",first,mid,last);
        for( i = 0 ; i < n ; i++ ){
            if( hair[i] > mid ){
                t++;
                i += k - 1;
            }
        }
        if( t <= m ){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }
    printf("%d",first);
    return 0;
}
