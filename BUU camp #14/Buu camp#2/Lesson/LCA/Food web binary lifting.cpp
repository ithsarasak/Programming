#include<bits/stdc++.h>

using namespace std;
int in[100010], lv[100010];
int mic[21][100010], rt;
vector<int> g[100010];
void dfs( int now, int p )
{
    mic[0][now] = p;
    lv[now] = lv[p] + 1;
    for( auto &next : g[now] )
        dfs( next, now );
}
int lca( int a, int b )
{
    if( lv[a] > lv[b] ) swap( a, b );
    for( int i = 20 ; i >= 0 ; i-- ){
        if( lv[mic[i][b]] < lv[a] ) continue;
        b = mic[i][b];
    }
    if( a == b ) return a;
    for( int i = 20 ; i >= 0 ; i-- ){
        if( mic[i][a] != mic[i][b] )a = mic[i][a], b = mic[i][b];
    }
    return mic[0][a];
}
int main()
{
    int n, s, e, q;
    scanf("%d",&n);
    for( int i = 1 ; i < n ; i++ ){
        scanf("%d %d",&s,&e);
        g[s].push_back( e );
        in[e]++;
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( !in[i] ){
            rt = i;
            break;
        }
    }
    dfs( rt , 0 );
    for( int i = 1 ; i <= 20 ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            mic[i][j] = mic[i - 1][mic[i - 1][j]];
        }
    }
    scanf("%d",&q);
    while( q-- ){
        scanf("%d %d",&s,&e);
        printf("%d\n",lca( s, e ));
    }
    return 0;
}
