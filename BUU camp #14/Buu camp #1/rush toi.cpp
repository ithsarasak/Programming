#include<bits/stdc++.h>

using namespace std;

int dist[310][310];
int graph[310][310];
int x, y, d, n, m;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            graph[i][j] = 999999999;
        }
    }
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d %d",&x,&y,&d);
        graph[x][y] = min( graph[x][y] , d );
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            dist[i][j] = graph[i][j];
        }
    }
    for( int k = 1 ; k <= n ; k++ ){
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if( dist[i][k] + dist[k][j] < dist[i][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( dist[i][j] == 999999999 ){
                printf("0 ");
            }
            else{
                printf("%d ",dist[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
