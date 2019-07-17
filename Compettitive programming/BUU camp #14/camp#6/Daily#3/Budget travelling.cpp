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

int dis[10010], dis2[10010];
int mark[10010], mark2[10010];
int n, m, s, e, mo;
vector<vv> g[10010];
vector<int> noo;
priority_queue<qq> q;
int mi = 1e9, mn;
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&s,&e,&mo);
    for( int i = 0 ; i < m ; i++ ){
        int f, t, d;
        scanf("%d %d %d",&f,&t,&d);
        g[f].push_back({ t, d });
        g[t].push_back({ f, d });
    }
    q.push({s, 0});
    while( !q.empty() ){
        te = q.top();
        q.pop();
        if( mark[te.t] )continue;
        mark[te.t] = 1;
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark[g[te.t][i].t] ){
                if( te.d + g[te.t][i].d > mo ){
                    noo.push_back( te.t );
                }
                else if( dis[g[te.t][i].t] == 0 || dis[g[te.t][i].t] > te.d + g[te.t][i].d ){
                    dis[g[te.t][i].t] = te.d + g[te.t][i].d;
                    q.push({ g[te.t][i].t , te.d + g[te.t][i].d });
                }
            }
        }
    }
    if( mark[e] ){
        printf("%d %d 0",e,dis[e]);
        return 0;
    }
    q.push({ e, 0 });
    while( !q.empty() ){
        te = q.top();
        q.pop();
        if( mark2[te.t] )continue;
        mark2[te.t] = 1;
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark2[g[te.t][i].t] ){
               if( dis2[g[te.t][i].t] == 0 || dis2[g[te.t][i].t] > te.d + g[te.t][i].d ){
                    dis2[g[te.t][i].t] = te.d + g[te.t][i].d;
                    q.push({ g[te.t][i].t , te.d + g[te.t][i].d });
                }
            }
        }
    }
    for( int i = 0 ; i < noo.size() ; i++ ){
        if( mi > dis2[noo[i]] ){
            mi = dis2[noo[i]];
            mn = noo[i];
        }
        else if( dis2[noo[i]] == mi ){
            mn = min( mn, noo[i] );
        }
    }
    printf("%d %d %d",mn,dis[mn],mi);
}
/*
8 11
0 5 200
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/
