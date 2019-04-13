#include<stdio.h>
#include<stdlib.h>

int block1[65000], block2[65000], block3[65000], block4[65000],count1, count2;
long long en;
int n, i ,j;
int compare( const void *a , const void *b ){
    return ( *( int *)b - *( int *)a );
}
int main()
{
    scanf("%d",&n);
    for( i = 1 ; i <= n ; i++ ){
        if( i % 2 == 1 ){
            for( j = 1 ; j <= n / 2 ; j++ ){
                scanf("%d %d",&block1[count1],&block2[count1]);
                count1++;
            }
        }
        else{
            for( j = 1 ; j <= n / 2 ; j++ ){
                scanf("%d %d",&block3[count2],&block4[count2]);
                count2++;
            }
        }
    }
    qsort( block1 , count1 , sizeof( int ) , compare );
    qsort( block2 , count1 , sizeof( int ) , compare );
    qsort( block3 , count2 , sizeof( int ) , compare );
    qsort( block4 , count2 , sizeof( int ) , compare );
    for( i = 0 ; i < count1 ; i++ ){
        en += block1[i] * block2[i] * block3[i] *block4[i];
    }
    printf("%lld",en);
    return 0;
}
