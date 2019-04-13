#include<stdio.h>
int k, n, m, right[1010][1010], up[1010][1010], down[1010][1010], left[1010][1010], max, i, j ,l;
char board[1010][1010];
int main()
{
    scanf("%d",&k);
    for( i = 0 ; i < k ; i++ ){
        max = 0;
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                left[j][l] = 0;
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                down[j][l] = 0;
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                up[j][l] = 0;
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                right[j][l] = 0;
            }
        }
        scanf("%d %d",&n,&m);
        for( j = 1 ; j <= n ; j++ ){
            scanf("%s",&board[j][1]);
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                if( board[j][l] == '0' ){
                    left[j][l] = 0;
                }
                else{
                    left[j][l] = left[j][l - 1] + 1;
                }
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = m ; l >= 1 ; l-- ){
                if( board[j][l] == '0' ){
                    right[j][l] = 0;
                }
                else{
                    right[j][l] = right[j][l + 1] + 1;
                }
            }
        }
        for( j = n ; j >= 1 ; j-- ){
            for( l = 1 ; l <= m ; l++ ){
                if( board[j][l] == '0' ){
                    down[j][l] = 0;
                }
                else{
                    down[j][l] = down[j + 1][l] + 1;
                }
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                if( board[j][l] == '0' ){
                    up[j][l] = 0;
                }
                else{
                    up[j][l] = up[j - 1][l] + 1;
                }
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                if( max < left[j][l] + up[j][l] - 1 ){
                    max = left[j][l] + up[j][l] - 1;
                }
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                if( max < right[j][l] + up[j][l] - 1 ){
                    max = right[j][l] + up[j][l] - 1;
                }
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                if( max < left[j][l] + down[j][l] - 1 ){
                    max = left[j][l] + down[j][l] - 1;
                }
            }
        }
        for( j = 1 ; j <= n ; j++ ){
            for( l = 1 ; l <= m ; l++ ){
                if( max < right[j][l] + down[j][l] - 1 ){
                    max = right[j][l] + down[j][l] - 1;
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
