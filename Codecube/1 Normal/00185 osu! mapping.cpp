#include<bits/stdc++.h>
#define inf 2000000000000000;
using namespace std;

struct node{
    int t;
    long long d;
};
struct p{
    int n, be;
    long long su;
    bool operator<( const p &k )const{
        return su > k.su;
    }
}te;
vector< node > g[10010];
priority_queue< p > q;
int visit[10010][9];
long long dis[10010][9];
int n, m, t, s, e;
int main()
{
    scanf("%d %d %d",&n,&m,&t);
    scanf("%d %d",&s,&e);
    for( int i = 0 ; i < m ; i++ ){
        int fr, to;
        long long di;
        scanf("%d %d %lld",&fr,&to,&di);
        g[fr].push_back({ to, di });
    }
    for( int i = 0 ; i <= t ; i++ ){
        for( int j = 0 ; j <= n ; j++ ){
            dis[j][i] = inf;
        }
    }
    q.push({ s, 1, 0 });
    dis[s][1] = 0;
    while( !q.empty() ){
        te = q.top();
        q.pop();
        visit[te.n][te.be % t] = 1;
        for( int i = 0 ; i <  g[te.n].size() ; i++ ){
            if( !visit[g[te.n][i].t][( te.be + 1 ) % t] )
                if( dis[g[te.n][i].t][(te.be+1)%t] > te.su + g[te.n][i].d ){
                    dis[g[te.n][i].t][(te.be+1)%t] = te.su + g[te.n][i].d;
                    q.push({ g[te.n][i].t, ( te.be + 1 ) % t , te.su + g[te.n][i].d});
                }
        }
    }
    if( visit[e][0] == 0 ){
        printf("-1");
        return 0;
    }
    printf("%lld",dis[e][0]);
    return 0;
}

