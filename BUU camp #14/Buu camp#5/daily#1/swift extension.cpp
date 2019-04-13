#include<bits/stdc++.h>

using namespace std;
struct node{
    int t, d, id;
    bool operator<( const node &k )const{
        return d > k.d;
    }
}te;
int n, m, q, no, mindi, maxdi;
vector< node > g[1010];
priority_queue< node > pq;
int dis[1010];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= m ; i++ ){
        int fr, to, di, id = i;
        scanf("%d %d %d",&fr,&to,&di);
        g[fr].push_back({to,di,id});
        g[to].push_back({fr,di,id});
    }
    for( int j = 0 ; j <= m ; j++ ){
        memset( dis, 127, sizeof dis );
        pq.push({ 1, 0, 0 });
        while( !pq.empty() ){
            te = pq.top();
            pq.pop();
            for( int i = 0 ; i < g[te.t].size() ; i++ ){
                if( g[te.t][i].id == j ){
                    if( dis[g[te.t][i].t] > te.d + g[te.t][i].d*2 ){
                        dis[g[te.t][i].t] = te.d + g[te.t][i].d*2;
                        pq.push({g[te.t][i].t,te.d + g[te.t][i].d*2, 0 });
                    }
                }
                else{
                    if( dis[g[te.t][i].t] > te.d + g[te.t][i].d ){
                        dis[g[te.t][i].t] = te.d + g[te.t][i].d;
                        pq.push({g[te.t][i].t,te.d + g[te.t][i].d, 0 });
                    }
                }
            }
        }
        if( j == 0 ){
            mindi = dis[n];
            maxdi = mindi;
        }
        else{
            maxdi = max( maxdi, dis[n] );
        }
    }
    printf("%d",maxdi - mindi);
    return 0;
}
/*
5 7
1 2 5
1 3 1
2 3 8
2 4 7
3 5 7
3 4 3
4 5 2
*/
