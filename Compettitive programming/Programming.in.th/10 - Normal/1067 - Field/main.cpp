#include<stdio.h>

struct node{
    int px, py;
}map[102][102];
int i, j, m, n, k, field[102][102], x, y, posx, posy;

int main()
{
    scanf("%d %d %d",&m,&n,&k);

    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= m ; j++ ){
            scanf("%d",&field[i][j]);
            //printf("field[%d][%d] : %d ",i,j,field[i][j]);
            if( field[i][j] == 1 ){
                map[i][j].px = i - 1;
                map[i][j].py = j;
            }
            else if( field[i][j] == 2 ){
                map[i][j].px = i;
                map[i][j].py = j + 1;
            }
            else if( field[i][j] == 3 ){
                map[i][j].px = i + 1;
                map[i][j].py = j;
            }
            else if( field[i][j] == 4 ){
                map[i][j].px = i;
                map[i][j].py = j - 1;
            }
        }
        //printf("\n");
    }
    /*for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= m ; j++ ){
            printf("map[%d][%d] : x :%d y : %d\n",i,j,map[i][j].px,map[i][j].py);
        }
    }*/
    for( i = 0 ; i < k ; i++ ){
        scanf("%d %d",&y,&x);
        //printf("%d\n",field[x][y]);
        int tempx, tempy, path[102][102];

        for( int k = 0 ; k < 102 ; k++ ){
            for( int l = 0 ; l < 102 ; l++ ){
                path[k][l] = 0;
            }
        }
        path[x][y] = 1;
        posx = map[x][y].px;
        posy = map[x][y].py;
        tempx = posx;
       /// printf("%d %d\n",posx,posy);
        while( posx <= n && posx > 0 && posy <= m && posy > 0 && path[posx][posy] != 1 ){
            path[posx][posy] = 1;
            tempx = posx;
            //printf("posx : %d posy : %d\n",posx,posy);
            posx = map[posx][posy].px;
            posy = map[tempx][posy].py;
        }
        //posx = tempx;
        //return 0;
        /*printf("posx : %d posy : %d\n",posx,posy);
        printf("m : %d n : %d\n",m,n);*/
        if( posx > n ){
            printf("S\n");
        }
        else if( posx < 1 ){
            printf("N\n");
        }
        else if( posy < 1 ){
            printf("W\n");
        }
        else if( posy > m ){
            printf("E\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
