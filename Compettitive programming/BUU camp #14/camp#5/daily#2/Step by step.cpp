#include<bits/stdc++.h>

using namespace std;
struct vv{
    long long t, d;
};
struct qq{
    long long t, d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}te;

long long dis[20010], dis2[20010];
long long mark[20010], mark2[20010];
long long n, m, s, e, mo;
vector<vv> g[20010];
priority_queue<qq> q;
int main()
{
    memset( dis, 127, sizeof dis );
    memset( dis2, 127, sizeof dis2 );
    scanf("%lld %lld",&n,&m);
    scanf("%lld %lld %lld",&s,&e,&mo);
    for( long long i = 0 ; i < m ; i++ ){
        long long f, t, d;
        scanf("%lld %lld %lld",&f,&t,&d);
        g[f].push_back({ t, d });
        g[t].push_back({ f, d });
    }
    q.push({s, 0});
    while( !q.empty() ){
        te = q.top();
        q.pop();
        if( mark[te.t] )continue;
        mark[te.t] = 1;
        for( long long i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark[g[te.t][i].t] ){
                if( dis[g[te.t][i].t] > te.d + g[te.t][i].d ){
                    dis[g[te.t][i].t] = te.d + g[te.t][i].d;
                    q.push({ g[te.t][i].t , te.d + g[te.t][i].d });
                }
            }
        }
    }
    q.push({ e, 0 });
    while( !q.empty() ){
        te = q.top();
        q.pop();
        if( mark2[te.t] )continue;
        mark2[te.t] = 1;
        for( long long i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark2[g[te.t][i].t] ){
               if( dis2[g[te.t][i].t] > te.d + g[te.t][i].d ){
                    dis2[g[te.t][i].t] = te.d + g[te.t][i].d;
                    q.push({ g[te.t][i].t , te.d + g[te.t][i].d });
                }
            }
        }
    }

    dis[s] = 0;
    dis2[e] = 0;
    for( long long i = 0 ; i < n ; i++ ){
        if( dis[i] + dis2[i] > mo || dis[i] > mo || dis2[i] > mo )  {
            printf("%lld ",i);
        }
    }
    return 0;
}
