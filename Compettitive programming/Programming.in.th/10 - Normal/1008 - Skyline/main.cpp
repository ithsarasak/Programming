#include<stdio.h>

int skyline[255], p, q, r, n, i, j, max, min;
int main()
{
    scanf("%d", &n);

    for( i = 0; i < n ; i++ ){
        scanf("%d %d %d", &p, &q, &r);

       if( max < r ){
            max = r;
        }
       if( min > p ){
           min = p;
       }
       for( j = p - 1 ; j < r - 1 ; j++ ){
           if( skyline[j] < q ){
                skyline[j] = q;
           }
        }
     }

    for( i = min; i < max; i++ ){

        if( skyline[i] != skyline[i - 1] && skyline[i] != 0 ){
            printf("%d %d ", i + 1 , skyline[i] );
        }

        if( skyline[i + 1] == 0  && skyline[i] != 0 ){
            printf("%d 0 ", i + 2 );
        }
     }
    return 0;
 }
