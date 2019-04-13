#include<bits/stdc++.h>

using namespace std;
struct po{
    int x, y, st;
}t;
queue<po> q;
char ma[2010][2010];
int mark[2010][2010];
int fx[4] = { 1, 0, -1, 0 }, fy[4] = { 0, 1, 0, -1 };
int m, n, ans, all;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i <n ; i++ ){
        scanf("%s",ma[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            if( ma[i][j] == 'X' ){
                q.push({i,j,0});
            }
        }
    }
    while( !q.empty() ){
        t = q.front();
        q.pop();
        if( ma[t.x][t.y] == 'A' ){
            ans += t.st*2;
            all++;
        }
        for( int i = 0 ; i < 4 ; i++ ){
            if( t.x + fx[i] >= 0 && t.x + fx[i] < n && t.y + fy[i] >= 0 && t.y + fy[i] < m ){
                if( ma[t.x + fx[i]][t.y + fy[i]] != 'W' && !mark[t.x + fx[i]][t.y + fy[i]] ){
                    mark[t.x + fx[i]][t.y + fy[i]] = 1;
                    q.push({ t.x + fx[i], t.y + fy[i], t.st+1 });
                }
            }
        }
    }
    printf("%d %d",all,ans);
    return 0;
}

