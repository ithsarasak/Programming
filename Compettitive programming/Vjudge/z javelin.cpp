#include<bits/stdc++.h>

using namespace std;
char ma[1010][1010];
int n, m, ma2[1010][1010], sx, sy, ex, ey;
int fx[4] = { 1, 0, -1, 0 };
int fy[4] = { 0, 1, 0, -1 };
void dfs( int x, int y, int di, int t )
{
    if( t > 2 || x < 0 || x >= n || y < 0 || y >= m || ma2[x][y] == 1 ){
        return ;
    }
    if( x == ex && y == ey ){
        printf("YES");
        exit( 0 );
    }
    for( int i = 0 ; i < 4 ; i++ ){
        if( di == i || di == ( i ^ 2 ) ) continue;
        dfs( x + fx[i], y + fy[i], i, t + 1 );
    }
    dfs( x + fx[di], y + fy[di], di, t );
    return ;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%s",ma[i]);
        for( int j = 0 ; j < m ; j++ ){
            if( ma[i][j] == '*' ){
                ma2[i][j] = 1;
            }
            else if( ma[i][j] == 'S' ){
                sx = i;
                sy = j;
            }
            else if( ma[i][j] == 'T' ){
                ex = i;
                ey = i;
            }
        }
    }
    for( int i = 0 ; i < 4 ; i++ ){
        dfs( sx + fx[i], sy + fy[i], i, 0 );
    }
    printf("NO");
    return 0;
}
