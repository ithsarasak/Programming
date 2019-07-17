#include<bits/stdc++.h>

using namespace std;
struct gg{
    int t, d;
};
struct qq{
    int t, d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}tt;
vector<gg> g[1500];
priority_queue<qq> q;
int v, e, a, b, t, k, st, en;
int dis[1500];
int main()
{
    scanf("%d %d",&v,&e);
    scanf("%d %d",&st,&en);
    scanf("%d %d %d %d",&a,&b,&t,&k);
    g[a].push_back({ b, t });
    for( int i = 0 ; i < e ; i++ ){
        int f, t, d;
        scanf("%d %d %d",&f,&t,&d);
        g[f].push_back({ t, d });
    }
    q.push({ st, 0 });
    for( int i = 0 ; i <= 1400 ; i++ )dis[i] = 1e9;
    dis[st] = 0;
    while( !q.empty() ){
        tt = q.top();
        q.pop();
        //printf("%d %d\n",tt.t,tt.d);
        for( int i = 0 ; i < g[tt.t].size() ; i++ ){
            if(( g[tt.t][i].d < 0 && tt.d <= k ) || g[tt.t][i].d > 0 ){
                if( dis[g[tt.t][i].t] > tt.d + g[tt.t][i].d ){
                    dis[g[tt.t][i].t] = tt.d + g[tt.t][i].d;
                    q.push({ g[tt.t][i].t, tt.d + g[tt.t][i].d });
                }
            }
        }
    }
    printf("%d",dis[en]);
    return 0;
}
