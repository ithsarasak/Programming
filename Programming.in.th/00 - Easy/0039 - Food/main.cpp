#include <stdio.h>
#include <stdlib.h>

int cante[8], cane[8], how[8], food[8];
int num, i, k, j, note, check = 0, count = 0;

int sort( const void *a , const void *b )
{
    return ( *( int *)a - *( int *)b );
}
int search( int food[] , int small , int mid , int size)
{
    int index = mid;

    for( i = mid + 1 ; i <= size ; i++ )
    {
        if( food[i] > small && food[i] < food[index] )
        {
            index = i;
        }
    }
    return index;
}
int result( int num , int food[] , int size )
{
    int check = 1, i;

    //printf("size : %d\n",size);

    while( check )
    {
        printf("%d ",num);

        for( i = 0 ; i < size; i++ )
        {
            printf("%d ", food[i]);
        }

        printf("\n");

        for( i = size - 2 ; i >= 0 ; i-- )
        {
            if( food[i] < food[i+1] )
            {
                break;
            }
        }

        //printf("i : %d\n", i);
        if( i < 0 )
        {
            check = 0;
        }
        else
        {
            //printf("food[%d] : %d\n",i,food[i]);
            int index = search( food , food[i] , i + 1 , size );

            int temp;

            temp = food[i];
            food[i] = food[index];
            food[index] = temp;

            int k = 0;

            /*printf("%d ",num);

            for( j = 0 ; j < size; j++ )
            {
                printf("%d ", food[j]);
            }

            printf("\n");*/

            for( j = i + 1 ; j < size ; j++ )
            {
                how[k] = food[j];
                //printf("how[%d] : %d\n",k,how[k]);
                //printf("food[%d] : %d\n",j,food[j]);

                k++;
            }

            int g;

            /*for( g = 0 ; g < size - 1 - i ; g++ )
            {
                //printf("IN\n");
                printf("%d ", how[g]);
            }

            printf("\n");*/

            qsort( how , size - 1 - i , sizeof( int ) , sort );

            /*for( g = 0 ; g < size - 1 - i ; g++ )
            {
                //printf("IN\n");
                printf("%d ", how[g]);
            }
            printf("\n");*/

            k = 0;
            for( j = 1 + i ; j < size ; j++ )
            {
                food[j] = how[k];
                k++;
            }

            /*printf("%d ",num);

            for( i = 0 ; i < size; i++ )
            {
                printf("%d ", food[i]);
            }
            printf("\n");

            count++;*/
        }
        //if(count == 2) { check = 0; }
    }
}
main()
{
    int i;
    scanf("%d", &num);
    scanf("%d", &note);

    for( i = 0 ; i < note ; i++ )
    {
        scanf("%d", &cante[i]);
    }
    /*for( i = 0 ; i < num ; i++ )
    {
        printf("%d ", cante[i]);
    }
    printf("\n");*/

    int count = 0;

    for( i = 1 ; i <= num ; i++ )
    {
        count = 0;

        for( j = 0 ; j < note ; j++ )
        {
            if( cante[j] != i)
            {
                count++;
            }
        }
        if( count == note)
        {
            cane[k] = i;
            k++;
        }
    }
    /*for(i=0;i<num;i++)
    {
        printf("%d ",cane[i]);
    }
    printf("\n");*/

    for( i = 0 ; i < num-note ; i++ )
    {
        k = 0;

        for( j = 0 ; j < num ; j++ )
        {
            if( j + 1 != cane[i])
            {
                food[k] = j+1;
                k++;
            }
        }
        /*for( j = 0 ; j < k ; j++ )
        {
            printf("%d ",food[j]);
        }*/

        //printf("\n");
        result( cane[i] , food , k );
    }
}
