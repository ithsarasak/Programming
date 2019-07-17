#include <stdio.h>
int flag[1001],sol[1001];
main()
{
    int num, pos;
    int i, j, k = 0;
    scanf("%d %d",&num,&pos);

    for( i = 2 ; i <= num ; i++ )
    {
        for( j = 1 ; j <= num ; j++ )
        {
            if( i * j > num)
            {
                break;
            }
            if( !flag[i*j] )
            {
                sol[k] = i * j;
                //printf("sol[%d] : %d\ni*j : %d\ni : %d\nj : %d\n",k,sol[k],i*j,i,j);
                k++;
                flag[ i * j ] = 1;
            }
        }
    }
    /*for( i = 0 ; i < k ; i++ )
    {
        printf("%d ",sol[i]);
    }
    printf("\n");*/
    printf("%d",sol[pos-1]);
}
