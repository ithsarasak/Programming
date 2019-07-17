#include<bits/stdc++.h>

using namespace std;
int n, q;
vector<int> g[100100];
int mic[20][100100], lv[100100];
void dfs( int now, int p )
{
    mic[0][now] = p;
    lv[now] = lv[p] + 1;
    for( int i = 0 ; i < g[now].size() ; i++ ){
        if( g[now][i] != p )
            dfs( g[now][i], now );
    }
}
int lca( int a, int b )
{
    if( lv[a] > lv[b] )swap( a, b );
    for( int i = 18 ; i >= 0 ; i-- ){
        if( lv[mic[i][b]] < lv[a] ) continue;
        b = mic[i][b];
    }
    if( a == b )return a;
    for( int i = 18 ; i >= 0 ; i-- ){
        if( mic[i][a] != mic[i][b] )a = mic[i][a], b = mic[i][b];
    }
    return mic[0][a];
}
int cal( int l, int a, int b, int c )
{
    return lv[a]+lv[l]-2*lv[lca(a,l)]+lv[b]+lv[l]-2*lv[lca(b,l)]+lv[c]+lv[l]-2*lv[lca(c,l)];
}
int main()
{
    scanf("%d %d",&n,&q);
    for( int i = 0 ; i < n - 1 ; i++ ){
            int f, t;
        scanf("%d %d",&f,&t);
        g[f].push_back( t );
        g[t].push_back( f );
    }
    dfs( 1, 0 );
    for( int i = 1 ; i <= 18 ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            mic[i][j] = mic[i-1][mic[i-1][j]];
        }
    }
    while( q-- ){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        int no = lca( a, b );
        int mi = cal( no, a, b, c ), nownode = no;
        no = lca( b, c );
        int t = cal( no, a, b, c );
        if( t < mi ){
            mi = t;
            nownode = no;
        }
        no = lca( a, c );
        t = cal( no, a, b, c );
        if( t < mi ){
            mi = t;
            nownode = no;
        }
        printf("%d %d\n",nownode,mi);
    }
    return 0;
}
