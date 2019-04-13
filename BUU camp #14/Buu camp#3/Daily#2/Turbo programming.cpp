#include<bits/stdc++.h>

using namespace std;
struct node{
    int t, d;
    bool operator<( const node &k )const{
        return d > k.d;
    }
}te;
int n, m, q, no;
vector< node > g[1010];
priority_queue< node > pq;
int dis[1010];
int main()
{
    memset( dis, -1, sizeof dis );
    scanf("%d %d %d",&n,&m,&q);
    for( int i = 0 ; i < m ; i++ ){
        int fr, to, di;
        scanf("%d %d %d",&fr,&to,&di);
        g[fr].push_back({to,di});
    }
    pq.push({1,0});
    dis[1] = 0;
    while( !pq.empty() ){
        te = pq.top();
        pq.pop();
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( dis[g[te.t][i].t] == -1 || dis[g[te.t][i].t] > te.d + g[te.t][i].d ){
                dis[g[te.t][i].t] = te.d + g[te.t][i].d;
                pq.push({g[te.t][i].t,te.d + g[te.t][i].d});
            }
        }
    }
    for( int i = 0 ; i < q ; i++ ){
        scanf("%d",&no);
        printf("%d\n",dis[no]);
    }
    return 0;
}
