#include<stdio.h>

int sum[65][65], i, j, m, n, num, counts = 1, mark[65][65],k ,maxs = 0,bucket[2051], y, miny, l, o;
char plan[65][65];

int pond( int x, int y, int number ){
    mark[x][y] = number;
    //printf("%d %d %d\n",x,y,number);
    if( x < 1 || x > m || y < 1 || y > n ){
        return 0;
    }
    if( plan[x - 1][y] == 'P' && mark[x - 1][y] == 0 ){
        pond( x - 1 , y, number );
    }
    if( plan[x][y - 1] == 'P' && mark[x][y - 1] == 0 ){
        pond( x , y - 1, number );
    }
    if( plan[x][y + 1] == 'P' && mark[x][y + 1] == 0 ){
        pond( x , y + 1 , number );
    }
    if( plan[x + 1][y] == 'P' && mark[x + 1][y] == 0 ){
        pond( x + 1 , y, number );
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            scanf(" %c",&plan[i][j]);
            if( plan[i][j] == 'T' ){
                num = 0;
            }
            else{
                num = 1;
            }
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num;
        }
    }
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            if( plan[i][j] == 'P' && mark[i][j] == 0 ){
                pond( i , j , counts );
                counts++;
            }
        }
    }
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            k  = maxs;
            if( i + k <= m && j + k <= n && sum[i+k][j+ k] - sum[i+k][j - 1] - sum[i - 1][j + k] + sum[i - 1][j - 1] == ( k + 1 ) * ( k + 1 ) ){
                y = 0;
                for( l = i ; l <= i + k ; l++ ){
                    for( o = j ; o <= j + k ; o++ ){
                        if( mark[l][o] != 0 ){
                            bucket[mark[l][o]] = 1;
                        }
                    }
                }
                for( l = 1 ; l <= 2050 ; l++ ){
                    if( bucket[l] == 1 ){
                        y++;
                        bucket[l] = 0;
                    }
                }
                if( y < miny){
                    miny = y;
                }
            }
            else
                continue;
            for( k = maxs + 1 ; i + k <= m && j + k <= n ; k++ ){
                if( sum[i+k][j+ k] - sum[i+k][j - 1] - sum[i - 1][j + k] + sum[i - 1][j - 1] == ( k + 1 ) * ( k + 1 ) ){
                    maxs = k;
                    y = 0;
                    for( l = i ; l <= i + k ; l++ ){
                        for( o = j ; o <= j + k ; o++ ){
                            if( mark[l][o] != 0 ){
                                bucket[mark[l][o]] = 1;
                            }
                        }
                    }
                    for( l = 1 ; l <= 2050 ; l++ ){
                        if( bucket[l] == 1 ){
                            y++;
                            bucket[l] = 0;
                        }
                    }
                    miny = y;
                }
            else
                break;
            }
        }
    }
    if(maxs==0)
        printf("0 0\n");
    else
    printf("%d %d\n",(maxs + 1) * ( maxs + 1 ),miny);
    return 0;
}
