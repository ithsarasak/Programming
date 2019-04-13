#include<bits/stdc++.h>

using namespace std;
struct vv{
    int t, d;
};
struct qq{
    int t, d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}te;
struct ee{
    int f, t, d;
}e[200100];
int dis[100100], dis2[100100];
int mark[100100], mark2[100100];
int n, m, s, to, sum, ma;
vector<vv> g[100100];
priority_queue<qq> q;
int mi = 1e9, mn;
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%d %d",&s,&to);
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d %d",&e[i].f,&e[i].t,&e[i].d);
        g[e[i].f].push_back({ e[i].t, e[i].d });
        g[e[i].t].push_back({ e[i].f, e[i].d });
        sum += e[i].d;
    }
    for( int i = 0 ; i < n ; i++ ){
        dis[i] = 200000001;
        dis2[i] = 200000001;
    }
    dis[s] = 0;
    q.push({s, 0});
    while( !q.empty() ){
        te = q.top();
        q.pop();
        if( mark[te.t] )continue;
        mark[te.t] = 1;
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark[g[te.t][i].t] ){
                if( dis[g[te.t][i].t] > te.d + g[te.t][i].d ){
                    dis[g[te.t][i].t] = te.d + g[te.t][i].d;
                    q.push({ g[te.t][i].t , te.d + g[te.t][i].d });
                }
            }
        }
    }
    /*for( int i = 0 ; i < n ; i++ ){
        printf("%d ",dis[i]);
    }
    printf("\n");*/
    dis2[to] = 0;
    q.push({ to, 0 });
    while( !q.empty() ){
        te = q.top();
        q.pop();
        if( mark2[te.t] )continue;
        mark2[te.t] = 1;
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark2[g[te.t][i].t] ){
               if( dis2[g[te.t][i].t] > te.d + g[te.t][i].d ){
                    dis2[g[te.t][i].t] = te.d + g[te.t][i].d;
                    q.push({ g[te.t][i].t , te.d + g[te.t][i].d });
                }
            }
        }
    }
   /* for( int i = 0 ; i < n ; i++ ){
        printf("%d ",dis2[i]);
    }
    printf("\n");*/
    for( int i = 0 ; i < m ; i++ ){
        ma = max( ma, sum - dis[e[i].f] - dis2[e[i].t] );
        ma = max( ma, sum - dis2[e[i].f] - dis[e[i].t] );
    }
    printf("%d",ma);
    return 0;
}

