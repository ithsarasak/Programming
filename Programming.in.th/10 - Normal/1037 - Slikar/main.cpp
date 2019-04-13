#include<stdio.h>
#include<queue>

using namespace std;

struct node{
    int r,c,step;
}t,temp;
queue <node> q;
queue <node> p;
int n, i, j, m, d = 1;
char map[51][51];
int poswx, poswy, pospx, pospy, posfx, posfy, l, a, o;
int stepp, stepw;
int check[50][50], sol[50][50];
int main()
{
    scanf("%d %d",&n,&m);

    for( i = 1 ; i <= n ; i++ )
    {
        scanf("%s",&map[i][1]);
    }
    for( i = 1 ; i <= n ; i++ )
    {
        for( j = 1 ; j <= m ; j++ )
        {
            if( map[i][j] == '*' )
            {
                a = 1;
                poswx = i;
                poswy = j;
                q.push({poswx,poswy,1});
            }
            else if( map[i][j] == 'D' )
            {
                l = 1;
                posfx = i;
                posfy = j;
            }
            else if( map[i][j] == 'S' )
            {
                o = 1;
                pospx = i;
                pospy = j;
            }
        }
    }
    if( !o || !l )
    {
        printf("KAKTUS");

        return 0;
    }
    if( a )
    {
        q.push({poswx,poswy,1});
        check[poswx][poswy] = 1;
        sol[poswx][poswy] = 1;
    }
    p.push({pospx,pospy,1});
    check[pospx][pospy] = 1;
    sol[pospx][pospy] = 1;

    while( !q.empty() || !p.empty() )
    {
        /*for(int i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",check[i][x]);
            }
            printf("\n");
        }
        printf("\n");*/

        /*for(int i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",sol[i][x]);
            }
            printf("\n");
        }
        printf("\n");*/
        while( !q.empty() && a )
        {
            t = q.front();

            if(t.step != d)
            {
                break;
            }

            q.pop();

            stepw = t.step,poswx = t.r,poswy = t.c;

            sol[poswx][poswy] = stepw;

            if(poswx + 1 <= n && check[poswx + 1][poswy] == 0 && map[poswx+1][poswy] != 'D' && map[poswx+1][poswy] != 'X' )
            {
                check[poswx + 1][poswy] = 1;

                q.push({poswx + 1,poswy,stepw + 1});
            }

            if(poswx - 1 >= 1 && check[poswx - 1][poswy] == 0 && map[poswx-1][poswy] != 'D' && map[poswx-1][poswy] != 'X' )
            {
                check[poswx - 1][poswy] = 1;

                q.push({poswx - 1,poswy,stepw + 1});
            }

            if(poswy + 1 <= m && check[poswx][poswy + 1] == 0 && map[poswx][poswy+1] != 'D' && map[poswx][poswy+1] != 'X' )
            {
                check[poswx][poswy + 1] = 1;

                q.push({poswx,poswy + 1,stepw + 1});
            }

            if(poswy - 1 >= 1 && check[poswx][poswy - 1] == 0 && map[poswx][poswy-1] != 'D' && map[poswx][poswy-1] != 'X' )
            {
                check[poswx][poswy - 1] = 1;

                q.push({poswx,poswy - 1,stepw + 1});
            }

        }
        /*for(int i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",check[i][x]);
            }
            printf("\n");
        }
        printf("\n");*/

        /*for(int i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",sol[i][x]);
            }
            printf("\n");
        }
        printf("\n");*/
        while( !p.empty() )
        {
            temp = p.front();

            if(temp.step != d)
            {
                break;
            }
            p.pop();

            stepp = temp.step,pospx = temp.r,pospy = temp.c;

            sol[pospx][pospy] = stepp;
            if( map[pospx][pospy] == 'D' )
            {
                printf("%d",stepp-1);
                return 0;
            }

            if( pospx + 1 <= n && check[pospx + 1][pospy] == 0 && map[pospx+1][pospy] != 'X' )
            {
                check[pospx + 1][pospy] = 1;

                p.push({pospx + 1,pospy,stepp + 1});
            }

            if( pospx - 1 >= 1 && check[pospx - 1][pospy] == 0 && map[pospx-1][pospy] != 'X' )
            {
                check[pospx - 1][pospy] = 1;

                p.push({pospx - 1,pospy,stepp + 1});
            }

            if( pospy + 1 <= m && check[pospx][pospy + 1] == 0 && map[pospx][pospy+1] != 'X' )
            {
                check[pospx][pospy + 1] = 1;

                p.push({pospx,pospy + 1,stepp + 1});
            }

            if( pospy - 1 >= 1 && check[pospx][pospy - 1] == 0 && map[pospx][pospy-1] != 'X' )
            {
                check[pospx][pospy - 1] = 1;

                p.push({pospx,pospy - 1,stepp + 1});
            }
        }
        d++;
        /*for(int i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",check[i][x]);
            }
            printf("\n");
        }
        printf("\n");*/

        /*for(int i = 1; i <= n; i++)
        {
            for(int x = 1; x <= m; x++)
            {
                printf("%d ",sol[i][x]);
            }
            printf("\n");
        }
        printf("\n");*/
    }
    if( !check[posfx][posfy] )
    {
        printf("KAKTUS");
    }
}
