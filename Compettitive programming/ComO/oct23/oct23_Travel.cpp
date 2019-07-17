#include<bits/stdc++.h>

using namespace std;
int n, ans;
int lca[30100][18];
int lv[30100], now, m;
vector<int> g[30100];
void dfs( int now, int p )
{
    lca[now][0] = p;
    lv[now] = lv[p] + 1;
    for( int i = 0 ; i < g[now].size() ; i++ ){
        if( g[now][i] != p ){
            dfs( g[now][i], now );
        }
    }
    return ;
}
int findlca( int a, int b )
{
    if( lv[a] < lv[b] ) swap( a,b );
    for( int i = 16 ; i >= 0 ; i-- ){
        if( lv[lca[a][i]] >= lv[b] ){
            a = lca[a][i];
        }
    }
    if( a == b )return a;
    for( int i = 16 ; i >= 0 ; i-- ){
        if( lca[a][i] != lca[b][i] ){
            a = lca[a][i], b = lca[b][i];
        }
    }
    return lca[a][0];
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n - 1 ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        g[f].push_back( t );
        g[t].push_back( f );
    }
    lv[1] = 1;
    dfs( 1, 0 );
    for( int i = 1 ; i <= 16 ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            lca[j][i] = lca[lca[j][i-1]][i-1];
        }
    }
    scanf("%d",&m);
    now = 1;
    for( int i = 0 ; i < m ; i++ ){
        int node;
        scanf("%d",&node);
        int a = findlca( now, node );
        //printf("%d\n",a);
        ans += abs( lv[a] - lv[now] ) + abs( lv[a] - lv[node] );
        now = node;
    }
    printf("%d",ans);
    return 0;
}
