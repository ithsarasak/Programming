#include<stdio.h>
int tarang[1010][1010];
int sum[1010][1010], i, j, m, n, x, y, d, fromx, fromy, tox, toy;
int main()
{
    scanf("%d %d",&m,&n);
    for( i = 0 ; i < m ; i ++ ){
        scanf("%d %d",&x,&y);
        tarang[x+1][y+1]++;
    }
    for( i = 1 ; i <= 1001 ; i++ ){
        for( j = 1 ; j<= 1001 ; j++ ){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + tarang[i][j];
        }
    }
    /*for( i = 1 ; i <= 11 ; i++ ){
        for( j = 1 ; j<= 11 ; j++ ){
            sum[i][j] =;
        }
    }*/
    for( i = 0 ; i < n ; i++ ){
        scanf("%d %d %d",&x,&y,&d);
        x +=1;
        y +=1;
        fromx = x - d;
        fromy = y - d;
        tox = x + d;
        toy = y + d;
        if( fromx < 1 ){
            fromx = 1;
        }
        if( fromy < 1 ){
            fromy = 1;
        }
        if( tox > 1001 ){
            tox = 1001;
        }
        if( toy > 1001 ){
            toy = 1001;
        }
        printf("%d\n",sum[tox][toy] + sum[fromx - 1][fromy - 1] - sum[tox][fromy - 1] - sum[fromx - 1][toy] );
    }
    return 0;
}
