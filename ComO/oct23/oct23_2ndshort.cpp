#include<bits/stdc++.h>

using namespace std;
struct qq{
    int no, d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}t;
struct gg{
    int t, d;
};
struct ee{
    int f, t, d;
};
priority_queue<qq> q;
vector<gg> g[10100], g2[10100];
vector<ee> e;
int v, eee, s, to, mi = 1e9;
int dis[10100], dis2[10100];
int main()
{
    scanf("%d %d",&v,&eee);
    scanf("%d %d",&s,&to);
    for( int i = 0 ; i < eee ; i++ ){
        int f, t,d;
        scanf("%d %d %d",&f,&t,&d);
        g[f].push_back({ t, d });
        g2[t].push_back({ f, d });
        e.push_back({ f, t, d });
    }
    memset( dis, 127, sizeof dis );
    memset( dis2, 127, sizeof dis2 );
    dis[s] = 0,dis2[to] = 0;
    q.push({ s, 0 });
    while( !q.empty() ){
        t = q.top();
        q.pop();
        for( int i = 0 ; i < g[t.no].size() ; i++ ){
            if( dis[g[t.no][i].t] > t.d + g[t.no][i].d ){
                dis[g[t.no][i].t] = t.d + g[t.no][i].d;
                q.push({ g[t.no][i].t, t.d + g[t.no][i].d });
            }
        }
    }
    q.push({ to, 0 });
    while( !q.empty() ){
        t = q.top();
        q.pop();
        //printf("%d %d\n",t.no,t.d);
        for( int i = 0 ; i < g2[t.no].size() ; i++ ){
            if( dis2[g2[t.no][i].t] > t.d + g2[t.no][i].d ){
                dis2[g2[t.no][i].t] = t.d + g2[t.no][i].d;
                q.push({ g2[t.no][i].t, t.d + g2[t.no][i].d });
            }
        }
    }
    /*for( int i = 1 ; i <= v ; i++ ){
        printf("%d %d\n",dis[i],dis2[i]);
    }*/
    for( int i = 0 ; i < e.size() ; i++ ){
        int ss = dis[e[i].f] + dis2[e[i].t] + e[i].d;
        if( ss > dis[to] && ss < mi )mi = ss;
    }
    printf("%d",mi);
    return 0;
}
