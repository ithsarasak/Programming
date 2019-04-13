#include<bits/stdc++.h>

using namespace std;
int mic[25][100100];
vector<int> g[100100];
int n, in[100100], lv[100100];
void dfs( int now, int p )
{
    mic[0][now] = p;
    lv[now] = lv[p] + 1;
    for( int i = 0 ; i < g[now].size() ; i++ ){
        if( g[now][i] != p ){
            dfs( g[now][i], now );
        }
    }
}
int lca( int a, int b )
{
    if( lv[a] > lv[b] )swap( a, b );
    for( int i = 20 ; i >= 0 ; i-- ){
        if( lv[mic[i][b]] < lv[a] )continue;
        b = mic[i][b];
    }
    if( a == b )return a;
    for( int i = 20 ; i >= 0 ; i-- ){
        if( mic[i][a] != mic[i][b] ){
            a = mic[i][a];
            b = mic[i][b];
        }
    }
    return mic[0][a];
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n - 1 ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        g[f].push_back( t );
        in[t]++;
    }
    int rt;
    for( int i = 1 ; i <= n ; i++ ){
        if( !in[i] ){
            rt = i;
            break;
        }
    }
    dfs( rt, 0 );
    for( int i = 1 ; i <= 20 ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            mic[i][j] = mic[i-1][mic[i-1][j]];
        }
    }
    int q;
    scanf("%d",&q);
    while( q-- ){
        int a, b;
        scanf("%d %d",&a,&b);
        printf("%d\n",lca(a, b));
    }
    return 0;
}
