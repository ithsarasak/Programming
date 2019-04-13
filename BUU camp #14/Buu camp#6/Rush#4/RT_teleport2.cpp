#include<bits/stdc++.h>
using namespace std;
struct vv{
    long long t, d;
};
struct qq{
    long long t, d, co;
    bool operator<( const qq &k )const{
        return  d > k.d;
    }
}te;
long long n, m, k, a;
vector< vv > g[10500];
priority_queue< qq > pq;
long long dis[10500];
long long town;
long long ans = 1e9;
int main()
{
    scanf("%lld %lld %lld %lld",&n,&m,&k,&a);
    for( int i = 0 ; i < m ; i++ ){
        long long fr, to, di;
        scanf("%lld %lld %lld",&fr,&to,&di);
        g[fr].push_back({to,di});
        g[to].push_back({fr,di});
    }
    for( int i = 1 ; i <= k ; i++ ){
        int ho;
        scanf("%d",&ho);
        for( int j = 0 ; j < ho ; j++ ){
            scanf("%lld",&town);
            g[n+i].push_back({town,0});
            g[town].push_back({n+i,0});
        }
    }
    for( int i = 0 ; i <= n+k ; i++ )
        dis[i] = 1e9;
    pq.push({1,0,a});
    dis[1] = 0;
    while( !pq.empty() ){
        te = pq.top();
        pq.pop();
       // printf("%lld %lld %lld\n",te.t,te.d,te.co);
        if(te.t == n){
            printf("%lld\n",dis[n]);
            return 0;
        }
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            //printf("%lld %lld\n",g[te.t][i].t,g[te.t][i].d);
            if(g[te.t][i].t>n && te.co && dis[g[te.t][i].t]>te.d){
                dis[g[te.t][i].t] = te.d;
                pq.push({ g[te.t][i].t, te.d, te.co - 1 });
            }
            if(g[te.t][i].t<=n && dis[g[te.t][i].t] > te.d+g[te.t][i].d){
                dis[g[te.t][i].t] = te.d + g[te.t][i].d;
                pq.push({ g[te.t][i].t, te.d + g[te.t][i].d, te.co });
            }
        }
    }
    printf("-1");
    return 0;
}
