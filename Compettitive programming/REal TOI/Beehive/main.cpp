#include<stdio.h>

struct bee{
    int way = 0,sumhoney;
}sum[1002][1002];
int m, n, i, j, max, hive[1002][1002], count;
int main()
{
    scanf("%d %d",&m,&n);

    for( i = 1 ; i <= m ; i++ ){
        for( j = 1; j <= n ; j++ ){
                scanf("%d",&hive[i][j]);
            if( i == 1 ){
                sum[i][j].sumhoney = hive[i][j];
                sum[i][j].way = 1;
            }
            else if( i % 2 == 0 ){
                if( sum[i-1][j].sumhoney == sum[i-1][j+1].sumhoney ){
                    sum[i][j].sumhoney = hive[i][j] + sum[i-1][j+1].sumhoney;
                    sum[i][j].way = sum[i-1][j].way + sum[i-1][j+1].way;
                }
                else{
                    if( sum[i-1][j].sumhoney > sum[i-1][j+1].sumhoney ){
                        sum[i][j].sumhoney = hive[i][j] + sum[i-1][j].sumhoney;
                        sum[i][j].way =  sum[i-1][j].way;
                    }
                    else{
                        sum[i][j].sumhoney = hive[i][j] + sum[i-1][j+1].sumhoney;
                        sum[i][j].way = sum[i-1][j+1].way;
                    }
                }
            }
            else{
                if( sum[i-1][j-1].sumhoney == sum[i-1][j].sumhoney ){
                    sum[i][j].sumhoney = hive[i][j] + sum[i-1][j-1].sumhoney;
                    sum[i][j].way = sum[i-1][j].way + sum[i-1][j-1].way;
                }
                else{
                    if( sum[i-1][j].sumhoney > sum[i-1][j-1].sumhoney ){
                        sum[i][j].sumhoney = hive[i][j] + sum[i-1][j].sumhoney;
                        sum[i][j].way =  sum[i-1][j].way;
                    }
                    else{
                        sum[i][j].sumhoney = hive[i][j] + sum[i-1][j-1].sumhoney;
                        sum[i][j].way = sum[i-1][j-1].way;
                    }
                }
                /*printf("%d ",sum[i][j].way);
                printf("%d ",sum[i][j].sumhoney);*/
            }
        }
        //printf("\n");
    }
    j = m ;

    for( i = 1 ; i <= n ; i++ ){
        if( max < sum[j][i].sumhoney ){
            max = sum[j][i].sumhoney;
            count = sum[j][i].way;
        }
        else if( max == sum[j][i].sumhoney ){
            count += sum[j][i].way;
        }
    }
    printf("%d %d",max,count);
}
