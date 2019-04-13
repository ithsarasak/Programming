#include<stdio.h>
#include<stdlib.h>

int num[100001], amount, i;
int compare( const void *a , const void *b )
{
    return ( *( int * )a - *( int * )b );
}
int main()
{
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ ){
        scanf("%d",&num[i]);
    }
    qsort( num , amount , sizeof( int ) , compare );

    int sum = num[0] + num[1];

    for( i = 2 ; i < amount ; i++ ){
        if( sum <= num[i] ){
            printf("yes");
            return 0;
        }
    }
    printf("no");
    return 0;
}
