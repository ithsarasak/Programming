#include<bits/stdc++.h>

using namespace std;
struct po{
    int x, y, d;
}t;
char ma[1010][1010];
int r, c, xa, ya, xb, yb, qq;
int mark[1010][1010];
queue<po> q;
int main()
{
    scanf("%d",&qq);
    while( qq-- ){
        memset( mark, 0, sizeof mark );
        while( !q.empty() )q.pop();
        scanf("%d %d",&r,&c);
        for( int i = 1 ; i <= r ; i++ ){
            scanf("%s",&ma[i][1]);
        }
        for( int i =1  ; i <= r ; i++ ){
            for( int j = 1 ; j <= c ; j++ ){
                if( ma[i][j] == 'A' ) xa = i,ya = j;
                else if( ma[i][j] == 'B' )xb = i, yb = j;
            }
        }
        q.push({ xa, ya, 0 });
        while( !q.empty() ){
            t = q.front();
            mark[t.x][t.y] = t.d;
            q.pop();
            if( ( ma[t.x-1][t.y] == '.' ||  ma[t.x-1][t.y] == 'B' ) && !mark[t.x-1][t.y] ){
                mark[t.x-1][t.y] = t.d+1;
                q.push({ t.x-1, t.y , t.d+1 });
            }
            if(  (ma[t.x+1][t.y] == '.' ||  ma[t.x+1][t.y] == 'B' ) && !mark[t.x+1][t.y] ){
                mark[t.x+1][t.y] = t.d+1;
                q.push({ t.x+1, t.y , t.d+1 });
            }
            if( ( ma[t.x][t.y-1] == '.' ||  ma[t.x][t.y-1] == 'B' ) && !mark[t.x][t.y-1] ){
                mark[t.x][t.y-1] = t.d+1;
                q.push({ t.x, t.y-1 , t.d+1 });
            }
            if( ( ma[t.x][t.y+1] == '.' ||  ma[t.x][t.y+1] == 'B' ) && !mark[t.x][t.y+1] ){
                mark[t.x][t.y+1] = t.d+1;
                q.push({ t.x, t.y+1 , t.d+1 });
            }
        }
        if( !mark[xb][yb] )printf("-1\n");
        else printf("%d\n",mark[xb][yb]);
    }
    return 0;
}
