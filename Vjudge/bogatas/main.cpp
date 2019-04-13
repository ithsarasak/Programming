#include<bits/stdc++.h>
int i, j, k, n, p, x, y, sum[210][210], maps[210][210], maxs = 1;
int main()
{
    scanf("%d",&n);
    scanf("%d",&p);

    for( i = 0 ; i < p ; i++ ){
        scanf("%d %d",&x,&y);
        maps[x][y] = 1;
    }
    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            sum[i][j] += maps[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            while( 1 ){
                if( i + maxs <= n && j + maxs <= n ){
                    if( sum[i + maxs][j + maxs] - sum[i - 1][j + maxs] - sum[i + maxs][j - 1] + sum[i - 1][j - 1] == 0 ){
                        maxs++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
    }
    printf("%d",maxs);
    return 0;
}
