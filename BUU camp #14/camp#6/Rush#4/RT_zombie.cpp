#include<bits/stdc++.h>

using namespace std;
struct qq{
    int x, y, va;
    bool operator<( const qq &k )const{
        return va > k.va;
    }
}te;
int n, m, r;
int ma[1100][1100], walk[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int dis[1100][1100];
priority_queue<qq> q;
int main()
{
    for( int i = 0 ; i <= 1000 ; i++ ){
        for( int j = 0 ; j <= 1000 ; j++ ){
            dis[i][j] = 1e9;
        }
    }
    scanf("%d %d %d",&n,&m,&r);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            scanf("%d",&ma[i][j]);
        }
    }
    dis[r][1] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        if( i == r )break;
        dis[i][1] = ma[i][1];
        q.push({ i, 1, ma[i][1] });
    }
    while( !q.empty() ){
        te = q.top();
        q.pop();
        for( int i = 0 ; i < 4 ; i++ ){
            //printf("%d %d\n",walk[i][0] + te.x,walk[i][1] + te.y);
            if( walk[i][0] + te.x >= 1 && walk[i][0] + te.x <= n && walk[i][1] + te.y >= 1 && walk[i][1] + te.y <= m ){
                if( dis[walk[i][0] + te.x][walk[i][1] + te.y] > te.va + ma[walk[i][0] + te.x][walk[i][1] + te.y] ){
                    dis[walk[i][0] + te.x][walk[i][1] + te.y] = te.va + ma[walk[i][0] + te.x][walk[i][1] + te.y];
                    q.push({ walk[i][0] + te.x, walk[i][1] + te.y, dis[walk[i][0] + te.x][walk[i][1] + te.y] });
                }
            }
        }
    }
    /*for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }*/
    int ans = 1e9;
    for( int i = r + 1 ; i <= n ; i++ ){
        ans = min( ans, dis[i][1] );
    }
    printf("%d",ans);
    return 0;
}
