#include<bits/stdc++.h>

using namespace std;
int t, n, ma;
int mic[100100][10], q[100100];
vector<int> g[100100];
void dfs( int now, int p )
{
    mic[now][0] = q[now];
    for( int i = 0 ; i < g[now].size() ; i++ ){
        if( g[now][i] == p )continue;
        dfs( g[now][i], now );
        for( int j = 0 ; j < 4 ; j++ ){
            ma = max( ma, mic[now][j] + mic[g[now][i]][4-j-1] );
        }
        for( int j = 1 ; j <= 4 ; j++ ){
            mic[now][j] = max( mic[now][j], mic[g[now][i]][j-1] );
        }
    }
}
int main()
{
    scanf("%d",&t);
    while( t-- ){
        scanf("%d",&n);
        for( int i = 0 ; i <= 100000 ; i++ )g[i].clear();
        for( int i = 0 ; i < 5 ; i ++ )
            for( int j = 0 ; j <= 100000 ; j++ )
                mic[j][i] = -1e9 - 5;
        ma = -1;
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&q[i]);
        }
        for( int i = 0 ; i < n - 1 ; i++ ){
            int f, t;
            scanf("%d %d",&f,&t);
            g[f].push_back( t );
            g[t].push_back( f );
        }
        dfs( 1, 0 );
        printf("%d\n",ma);
    }
    return 0;
}
