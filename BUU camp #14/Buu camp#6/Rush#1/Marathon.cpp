#include<bits/stdc++.h>

using namespace std;
struct sh{
    int pr, da;
    bool operator<( const sh &k )const{
        if( da == k.da )return pr < k.pr;
        else return da < k.da;
    }
}shoe[100010];
struct ee{
    int t, da;
    long long d;
};
struct qq{
    int t;
    long long d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}te;
vector< ee > g[100010];
priority_queue<qq> q;
int n, m, k, t, s;
int mark[100010];
long long dis[100010];
int check( int num )
{
    memset( mark, 0, sizeof mark );
    fill( dis, dis + 100005, 200000000000 );
    dis[1] = 0;
    q.push({ 1, 0 });
    while( !q.empty() ){
        te = q.top();
        q.pop();
        if( te.t == n ){
            break;
        }
        for( int i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark[g[te.t][i].t] ){
                if( ( dis[g[te.t][i].t] > te.d + g[te.t][i].d ) && g[te.t][i].da <= num ){
                    dis[g[te.t][i].t] = te.d + g[te.t][i].d;
                    q.push({ g[te.t][i].t , te.d + g[te.t][i].d });
                }
            }
        }
        mark[te.t] = 1;
    }
    while( !q.empty() )q.pop();
    if( dis[n] <= t ){
        return 1;
    }
    else return 0;
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for( int i = 0 ; i < m ; i++ ){
        int f, t, da;
        long long d;
        scanf("%d %d %d %lld",&f,&t,&da,&d);
        g[f].push_back({ t, da, d });
        g[t].push_back({ f, da, d });
    }
    for( int i = 0 ; i < k ; i++ ){
        scanf("%d %d",&shoe[i].pr,&shoe[i].da);
    }
    sort( shoe, shoe + k );
    for( int i = k - 2 ; i >= 0 ; i-- ){
        shoe[i].pr = min( shoe[i].pr, shoe[i + 1].pr );
    }
    int l = 0, r = k;
    while( l < r ){
        int mid = ( l + r ) / 2;
        if( check( shoe[mid].da ) ) r = mid;
        else l = mid + 1;
    }
    if( l == k ) printf("-1");
    else printf("%d",shoe[l].pr);
    return 0;
}
