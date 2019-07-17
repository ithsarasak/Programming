#include<stdio.h>
#include<stdlib.h>

int compare( const void *a , const void *b ){
    return ( *( int *)b - *( int *)a );
}
int order[3000], n, k, i;
long long time;
int main()
{
    scanf("%d %d",&n,&k);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&order[i]);
    }

    qsort( order , n , sizeof( int ) , compare );

    for( i = 0 ; i < n ; i += k ){
            //printf("%d ",order[i]);
        time += order[i];
    }
    printf("%lld",time);
}
