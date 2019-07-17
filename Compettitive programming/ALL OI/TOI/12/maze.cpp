#include<stdio.h>
#include<queue>

using namespace std;

int i, j, startx, starty, endx, endy, maze[200][200], m, n, mins = 500, counts, check;
struct flag{
    int level = 0;
    int types;
}mark[200][200];
struct maps{
    int x, y, lv;
    int type;
}temp;
queue<maps> q, p;
int main()
{
    scanf("%d %d",&m,&n);
    scanf("%d %d",&startx,&starty);
    scanf("%d %d",&endx,&endy);
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            scanf("%d",&maze[i][j]);
        }
    }
    q.push( { startx, starty, 1, 1 } );
    while( !q.empty() ){
        temp = q.front();
        mark[temp.x][temp.y].level = temp.lv;
        mark[temp.x][temp.y].types = temp.type;
        q.pop();
        if( maze[temp.x - 1][temp.y] == 1 && mark[temp.x - 1][temp.y].level == 0 ){
            mark[temp.x - 1][temp.y].level = temp.lv + 1;
            mark[temp.x - 1][temp.y].types = temp.type;
            q.push({ temp.x - 1 , temp.y , temp.lv + 1 , 1 });
        }
        if( maze[temp.x][temp.y - 1] == 1 && mark[temp.x][temp.y - 1].level == 0 ){
            mark[temp.x][temp.y - 1].level = temp.lv + 1;
            mark[temp.x][temp.y - 1].types = temp.type;
            q.push({ temp.x , temp.y - 1 , temp.lv + 1 , 1 });
        }
        if( maze[temp.x][temp.y + 1] == 1 && mark[temp.x][temp.y + 1].level == 0 ){
            mark[temp.x][temp.y + 1].level = temp.lv + 1;
            mark[temp.x][temp.y + 1].types = temp.type;
            q.push({ temp.x , temp.y + 1 , temp.lv + 1 , 1 });
        }
        if( maze[temp.x + 1][temp.y] == 1 && mark[temp.x + 1][temp.y].level == 0 ){
            mark[temp.x + 1][temp.y].level = temp.lv + 1;
            mark[temp.x + 1][temp.y].types = temp.type;
            q.push({ temp.x + 1 , temp.y , temp.lv + 1 , 1 });
        }
    }
    p.push( { endx, endy, 1, 2 } );
    while( !p.empty() ){
        temp = p.front();
        mark[temp.x][temp.y].level = temp.lv;
        mark[temp.x][temp.y].types = temp.type;
        p.pop();
        if( maze[temp.x - 1][temp.y] == 1 && mark[temp.x - 1][temp.y].level == 0 ){
            mark[temp.x - 1][temp.y].level = temp.lv + 1;
            mark[temp.x - 1][temp.y].types = temp.type;
            p.push({ temp.x - 1 , temp.y , temp.lv + 1 , 2 });
        }
        if( maze[temp.x][temp.y - 1] == 1 && mark[temp.x][temp.y - 1].level == 0 ){
            mark[temp.x][temp.y - 1].level = temp.lv + 1;
            mark[temp.x][temp.y - 1].types = temp.type;
            p.push({ temp.x , temp.y - 1 , temp.lv + 1 , 2 });
        }
        if( maze[temp.x][temp.y + 1] == 1 && mark[temp.x][temp.y + 1].level== 0 ){
            mark[temp.x][temp.y + 1].level = temp.lv + 1;
            mark[temp.x][temp.y + 1].types = temp.type;
            p.push({ temp.x , temp.y + 1 , temp.lv + 1 , 2 });
        }
        if( maze[temp.x + 1][temp.y] == 1 && mark[temp.x + 1][temp.y].level == 0 ){
            mark[temp.x + 1][temp.y].level = temp.lv + 1;
            mark[temp.x + 1][temp.y].types = temp.type;
            p.push({ temp.x + 1 , temp.y , temp.lv + 1 , 2 });
        }
    }
    /*for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            printf("%d ",mark[i][j].level);
        }
        printf("\n");
    }*/
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
                check = 0;
            if( maze[i][j] == 0 ){
                if( mark[i - 1][j].types + mark[i][j - 1].types == 3 ){
                    if( mark[i - 1][j].level + mark[i][j - 1].level < mins ){
                        mins = mark[i - 1][j].level + mark[i][j - 1].level;
                    }
                    check = 1;
                }
                if( mark[i - 1][j].types + mark[i][j + 1].types == 3 ){
                    if( mark[i - 1][j].level + mark[i][j + 1].level < mins ){
                        mins = mark[i - 1][j].level + mark[i][j + 1].level;
                    }
                    check = 1;
                }
                if( mark[i - 1][j].types + mark[i + 1][j].types == 3 ){
                    if( mark[i - 1][j].level + mark[i + 1][j].level < mins ){
                        mins = mark[i - 1][j].level + mark[i + 1][j].level;
                    }
                    check = 1;
                }
                if( mark[i + 1][j].types + mark[i][j - 1].types == 3 ){
                    if( mark[i + 1][j].level + mark[i][j - 1].level < mins ){
                        mins = mark[i + 1][j].level + mark[i][j - 1].level;
                    }
                    check = 1;
                }
                if( mark[i + 1][j].types + mark[i][j + 1].types == 3 ){
                    if( mark[i + 1][j].level + mark[i][j + 1].level < mins ){
                        mins = mark[i + 1][j].level + mark[i][j + 1].level;
                    }
                    check = 1;
                }
                if( mark[i][j - 1].types + mark[i][j + 1].types == 3 ){
                    if( mark[i][j - 1].level + mark[i][j + 1].level < mins ){
                        mins = mark[i][j - 1].level + mark[i][j + 1].level;
                    }
                    check = 1;
                }
                if( check ){
                    counts++;
                }
            }
        }
    }
    printf("%d\n%d",counts,mins + 1);
    return 0;
}

