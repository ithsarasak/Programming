#include<bits/stdc++.h>

using namespace std;
struct qq{
    int x, y, bi, di;
}t;
int dis[510][510][10], walk[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, va[510][510];
int n, m, sx, sy, ex, ey, nowx, nowy, nowbi, nowdi, nexx, nexy, nexbi, nexdi;
char ma[510][510];
queue<qq> q;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%s",&ma[i][1]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            //printf("%c ",ma[i][j]);
            if( ma[i][j] == 'S' ){
                ma[i][j] = '.';
                sx = i;
                sy = j;
            }
            else if( ma[i][j] == 'E' ){
                ma[i][j] = '.';
                ex = i;
                ey = j;
            }
            else if( ma[i][j] == 'J' || ma[i][j] == 'j' )va[i][j] = 1 << 0;
            else if( ma[i][j] == 'B' || ma[i][j] == 'b' )va[i][j] = 1 << 1;
            else if( ma[i][j] == 'P' || ma[i][j] == 'p' )va[i][j] = 1 << 2;
        }
    }
    q.push({ sx, sy, 0, 0 });
    for( int i = 1 ; i <= 505 ; i++ ){
        for( int j = 1 ; j <= 505 ; j++ ){
            for( int k = 0 ; k < 10 ; k++ ){
                dis[i][j][k] = 1e9;
            }
        }
    }
    dis[sx][sy][0] = 0;
    //printf("%d %d\n",sx,sy);
    while( !q.empty() ){
        t = q.front();
        nowx = t.x;
        nowy = t.y;
        nowbi = t.bi;
        nowdi = t.di;
        q.pop();
        //printf("%d %d\n",nowx,nowy);
        if( nowx == ex && nowy == ey ){
            printf("%d",nowdi);
            return 0;
        }
        for( int i = 0 ; i < 4 ; i++ ){
            nexx = nowx + walk[i][0];
            nexy = nowy + walk[i][1];
            nexbi = nowbi;
            nexdi = nowdi + 1;
            //printf("%d %d %d %d\n",nexx,nexy,nexbi,nexdi);
            if( nexx < 1 || nexx > n || nexy < 1 || nexy > m || ma[nexx][nexy] == '#' )continue ;
            //printf("ma[%d][%d] : %c dis[%d][%d][%d] : %d\n",nexx,nexy,ma[nexx][nexy],nexx,nexy,nexbi,dis[nexx][nexy][nexbi]);
            if(( ma[nexx][nexy] == 'j' || ma[nexx][nexy] == 'b' || ma[nexx][nexy] == 'p' ) && !( nexbi & ( va[nexx][nexy] ) )){
                nexbi |= va[nexx][nexy];
            }
            if( ( ma[nexx][nexy] == '.' || ma[nexx][nexy] == 'j' || ma[nexx][nexy] == 'b' || ma[nexx][nexy] == 'p' ) && dis[nexx][nexy][nexbi] > nexdi ){
                dis[nexx][nexy][nexbi] = nexdi;
                q.push({ nexx, nexy, nexbi, nexdi });
            }
            else if(( ma[nexx][nexy] == 'J' || ma[nexx][nexy] == 'B' || ma[nexx][nexy] == 'P' ) && ( nexbi & ( va[nexx][nexy] ) )){
                if( dis[nexx][nexy][nexbi] > nexdi ){
                    dis[nexx][nexy][nexbi] = nexdi;
                    q.push({ nexx, nexy, nexbi, nexdi });
                }
            }
        }
    }
    printf("-1");
    return 0;
}
