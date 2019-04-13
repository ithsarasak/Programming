#include<bits/stdc++.h>

using namespace std;
struct po{
    int t, d;
}t;
int n, m, mark[100010], mic[100010];
vector<po> g[100010];
void dfs( int no, int sum )
{
    mark[no] = 1;
    mic[no] = sum;
    for( int i = 0 ; i < g[no].size() ; i++ ){
        if( !mark[g[no][i].t] ){
            dfs( g[no][i].t, sum ^ g[no][i].d );
        }
    }
    return ;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n-1 ; i++ ){
        int f, t, d;
        scanf("%d %d %d",&f,&t,&d);
        g[f].push_back({ t, d });
        g[t].push_back({ f, d });
    }
    dfs( 1 , 0 );
    for( int i = 0 ; i < m ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        printf("%d\n",mic[f]^mic[t]);
    }
    return 0;
}
