#include<bits/stdc++.h>
int sum[510][510], maps[510][510];
int i , j, k, m, n, tree, maxs = 1, maxt, l;
int main()
{
    for( l = 0 ; l < 2 ; l++ ){
        memset( sum , 0 , sizeof( sum ) );
        memset( maps , 0 , sizeof( maps ) );
        maxs = 1;
        scanf("%d %d",&m,&n);
        scanf("%d",&tree);
        for( i = 0 ; i < tree ; i++ ){
            int x, y;
            scanf("%d %d",&x,&y);
            maps[x + 1][y + 1] = 1;
        }
        for( i = 1 ; i <= m ; i++ ){
            for( j = 1 ; j <= n ; j++ ){
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + maps[i][j];
            }
        }
        /*for( i = 1 ; i <= m ; i++ ){
            for( j = 1 ; j <= n ; j++ ){
                printf("%d ",sum[i][j]);
            }
            printf("\n");
        }*/
        for( i = 1 ; i <= m ; i++ ){
            for( j = 1 ; j <= n ; j++ ){
                    k = 1;
                    maxt = 1;
                while( i + k - 1 <= m && j + k - 1 <= n ){
                    if( k == 1 ){
                        if( maps[i][j] != 1 && k > maxt ){
                            maxt = k;
                        }
                        k++;
                    }
                    else if( k == 2 ){
                        if( maps[i][j] != 1 && maps[i + 1][j] != 1 && maps[i + 1][j + 1] != 1 && maps[i][j + 1] != 1 ){
                            maxt = k;
                        }
                        k++;
                    }
                    else{
                        int temp1 = sum[i + k - 1][j + k - 1] - sum[i - 1][j + k - 1] - sum[i + k - 1][j - 1] + sum[i - 1][j - 1];
                        int temp2 = sum[i + k - 2][j + k - 2] - sum[i][j + k - 2] - sum[i + k - 2][j] + sum[i][j];
                        if( temp1 - temp2 == 0 && k > maxt ){
                            maxt = k;
                        }
                        /*if( i == 1 && j == 1 ){
                            printf("%d %d %d %d\n",temp1, temp2, maxt, k);
                        }*/
                        k++;
                    }
                }
                if( maxs < maxt - 1 ){
                    //printf("%d %d %d\n",i,j,maxt - 1);
                    maxs = maxt - 1;
                }
            }
        }
        printf("%d\n",maxs + 1);
    }
    return 0;
}

