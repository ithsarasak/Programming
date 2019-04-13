#include<bits/stdc++.h>

using namespace std;
vector< int > g[100010], g2[100010];
stack<int> ko;
int visit[100010], visit2[100010];
int n, m, k, co;
int dfs( int node )
{
    visit[node] = 1;
    for( int i = 0 ; i < g[node].size() ; i++ ){
        if( !visit[g[node][i]] ){
            dfs( g[node][i] );
        }
    }
    ko.push( node );
}
int dfs2( int node )
{
    visit2[node] = co;
    for( int i = 0 ; i < g2[node].size() ; i++ ){
        if( !visit2[g2[node][i]] ){
            dfs2( g2[node][i] );
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ){
        int nu, no;
        scanf("%d",&nu);
        for( int j = 0 ; j < nu ; j++ ){
            scanf("%d",&no);
            g[i].push_back( no );
            g2[no].push_back( i );
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( !visit[i] )dfs( i );
    }
    while( !ko.empty() ){
        int tt = ko.top();
        ko.pop();
        if( !visit2[tt] ){
            co++;
            dfs2( tt );
        }
    }
    for( int i = 0 ; i < k ; i++ ){
        int n1, n2;
        scanf("%d %d",&n1,&n2);
        if( visit2[n1] == visit2[n2] )printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
