#include<bits/stdc++.h>

using namespace std;

vector< int > graph[101];
int visit[101];
int n, numnode, startnode;
int dfs( int curnode )
{
    visit[curnode] = 1;
    printf("%d ",curnode);
    for( int i = 0 ; i < graph[curnode].size() ; i++ ){
        if( !visit[graph[curnode][i]] ){
            dfs( graph[curnode][i] );
        }
    }
    return 0;
}
int main()
{
    printf("Enter number of edges and nodes : ");
    scanf("%d %d",&n,&numnode);
    for( int i = 0 ; i < n ; i++ ){
        int f , t, d;
        scanf("%d %d",&f,&t);
        graph[f].push_back( t );
    }
    printf("Select node to start : ");
    scanf("%d",&startnode);
    visit[startnode] = 1;
    printf("DFS traversal : ");
    dfs( startnode );
    return 0;
}
