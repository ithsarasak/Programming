#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

struct town{
    int x, y, step;
    char before;
}t;

queue<town> path1;
queue<town> path2;

int i, j, check[101][101], side1, side2, d = 1;
char sewer[102][102];

int main()
{
    scanf("%d %d",&side1,&side2);

    for( i = 1 ; i <= side1 ; i++ ){
        for( j = 1 ; j <= side2 ; j++ ){
                scanf(" %c",&sewer[i][j]);
        }
    }
    /*for( i = 1 ; i <= side1 ; i++ ){
        for( j = 1 ; j <= side2 ; j++ ){
                printf("%c ",sewer[i][j]);
        }
        printf("\n");
    }*/

    path1.push({ 1, 1, 1, 'a' });
    while( !path1.empty() ){
        while( !path1.empty() ){
            t = path1.front();
            if( check[t.x][t.y] == 1 && t.step != 1 ){
                printf("%d\n%d %d\n\n",t.step,t.x,t.y);
                exit(0);
            }
            if( t.step != d ){
                break;
            }
            /*printf("t.x1 : %d t.y1 : %d t.step : %d\n",t.x,t.y,t.step);
            printf("sewer : %c\n",sewer[t.x][t.y]);*/
            path1.pop();

            if( t.before == 'd' ){
                check[t.x-1][t.y] = 0;
            }
            else if( t.before == 'r' ){
                check[t.x][t.y-1] = 0;
            }
            else if( t.before == 'u' ){
                check[t.x+1][t.y] = 0;
            }
            else if( t.before == 'l' ){
                check[t.x][t.y+1] = 0;
            }

            if( ( sewer[t.x-1][t.y] == 'D' || sewer[t.x-1][t.y] == 'B' ) && t.before != 'd' ){
                check[t.x][t.y] = 1;
                path1.push( { t.x - 1 , t.y , t.step + 1 , 'u' } );
            }
            if( ( sewer[t.x][t.y] == 'D' || sewer[t.x][t.y] == 'B' ) && t.before != 'u' ){
                check[t.x][t.y] = 1;
                path1.push( { t.x + 1 , t.y , t.step + 1 , 'd' } );
            }
            if( ( sewer[t.x][t.y-1] == 'R' || sewer[t.x][t.y-1] == 'B' ) && t.before != 'r' ){
                check[t.x][t.y] = 1;
                path1.push( { t.x , t.y - 1 , t.step + 1 , 'l' } );
            }
            if( ( sewer[t.x][t.y] == 'R' || sewer[t.x][t.y] == 'B' ) && t.before != 'l'  ){
                check[t.x][t.y] = 1;
                path1.push( { t.x , t.y + 1 , t.step + 1 , 'r' } );
            }
            for( i = 1 ; i <= 4 ; i++ ){
                for( j = 1 ; j <= 5 ; j++ ){
                    printf("%d ",check[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        d++;
    }
    return 0;
}
