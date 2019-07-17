#include<bits/stdc++.h>

using namespace std;
struct qq{
    int no;
    long long d;
    int bo, last;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}t;
struct vv{
    int t;
    long long d;
};
priority_queue<qq> q;
vector<vv> g[80100];
long long dis[80100][10], ans = 1e18;
int mark[80100];
int n, m, l, qe;
int main()
{
    scanf("%d %d %d %d",&n,&m,&l,&qe);
    for( int i = 0 ; i < m ; i++ ){
        int f, t;
        long long d;
        scanf("%d %d %lld",&f,&t,&d);
        g[f].push_back({ t, d });
    }
    for( int i = 0 ; i < l ; i++ ){
        int no;
        scanf("%d",&no);
        mark[no] = 1;
    }
    for( int i = 0 ; i <= 80000 ; i++ ){
        for( int j = 0 ; j < 10 ; j++ ){
            dis[i][j] = 1e18;
        }
    }
    dis[1][0] = 0;
    q.push({ 1, 0, 0, -1 });
    while( !q.empty() ){
        t = q.top();
        q.pop();
        if( mark[t.no] && t.no != t.last && t.bo < qe )t.bo++, t.last = t.no;
        for( int i = 0 ; i < g[t.no].size() ; i++ ){
            if( dis[g[t.no][i].t][t.bo] > t.d + g[t.no][i].d/(1<<t.bo) ){
                dis[g[t.no][i].t][t.bo] = t.d + g[t.no][i].d/(1<<t.bo);
                q.push({ g[t.no][i].t, t.d + g[t.no][i].d/(1<<t.bo), t.bo, t.last });
            }
        }
    }
    for( int i = 0 ; i <= qe ; i++ ){
        ans = min( ans, dis[n][i] );
    }
    printf("%lld",ans);
    return 0;
}
