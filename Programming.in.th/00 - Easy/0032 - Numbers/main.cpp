#include <stdio.h>
#include <stdlib.h>
int compare( const void *a , const void *b )
{
    return ( *( int *)a - *( int *)b );
}
int main()
{
    int num[1000],i,temp;
    int amount;

    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ )
    {
        scanf("%d",&num[i]);
    }

    qsort( num , amount , sizeof( int ) , compare );

    if( num[0] == 0 )
    {
        for( i = 1 ; i < amount ; i++ )
        {
            if( num[i] != 0 )
            {
                temp = num[i];
                num[i] = num[0];
                num[0] = temp;
                break;
            }
        }
    }
    for( i = 0 ; i < amount ; i++ )
    {
        printf("%d",num[i]);
    }
    return 0;
}
