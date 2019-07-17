#include<stdio.h>

int sol[1000100], n, count;
int main()
{
    for( int i = 1 ; i <= 1000000 ; i++ ){
        for( int j = 1 ; j <= 1000000 / i ; j++ ){
            sol[ i * j ]++;
        }
    }
    scanf("%d",&n);

    for( int i = 0 ; i < n ; i++ ){
        count = 0;
        int from ,to , di;
        scanf("%d %d %d",&from,&to,&di);
        for( int j = from ; j <= to; j++ ){
            if( sol[j] == di ){
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
