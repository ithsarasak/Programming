#include<bits/stdc++.h>

using namespace std;

struct node{
    int to, dis;
};
vector< node > graph[100];
int n, numnode;
int main()
{
    printf("Enter number of edges and nodes : ");
    scanf("%d %d",&n,&numnode);
    for( int i = 0 ; i < n ; i++ ){
        int f , t, d;
        scanf("%d %d %d",&f,&t,&d);
        graph[f].push_back({ t , d });
    }
    printf("=========ADJACENCY LIST=========\n");
    for( int i = 0 ; i <= numnode ; i++ ){
        for( int j = 0 ; j < graph[i].size() ; j ++ ){
            printf("Adjacency list[%d] :-> %d distance : %d\n",i,graph[i][j].to, graph[i][j].dis );
        }
    }
    return 0;
}
