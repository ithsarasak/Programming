#include<bits/stdc++.h>

using namespace std;
int n, m, k, di, to, visit[100010], visit2[100010], co, a, b;
vector<int> g[100010], g2[100010];
stack<int> po;
void dfs( int no )
{
    visit[no] = 1;
    for( int i = 0 ; i < g[no].size() ; i++ ){
        if( !visit[g[no][i]] ){
            dfs( g[no][i] );
        }
    }
    po.push( no );
}
void dfs2( int no )
{
    //printf("%d\n",no);
    visit2[no] = co;
    for( int i = 0 ; i < g2[no].size() ; i++ ){
        if( !visit2[g2[no][i]] ){
            dfs2( g2[no][i] );
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&di);
        for( int j = 0 ; j < di ; j++ ){
            scanf("%d",&to);
            g[i].push_back( to );
            g2[to].push_back( i );
        }
    }
    for( int i = 1 ; i < n ; i++ ){
        if( !visit[i] ){
            dfs( i );
        }
    }
    while( !po.empty() ){
        int tt = po.top();
        po.pop();
        //printf("%d",tt);
        if( !visit2[tt] ){
            co++;
            dfs2( tt );
        }
    }
    for( int i = 0 ; i < k ; i++ ){
        scanf("%d %d",&a,&b);
        if( visit2[a] == visit2[b] )printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
