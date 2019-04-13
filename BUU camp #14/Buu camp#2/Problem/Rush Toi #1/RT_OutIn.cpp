#include<bits/stdc++.h>

using namespace std;
struct no{
    int x, y, w;
}te;

int mark[35][35];
int qu, sp = -1, an, alno;
char m[35][35];
queue< no > q;
void cle()
{
    for( int i = 0 ; i < 35 ; i++ ){
        for( int j = 0 ; j < 35 ; j++ ){
            mark[i][j] = 0;
        }
    }
    while(!q.empty()){
        q.pop();
    }
}
int main()
{
    scanf("%d",&qu);
    while( qu-- ){
        cle();
        alno = 0;
        int r, c, t, si, sj, ei, ej;
        scanf("%d %d %d",&r,&c,&t);
        for( int i = 0 ; i < r ; i++ ){
            scanf("%s",m[i]);
        }
        sp = -1;
        scanf("%d %d %d %d",&si,&sj,&ei,&ej);
        si -= 1, sj -= 1, ei -= 1, ej -= 1;
        mark[si][sj] = 1;
        q.push({ si, sj, 0 });
        while( !q.empty() ){
            alno++;
            te = q.front();
            mark[te.x][te.y] = 1;
            q.pop();
            if( te.x == ei && te.y == ej ){
                sp = te.w;
            }
            if( te.x - 1 >= 0 )
                if( m[te.x - 1][te.y] == '.' && !mark[te.x - 1][te.y] ){
                    q.push({ te.x - 1, te.y, te.w + 1 });
                    mark[te.x - 1][te.y] = 1;
                }
            if( te.x + 1 < r )
                if( m[te.x + 1][te.y] == '.' && !mark[te.x + 1][te.y] ){
                    q.push({ te.x + 1, te.y, te.w + 1 });
                    mark[te.x + 1][te.y] = 1;
                }
            if( te.y - 1 >= 0 )
                if( m[te.x][te.y - 1] == '.' && !mark[te.x][te.y - 1] ){
                    q.push({ te.x, te.y - 1, te.w + 1 });
                    mark[te.x][te.y - 1] = 1;
                }
            if( te.y + 1 < c )
                if( m[te.x][te.y + 1] == '.' && !mark[te.x][te.y + 1] ){
                    q.push({ te.x, te.y + 1, te.w + 1 });
                    mark[te.x][te.y + 1] = 1;
                }
        }
        if( sp == -1 || sp > t ){
            printf("-1\n");
            continue;
        }
        int th = (t-sp)/2;
        printf("%d\n",sp + min( th, alno - sp - 1 ) + 1);
    }
}
/*
3
5 8 9
#..#..#.
.#...##.
##.##..#
...##.##
##.#..##
4 3 2 4
4 5 100
.....
.####
...#.
#.##.
3 3 1 3
3 5 2
.....
.####
.....
3 3 1 3
*/
