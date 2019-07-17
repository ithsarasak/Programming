#include<stdio.h>
#include<stdlib.h>

int nm, times, q, start, end, f;
int magnet[200010], count, count2, i, mid, magnet2[200010];
int compare( const void *a , const void *b ){
    return( *( int *)a - *( int *)b );
}
int main()
{
    scanf("%d %d %d",&nm,&times,&q);
    for( i = 0 ; i < times ; i++ ){
        scanf("%d %d",&start,&end);
        magnet[count] = start;
        count++;
        magnet[count] = start + end;
        count++;
    }
    qsort( magnet , count , sizeof( int ) , compare );
    for( i = 0 ; i < count ; i++ ){
        if( magnet[i] == magnet[i + 1] ){
            i++;
        }
        else{
            magnet2[count2] = magnet[i];
            count2++;
        }
    }
    /*for( i = 0 ; i < count2 ; i++ ){
        printf("%d ",magnet2[i]);
    }
    printf("\n");*/
    for( i = 0 ; i < q ; i++ ){
        scanf("%d",&f);
        if( count2 == 0 ){
            printf("%d\n",nm);
        }
        else if( f < magnet2[0] ){
            printf("%d\n",magnet2[0] - 1);
        }
        else if( f >= magnet2[count2 - 1] ){
            printf("%d\n",nm - magnet2[count2 - 1] + 1 );
        }
        else{
            start = 0;
            end = count2 - 1;
            while( 1 ){
                mid = ( start + end ) / 2;
                if( magnet2[start] == f ){
                    printf("%d\n",magnet2[start + 1] - magnet2[start] );
                    break;
                }
                else if( magnet2[end] == f ){
                    printf("%d\n",magnet2[end + 1] - magnet2[end] );
                    break;
                }
                else if( start + 1 == end ){
                    printf("%d\n",magnet2[end] - magnet2[start] );
                    break;
                }
                else if( f <= magnet2[mid] ){
                    end = mid;
                }
                else if( f > magnet2[mid] ){
                    start = mid;
                }
            }
        }
    }
    return 0;
}
