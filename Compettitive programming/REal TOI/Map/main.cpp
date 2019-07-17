#include<stdio.h>
int check[400], map[1000][1000], i, j, m, n, start, minx, miny, maxx, maxy, x;
struct tre{
    int num1, num2, check = 1;
    char pos;
}all[400];
struct point{
    int posx, posy;
}way[400];
int build( int posi )
{
    int i;
    for( i = 0 ; i < x - 1 ; i++ ){
        if( all[i].num1 == posi && all[i].check ){
            if( all[i].pos == 'U' ){
                way[all[i].num2].posx = way[posi].posx + 1;
                way[all[i].num2].posy = way[posi].posy;
                all[i].check = 0;
                map[way[all[i].num2].posx][way[all[i].num2].posy] = all[i].num2;
            }
            else{
                way[all[i].num2].posx = way[posi].posx;
                way[all[i].num2].posy = way[posi].posy + 1;
                all[i].check = 0;
                map[way[all[i].num2].posx][way[all[i].num2].posy] = all[i].num2;
            }
            if( maxx < way[all[i].num2].posx ){
                maxx = way[all[i].num2].posx;
            }
            else if( minx > way[all[i].num2].posx ){
                minx = way[all[i].num2].posx;
            }
            if( maxy < way[all[i].num2].posy ){
                maxy = way[all[i].num2].posy;
            }
            else if( miny > way[all[i].num2].posy ){
                miny = way[all[i].num2].posy;
            }
            build( all[i].num2 );
        }
        else if( all[i].num2 == posi && all[i].check ){
            if( all[i].pos == 'U' ){
                way[all[i].num1].posx = way[posi].posx - 1;
                way[all[i].num1].posy = way[posi].posy;
                all[i].check = 0;
                map[way[all[i].num1].posx][way[all[i].num1].posy] = all[i].num1;
            }
            else{
                way[all[i].num1].posx = way[posi].posx;
                way[all[i].num1].posy = way[posi].posy - 1;
                all[i].check = 0;
                map[way[all[i].num1].posx][way[all[i].num1].posy] = all[i].num1;
            }
            if( maxx < way[all[i].num2].posx ){
                maxx = way[all[i].num2].posx;
            }
            else if( minx > way[all[i].num2].posx ){
                minx = way[all[i].num2].posx;
            }
            if( maxy < way[all[i].num2].posy ){
                maxy = way[all[i].num2].posy;
            }
            else if( miny > way[all[i].num2].posy ){
                miny = way[all[i].num2].posy;
            }
            build( all[i].num1 );
        }
    }
    return 0;
}
int main()
{
    scanf("%d %d",&m,&n);
    x = m * n;

    for( i = 0 ; i < x - 1 ; i++ ){
        scanf("%d %c %d",&all[i].num1,&all[i].pos,&all[i].num2);

        check[all[i].num1]++;
        check[all[i].num2]++;
    }
    for( i = 0 ; i < x ; i++ ){
        if( check[i] == 1 ){
            map[500][500] = i;
            way[i].posx = 500;
            way[i].posy = 500;
            minx = 500;
            miny = 500;
            maxx = 500;
            maxy = 500;
            start = i;
            break;
        }
    }
    build( start );

    for( i =  minx; i <= maxx ; i++ ){
        for( j = miny ; j <= maxy ; j++ ){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}
