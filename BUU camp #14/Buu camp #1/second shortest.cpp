#include<bits/stdc++.h>

using namespace std;

struct node{
    int to, dis;
};
struct pq{
    int curnode, sum;
    bool operator<( const pq &k )const{
        return sum > k.sum;
    }
}t;
vector< node > graph[10010];
priority_queue< pq > q;
int visit[10010];
int v, e, st, en;
int main()
{
    scanf("%d %d",&v,&e);
    scanf("%d %d",&st,&en);
    for( int i = 0 ; i < e ; i++ ){
        int f, t, w;
        scanf("%d %d %d",&f,&t,&w);
        graph[f].push_back({ t, w });
    }
    q.push({ st, 0 });
    while( !q.empty() ){
        t = q.top();
        visit[t.curnode]++;
        q.pop();
        if( visit[en] == 2 ){
            printf("%d",t.sum);
            return 0;
        }
        for( int i = 0 ; i < graph[t.curnode].size() ; i++ ){
            q.push({ graph[t.curnode][i].to , t.sum + graph[t.curnode][i].dis });
        }
    }
    return 0;
}
