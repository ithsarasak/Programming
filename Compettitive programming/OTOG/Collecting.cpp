#include<bits/stdc++.h>

using namespace std;
struct node{
    int t, d, l;
    bool operator<( const node &k )const{
        return d > k.d;
    }
}te;
struct gg{
    int t, d;
};
int n, m, no, k, s ,t;
vector< gg > g[50010];
priority_queue< node > q;
int dis[50010][31], va[50010];
int main()
{
    for( int i = 0 ; i <= 50000 ; i++ ){
        for( int j = 0 ; j <= 30 ; j++ ){
            dis[i][j] = 1e9;
        }
    }
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d %d",&s,&t);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&va[i]);
    }
    for( int i = 0 ; i < m ; i++ ){
        int fr, to, di;
        scanf("%d %d %d",&fr,&to,&di);
        g[fr].push_back({to,di});
    }
    dis[s][0] = 0;
    q.push({ s, 0, 0 });
    while( !q.empty() ){
        te = q.top();
        q.pop();
        if( va[te.t] == te.l ){
            te.l++;
        }
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( dis[g[te.t][i].t][te.l] > te.d + g[te.t][i].d ){
                dis[g[te.t][i].t][te.l] = te.d + g[te.t][i].d;
                q.push({ g[te.t][i].t, te.d + g[te.t][i].d, te.l });
            }
        }
    }
    if( dis[t][k] == 1e9 )printf("-1");
    else printf("%d",dis[t][k]);
    return 0;
}
