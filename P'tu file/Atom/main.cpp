#include<stdio.h>
#include<stdlib.h>

int compare( const void *a, const void *b )
{
    return ( *( int *)b - *( int *)a );
}
int cases, i, j;
int main()
 {
     scanf("%d",&cases);
     for( i = 0 ; i < cases ; i++ ){
        int atoms, atom[201];
        char each[3];
        scanf("%d",&atoms);
        for( j = 0 ; j < atoms ; j++ ){
            scanf("%d",&atom[j]);
            if( atom[j] < 0 ){
                atom[j] *= -1;
            }
        }
        qsort( atom , atoms , sizeof( int ) , compare );
        int start = 0;
        long long value = 0;
        while( start < atoms ){
            value += atom[start] * atom[start];
            start++;
            for( j = start ; j < atoms ; j++ ){
                if( atom[j] != 0 ){
                    atom[j] -= 1;
                }
            }
        }
        printf("Case #%d: %lld\n",i + 1,value);
     }
     return 0;
 }
