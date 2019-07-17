#include<bits/stdc++.h>

using namespace std;
struct qq{
    int no, d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}t;
struct gg{
    int t, d;
};
priority_queue<qq> q;
vector<gg> g[1100];
int mark[1100][2200];
int ans;
int n, np, b, s, m, k;
int main()
{
    scanf("%d %d",&n,&np);
    scanf("%d",&k);
    for( int i = 0 ; i < k ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        g[f].push_back({ t, 0 });
    }
    scanf("%d",&m);
    for( int i = 0 ; i < m ; i++ ){
        int f, t, d;
        scanf("%d %d %d",&f,&t,&d);
        g[f].push_back({ t, d });
    }
    scanf("%d %d",&b,&s);
    q.push({ b, 0 });
    mark[b][0] = 1;
    while( !q.empty() ){
        t = q.top();
        q.pop();
        for( int i = 0 ; i < g[t.no].size() ; i++ ){
            if( t.d + g[t.no][i].d <= s ){
                if( !mark[g[t.no][i].t][t.d+g[t.no][i].d] ){
                    mark[g[t.no][i].t][t.d+g[t.no][i].d] = 1;
                    q.push({ g[t.no][i].t, t.d + g[t.no][i].d });
                }
            }
        }
    }
    for( int i = 1 ; i <= np ; i++ ){
        for( int j = s ; j >= 0 ; j-- ){
            //printf("mark[%d][%d] : %d\n",i,j,mark[i][j]);
            if( mark[i][j] )ans = max( ans, j );
        }
    }
    printf("%d",s-ans);
    return 0;
}
