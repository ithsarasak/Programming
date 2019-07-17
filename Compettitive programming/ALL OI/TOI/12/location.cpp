#include<stdio.h>
int location[1000][1000], i, j, m, n, k, sum[1000][1000], max;
int main()
{
    scanf("%d %d",&m,&n);

    scanf("%d",&k);

    for( i = 0 ; i < m ; i++ ){
        for( j = 0 ; j < n ; j++ ){
                scanf("%d",&location[i][j]);
            if( i == 0 && j == 0 ){
                sum[i][j] = location[i][j];
            }
            else if( i == 0 ){
                sum[i][j] += sum[i][j-1] + location[i][j];
            }
            else if( j == 0 ){
                sum[i][j] += sum[i-1][j] + location[i][j];
            }
            else{
                sum[i][j] += ( sum[i-1][j] + sum[i][j-1] + location[i][j] ) - sum[i-1][j-1];
            }
        }
    }
    for( i = k - 1 ; i < m ; i++ ){
        for( j = k - 1 ; j < n ; j++ ){
            if( i == k - 1 && j == k - 1 ){
                max = sum[i][j];
            }
            else if( i == k - 1 ){
                if( max < sum[i][j] - sum[i][j-k] ){
                    max = sum[i][j] - sum[i][j-k];
                }
            }
            else if( j == k - 1 ){
                if( max < sum[i][j] - sum[i-k][j] ){
                    max = sum[i][j] - sum[i-k][j];
                }
            }
            else{
                if( max < sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k] ){
                    max = sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k];
                }
            }
        }
    }
    printf("%d",max);
}

