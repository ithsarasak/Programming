#include<stdio.h>

int r, c, limit, i, j, k, house[301][301], sum[301][301], max = -999999999;
int main()
{
    scanf("%d %d %d",&r,&c,&limit);

    for( i = 1 ; i <= r ; i++ ){
        for( j = 1 ; j <= c ; j++ ){
            scanf("%d",&house[i][j]);
        }
    }

    for( i = 1 ; i <= r ; i++ ){
        for( j = 1 ; j <= c ; j++ ){
            int count = 0;
            //printf("i : %d j : %d\n",i,j);
            for( k = j - 1 ; k >= 1 ; k-- ){
               //printf("k : %d count : %d\n",k,count);
                if( count >= limit ){
                    break;
                }
                if( ( j - k ) % 2 == 1 ){
                    sum[i][j] -= house[i][k];
                }
                else{
                    sum[i][j] += house[i][k];
                }
                //printf("sum[%d][%d] : %d\n",i, j, sum[i][j]);
                count++;
            }
            count = 0;
            for( k = j + 1 ; k <= c ; k++ ){
                //printf("k : %d count : %d\n",k,count);
                if( count >= limit ){
                    break;
                }
                if( ( k - j ) % 2 == 1 ){
                    sum[i][j] -= house[i][k];
                }
                else{
                    sum[i][j] += house[i][k];
                }
                //printf("sum[%d][%d] : %d\n",i, j, sum[i][j]);
                count++;
            }
            count = 0;
            for( k = i - 1 ; k >= 1 ; k-- ){
                //printf("k : %d count : %d\n",k,count);
                if( count >= limit ){
                    break;
                }
                if( ( i - k ) % 2 == 1 ){
                    sum[i][j] -= house[k][j];
                }
                else{
                    sum[i][j] += house[k][j];
                }
                //printf("sum[%d][%d] : %d\n",i, j, sum[i][j]);
                count++;
            }
            count = 0;
            for( k = i + 1 ; k <= r ; k++ ){
                //printf("k : %d count : %d\n",k,count);
                if( count >= limit ){
                    break;
                }
                if( ( k - i ) % 2 == 1 ){
                    sum[i][j] -= house[k][j];
                }
                else{
                    sum[i][j] += house[k][j];
                }
                //printf("sum[%d][%d] : %d\n",i, j, sum[i][j]);
                count++;
            }
            sum[i][j] += house[i][j] ;
            if( max < sum[i][j] ){
                max = sum[i][j];
            }
            //printf("sum[%d][%d] : %d max : %d\n",i, j, sum[i][j], max);
        }
    }
    printf("%d",max);
}
