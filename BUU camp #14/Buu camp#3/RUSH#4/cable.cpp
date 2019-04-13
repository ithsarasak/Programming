#include<bits/stdc++.h>

using namespace std;
struct no{
    int t, d;
};
struct qq{
    int t, mi;
    bool operator<( const qq &k )const{
        return mi < k.mi;
    }
}t;
priority_queue<qq> q;
vector<no> g[2510];
int mark[2510];
int n, m, s, e, pe;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        int f, t, d;
        scanf("%d %d %d",&f,&t,&d);
        g[f].push_back({ t, d });
        g[t].push_back({ f, d });
    }
    scanf("%d %d %d",&s,&e,&pe);
    q.push({ s, 1e9 });
    while( !q.empty() ){
        t = q.top();
        q.pop();
        if( t.t == e ){
            double th = ( double )t.mi-1.00;
            double ans = ( ceil )( ( double )pe / th );
            printf("%.0f",ans);
            return 0;
        }
        if( mark[t.t] )continue;
        mark[t.t] = 1;
        for( int i = 0 ; i < g[t.t].size() ; i++ ){
            if( !mark[g[t.t][i].t] ){
                q.push({ g[t.t][i].t, min( t.mi, g[t.t][i].d )});
            }
        }
        mark[t.t] = 1;
    }
    return 0;
}
