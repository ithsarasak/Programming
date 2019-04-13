#include<bits/stdc++.h>

using namespace std;
struct po{
    int x, y;
}t;
int px[4] = { 1, 0, -1, 0 };
int py[4] = { 0, 1, 0, -1 };
int r, c, ma[1010][1010], visit[1010][1010], qq;
queue<po> q;
void bfs( int x, int y )
{
    int co = 0;
    q.push({ x, y });
    while( !q.empty() ){
        t = q.front();
        q.pop();
        if( ma[t.x][t.y] == 2 ){
            co++;
        }
        visit[t.x][t.y] = 1e9;
        for( int i = 0 ; i < 4 ; i++ ){
            if( t.x + px[i] > 0 && t.x + px[i] <= r && t.y + py[i] > 0 && t.y + py[i] <= c ){
                if( visit[t.x + px[i]][t.y + py[i]] == -1 && ma[t.x + px[i]][t.y + py[i]] != 0 ){
                    visit[t.x + px[i]][t.y + py[i]] = 1e9;
                    q.push({ t.x + px[i], t.y + py[i] });
                }
            }
        }
    }
    q.push({x, y});
    while( !q.empty() ){
        t = q.front();
        q.pop();
        visit[t.x][t.y] = co;
        for( int i = 0 ; i < 4 ; i++ ){
            if( t.x + px[i] > 0 && t.x + px[i] <= r && t.y + py[i] > 0 && t.y + py[i] <= c ){
                if( visit[t.x + px[i]][t.y + py[i]] == 1e9 && ma[t.x + px[i]][t.y + py[i]] != 0 ){
                    visit[t.x + px[i]][t.y + py[i]] = co;
                    q.push({ t.x + px[i], t.y + py[i] });
                }
            }
        }
    }
    /*for( int i = 1 ; i <= r ; i++ ){
        for( int j =1  ; j <=c ; j++ ){
            printf("%d ",visit[i][j]);
        }
        printf("\n");
    }*/
}
int main()
{
    memset( visit, -1, sizeof visit );
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%d",&ma[i][j]);
        }
    }
    for( int i = 1 ; i <= r ; i++ ){
        for(int j = 1 ; j <= c ; j++ ){
            if( ma[i][j] == 3 && visit[i][j] == -1 ){
                //printf("%d %d\n",i,j);
                bfs( i, j );
            }
        }
    }
    scanf("%d",&qq);
    for(int i = 0 ; i < qq ; i++ ){
        int a, b;
        scanf("%d %d",&a,&b);
        printf("%d\n",visit[a][b]);
    }
    return 0;
}
/*
10 13
0 1 3 3 0 0 2 0 1 3 0 2 1
0 1 1 1 0 3 1 0 1 0 1 0 3
2 1 2 1 1 3 1 0 0 0 1 0 1
0 0 2 1 2 0 0 1 2 3 0 0 1
1 0 0 1 1 3 0 3 0 3 0 1 1
1 3 0 0 0 2 0 0 1 2 0 1 0
1 0 0 3 0 1 1 0 1 2 0 1 2
0 1 2 2 0 3 1 2 0 1 1 0 1
1 3 3 0 0 1 0 1 0 1 0 1 3
0 0 2 1 0 1 2 0 0 0 0 2 3
10
1 3
1 10
2 13
10 13
9 2
9 13
1 4
3 6
5 10
8 6
*/
