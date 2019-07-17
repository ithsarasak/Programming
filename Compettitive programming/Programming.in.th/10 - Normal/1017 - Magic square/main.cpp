#include<stdio.h>
#include<stdlib.h>
int square[10][10];
int check[100];
int suml, sum, c = 0, sums;
int compare( const void *a , const void *b )
{
    return ( *( int *)a - *( int *)b );
}
int main()
{
    int side, i, j, k = 0;

    scanf("%d",&side);

    for( i = 0 ; i < side ; i++ )
    {
        for( j = 0 ; j < side ; j++ )
        {
            scanf("%d",&square[i][j]);
            check[k] = square[i][j];
            k++;
        }
    }

    qsort( check , side * side , sizeof( int ) , compare );

    /*for( i = 0 ; i < side * side  ; i++ )
    {
        printf("%d ",check[i]);
    }*/

    for( i = 0 ; i < side * side - 1 ; i++ )
    {
        if( check[i] == check[ i + 1 ] )
        {
            printf("No");
            return 0;
        }
    }
    for( i = 0 ; i < side ; i++ )
    {
        sum += square[0][i];
    }
    for( i = 0 ; i < side ; i++ )
    {
        sums = 0;
        suml = 0;
        for( j = 0 ; j < side ; j++ )
        {
            suml += square[i][j];
            sums += square[j][i];
        }
       // printf("sum : %d suml : %d sums : %d\n",sum,suml,sums);
        if( suml != sum || sums != sum )
        {
            c = 1;
            break;
        }
    }
    if( c )
    {
        printf("No");
        return 0;
    }
    sums = 0;
    suml = 0;
    for( i = 0 ; i < side ; i++ )
    {
        suml += square[i][i];
        sums += square[i][ side - i - 1 ];
    }
    if( suml != sum || sums != sum )
    {
        c = 1;
    }
    if( c )
    {
        printf("No");
        return 0;
    }
    else
    {
        printf("Yes");
    }
    return 0;
}
