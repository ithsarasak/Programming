#include<bits/stdc++.h>

using namespace std;

struct node{
    int to, dis;
};
struct pairs{
    int curnode, sum;
    bool operator<( const pairs &k )const{
        return k.sum < sum;
    }
}t;
vector< node > graph[101];
priority_queue< pairs > pri;
int s, e;
int n, numnode;
int visit[101], dis[101];
int main()
{
    printf("Enter number of edges and nodes : ");
    scanf("%d %d",&n,&numnode);
    for( int i = 0 ; i < n ; i++ ){
        int f , t, d;
        scanf("%d %d %d",&f,&t,&d);
        graph[f].push_back({ t , d });
        graph[t].push_back({ f , d });
    }
    printf("Start node : ");
    scanf("%d",&s);
    printf("End node : ");
    scanf("%d",&e);
    pri.push({ s, 0 });
    while( !pri.empty() ){
        t = pri.top();
        for( int i = 0 ; i < graph[t.curnode].size() ; i++ ){
            if( !visit[graph[t.curnode][i].to] ){
                if( dis[graph[t.curnode][i].to] == 0 || dis[graph[t.curnode][i].to] > t.sum + graph[t.curnode][i].dis ){
                    dis[graph[t.curnode][i].to] = t.sum + graph[t.curnode][i].dis;
                    pri.push({ graph[t.curnode][i].to , dis[graph[t.curnode][i].to] });
                }
            }
        }
        visit[t.curnode] = 1;
        pri.pop();
    }
    if( !visit[e] ){
        printf("Unreachable node\n");
    }
    else{
        printf("Shortest distance form %d to %d : %d",s,e,dis[e]);
    }
    return 0;
}
