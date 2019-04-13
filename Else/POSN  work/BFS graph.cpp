#include<bits/stdc++.h>

using namespace std;

struct b{
    int lv, node;
}t;
vector< int > graph[101];
queue< b > q;
int n, numnode, startnode, visit[101];
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
    q.push( { 0 , startnode } );
    visit[startnode] = 1;
    printf("----BFS traversal----\n");
    while( !q.empty() ){
        t = q.front();
        q.pop();
        visit[t.node] = 1;
        printf("Node : %d Level : %d\n",t.node,t.lv);
        for( int i = 0 ; i < graph[t.node].size() ; i++ ){
            //printf("%d ",graph[t.node][i]);
            if( !visit[graph[t.node][i]] ){
                visit[graph[t.node][i]] = 1;
                q.push({ t.lv + 1 , graph[t.node][i] });
            }
        }
    }
    return 0;
}
