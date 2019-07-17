#include<bits/stdc++.h>

using namespace std;

int color[100010];
vector< int > graph[100010];

int i, x, y, n ,m;
int dfs( int v , int t )
{
    color[v] = t;
    for( int j = 0 ; j < graph[v].size() ; j++ ){
        int u = graph[v][j];
        if( color[u] == color[v] ){
            printf("Gay found!");
            exit(0);
        }
        if( color[u] == 0 ){
            dfs( u , 2 / t );
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for( i = 0 ; i < m ; i++ ){
        scanf("%d %d",&x,&y);
        graph[x].push_back( y );
        graph[y].push_back( x );
    }
    for( i = 0 ; i < 100000 ; i++ ){
        if( color[i] == 0 ){
            dfs( i , 1 );
        }
    }
    printf("Gay not found!");
    return 0;
}
