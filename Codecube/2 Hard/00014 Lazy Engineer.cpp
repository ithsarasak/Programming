#include<bits/stdc++.h>

using namespace std;
struct qq{
    int t, d, pn;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}te;
struct no{
    int t, d;
};
struct ee{
    int f, t, d;
}e[5010];
vector< no > g[1010];
priority_queue< qq > pq;
int mark[1010][3];
int dis[1010][3];
int n, m;
int mi = 1e9;
int ssp( int k )
{
    memset( mark, 0, sizeof mark );
    memset( dis, 0, sizeof dis );
    for( int i = 0 ; i < 1010 ; i++ ){
        g[i].clear();
    }
    for( int i = 1 ; i <= k ; i++ ){
        g[e[i].f].push_back({ e[i].t, e[i].d });
        g[e[i].t].push_back({ e[i].f, e[i].d });
    }
    pq.push({ 1, 0, 1 });
    while( !pq.empty() ){
        te = pq.top();
        pq.pop();
        if( mark[te.t][te.pn%2] )continue;
        mark[te.t][te.pn%2] = 1;
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark[g[te.t][i].t][(te.pn+1)%2] ){
                if( dis[g[te.t][i].t][(te.pn+1)%2] == 0 || dis[g[te.t][i].t][(te.pn+1)%2] > te.d + g[te.t][i].d ){
                    dis[g[te.t][i].t][(te.pn+1)%2] = te.d + g[te.t][i].d;
                    pq.push({ g[te.t][i].t , te.d + g[te.t][i].d , (te.pn+1)%2 });
                }
            }
        }
    }
    if( mi == dis[n][0] ){
        mi = dis[n][0];
        return 1;
    }
    else return 0;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= m ; i++ ){
        int f, t, d;
        scanf("%d %d %d",&e[i].f,&e[i].t,&e[i].d);
    }
    for( int i = 1 ; i <= m ; i++ ){
        g[e[i].f].push_back({ e[i].t, e[i].d });
        g[e[i].t].push_back({ e[i].f, e[i].d });
    }
    pq.push({ 1, 0, 1 });
    while( !pq.empty() ){
        te = pq.top();
        pq.pop();
        if( mark[te.t][te.pn%2] )continue;
        mark[te.t][te.pn%2] = 1;
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark[g[te.t][i].t][(te.pn+1)%2] ){
                if( dis[g[te.t][i].t][(te.pn+1)%2] == 0 || dis[g[te.t][i].t][(te.pn+1)%2] > te.d + g[te.t][i].d ){
                    dis[g[te.t][i].t][(te.pn+1)%2] = te.d + g[te.t][i].d;
                    pq.push({ g[te.t][i].t , te.d + g[te.t][i].d , (te.pn+1)%2 });
                }
            }
        }
    }
    mi = dis[n][0];
    int l = 1, r = m;
    while( l < r ){
        int mm = ( l + r ) / 2;
        if( ssp( mm ) ){
            r = mm;
        }
        else l = mm+1;
    }
    printf("%d %d",l,mi);
    return 0;
}
