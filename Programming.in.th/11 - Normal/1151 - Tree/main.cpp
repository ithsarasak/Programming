#include <stdio.h>
int num[200001] ;
int sol[200001] ;
int counts = 0 ;
int main()
{
    int amount,i;

    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ )
    {
        scanf("%d",&num[i]);
    }
    int sizes = 0;
    for( i = 0 ; i < amount ; i++ )
    {
        if( i == 0 )
        {
            //printf("num[%d] : %d\n",i,num[i]);
            sol[sizes] = num[i];
            sizes++;
            counts++;
        }
        else
        {
            int k = sizes;
            int c = 0;
            //printf("num[%d] : %d\n",i,num[i]);
            while( num[i] <= sol[ k - 1 ] )
            {
                c = 1;
                k = k - 1;
            }
            sol[ k ] = num[i];
            //printf("sol[%d] : %d\n",k,sol[k]);
            if( !c )
            {
                sizes++;
                counts++;
            }
        }
    }
    printf("%d",counts);
    return 0;
}
