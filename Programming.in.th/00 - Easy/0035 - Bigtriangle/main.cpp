#include <stdio.h>
#include <stdlib.h>
struct point{
    float x;
    float y;
}sao[100];
double area[350000];
int compare( const void *a , const void *b )
{
    return ( *( double *)a - *( double *)b );
}
int main()
{
    int amount,i,j,k;

    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ )
    {
        scanf("%f %f",&sao[i].x,&sao[i].y);
    }
    int size = 0;
    for( i = 0 ; i < amount ; i++ )
    {
        for( j = i + 1 ; j < amount ; j++ )
        {
            for( k = j + 1 ; k < amount ; k++ )
            {
                area[size] = ( ( ( sao[i].x * sao[j].y ) + ( sao[j].x * sao[k].y ) + ( sao[k].x * sao[i].y ) ) - ( ( sao[j].x * sao[i].y ) + ( sao[k].x * sao[j].y ) + ( sao[i].x * sao[k].y ) ) ) / 2;
                if( area[size] < 0)
                {
                    area[size] = area[size] * -1;
                }
                //printf("area[%d] :%.3lf\n",size,area[size]);
                size++;
            }
        }
    }

    qsort( area , size , sizeof( double ) , compare );

    /*for( i = 0 ; i < size ; i++ )
    {
        printf("%.3lf ",area[i]);
    }*/

    printf("%.3lf",area[ size - 1 ]);
    return 0;
}
