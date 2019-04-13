#include<bits/stdc++.h>

using namespace std;
struct sh{
    long long pr, da;
}shoe[100010];
struct ee{
    long long t, da, d;
};
struct qq{
    long long t, d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}te;
vector< ee > g[100010];
priority_queue<qq> q;
long long n, m, k, t, s, ans = 1e9;
long long mark[100010], dis[100010];
long long check( long long num )
{
    memset( mark, 0, sizeof mark );
    fill( dis, dis + 100005, 200000000000 );
    dis[1] = 0;
    q.push({ 1, 0 });
    while( !q.empty() ){
        te = q.top();
        q.pop();
        for( long long i = 0 ; i < g[te.t].size() ; i++ ){
            if( !mark[g[te.t][i].t] ){
                if( ( dis[g[te.t][i].t] > te.d + g[te.t][i].d ) && g[te.t][i].da <= num ){
                    dis[g[te.t][i].t] = te.d + g[te.t][i].d;
                    q.push({ g[te.t][i].t , te.d + g[te.t][i].d });
                }
            }
        }
        mark[te.t] = 1;
    }
    if( dis[n] <= t ){
        return 1;
    }
    else return 0;
}
int main()
{
    scanf("%lld %lld %lld %lld",&n,&m,&k,&t);
    for( long long i = 0 ; i < m ; i++ ){
        long long f, t, da, d;
        scanf("%lld %lld %lld %lld",&f,&t,&da,&d);
        g[f].push_back({ t, da, d });
        g[t].push_back({ f, da, d });
    }
    for( long long i = 0 ; i < k ; i++ ){
        scanf("%lld %lld",&shoe[i].pr,&shoe[i].da);
    }
    long long l = 0, r = 100000;
    while( l < r ){
        long long mid = ( l + r ) / 2;
        if( check( mid ) ) r = mid;
        else l = mid + 1;
    }
    for( int i = 0 ; i < k ; i++ ){
        if( shoe[i].da >= l ){
            ans = min( ans, shoe[i].pr );
        }
    }
    if( ans == 1e9 ) printf("-1");
    else printf("%lld",ans);
    return 0;
}