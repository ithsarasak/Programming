#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, q, rt, in[N], lv[N], mic[20][N], a, b;
vector<int> g[N];

void dfs( int now, int p ) {
    lv[now] = lv[p] + 1, mic[0][now] = p;
    for( int i : g[now] ) if( i != p ) dfs( i, now );
    return ;
}

int lca( int a, int b ) {
    if( lv[a] > lv[b] ) swap( a, b );
    for( int i = 17 ; i >= 0 ; i-- ) if( lv[mic[i][b]] >= lv[a] ) b = mic[i][b];
    if( a == b ) return a;
    for( int i = 17 ; i >= 0 ; i-- ) if( mic[i][a] != mic[i][b] ) a = mic[i][a], b = mic[i][b];
    return mic[0][a];
}

int main()
{
    scanf("%d",&n);
    for( int i = 0, s, e ; i < n - 1 ; i++ ) {
        scanf("%d %d",&s,&e);
        g[s].emplace_back( e );
        in[e]++;
    }
    for( int i = 1 ; i <= n ; i++ ) if( !in[i] ) {
        rt = i;
        break;
    }
    dfs( rt, 0 );
    for( int i = 1 ; i <= 17 ; i++ ) for( int j = 1 ; j <= n ; j++ ) mic[i][j] = mic[i-1][mic[i-1][j]];
    scanf("%d",&q);
    while( q-- ) {
        scanf("%d %d",&a,&b);
        printf("%d\n",lca( a, b ));
    }
    return 0;
}