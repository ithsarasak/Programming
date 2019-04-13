#include <stdio.h>
#include <stdlib.h>
int compare( const void *a , const void *b )
{
    return ( *( int *)a - *( int *)b );
}
int main()
{
    int side[3],count=0;

    scanf("%d %d %d",&side[0],&side[1],&side[2]);


    while( side[0] != 1 || side[1] != 1 || side[2] != 1 )
    {
        qsort( side , 3 , sizeof( int ) , compare );
        side[2] = side[2] / 2;
        count++;
    }
    printf("%d",count);
    return 0;
}
