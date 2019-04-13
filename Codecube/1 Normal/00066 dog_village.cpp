#include<bits/stdc++.h>

using namespace std;
struct qq{
    int x, y, lv;
}t;
queue<qq> q;
int r, c, cnt;
int ma[1010][1010], mark[1010][1010], wa[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    scanf("%d %d",&r,&c);
    for( int i = 1 ; i <= r;  i++ ){
        for( int j = 1 ; j <= c ; j++ ){
            scanf("%d",&ma[i][j]);
            if( ma[i][j] == 0 ) q.push({ i, j, 0 });
        }
    }
    while( !q.empty() ){
        t = q.front();
        q.pop();
        mark[t.x][t.y] = 1;
        for( int i = 0 ; i < 4 ; i++ ){
            if( t.x + wa[i][0] >= 1 && t.x + wa[i][0] <= r && t.y + wa[i][1] >=1 && t.y + wa[i][1] <= c ){
                if( ma[t.x + wa[i][0]][t.y + wa[i][1]] > t.lv + 1 && !mark[t.x + wa[i][0]][t.y + wa[i][1]]){
                    mark[t.x + wa[i][0]][t.y + wa[i][1]] = 1;
                    q.push({ t.x + wa[i][0], t.y + wa[i][1], t.lv + 1 });
                }
            }
        }
    }
    for( int i = 1 ; i <= r ; i++ ){
        for( int j = 1 ; j <= c ; j++ ){
            if( !mark[i][j] ) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}

