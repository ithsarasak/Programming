#include <stdio.h>
#include <stdlib.h>
struct ingredient{
    int sour,bitter;
}perket[10];

int i, amount , flag[10] , sol[1024], sumbitter = 0, sumsour = 1;
long k = 0;

int compare( const void *a , const void *b )
{
    return ( *( int *)a - *( int *)b );
}
int taste( int check , int d )
{
    if( d != 0 )
    {
        flag[d] = check;
    }
    if( d > amount )
    {
        return 0;
    }
    int count = 0;
    for( i = 1 ; i <= amount ; i++ )
    {
        if( flag[i] == 1 )
        {
            count++;
        }
    }
    if( d == amount && count != 0 )
    {
        /*for( i = 1 ; i <= amount ; i++ )
        {
            printf("%d ",flag[i]);
        }
        printf("\n");*/
        for( i = 1 ; i <= amount ; i++ )
        {
            if( flag[i] == 1 )
            {
                sumsour = sumsour * perket[i-1].sour;
                sumbitter = sumbitter + perket[i-1].bitter;
            }
        }
        sol[k] = sumsour - sumbitter;
        //printf("sol[%d]:%d\nsumsour : %d\nsumbitter : %d\n",k,sol[k],sumsour,sumbitter);
        if( sol[k] < 0 )
        {
            sol[k] = sol[k] * -1;
        }
        sumbitter = 0;
        sumsour = 1;
        k++;
        return 0;
    }
    taste( 0 , d + 1 );
    taste( 1 , d + 1 );
}

int main()
{
	scanf("%d",&amount);

	for( i = 0 ; i < amount ; i++ )
    {
        scanf("%d %d",&perket[i].sour,&perket[i].bitter);
    }
    if( amount == 1 )
    {
        int diff;

        diff = perket[0].sour - perket[0].bitter;
        if( diff < 0 )
        {
            diff = diff * -1;
        }
        printf("%d",diff);
        return 0;
    }
	taste( 0,0 );

    //printf("k : %d\n",k);

	qsort( sol , k , sizeof( int ) , compare );

    /*for( i = 0 ; i < k ; i++ )
    {
        printf("%d ",sol[i]);
    }
    printf("\n");*/
	printf("%d",sol[0]);

	return 0;

}
