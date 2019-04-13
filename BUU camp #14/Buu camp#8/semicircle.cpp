#include <bits/stdc++.h>

using namespace std;
struct cc{
    int f, t;
}c[710];
vector<int> g[710];
int cou[710];
int q;
int n;
int check( int i, int j )
{
    if( c[j].f > c[i].f && c[j].f < c[i].t && c[j].t > c[i].t )return 1;
    swap( i, j );
    if( c[j].f > c[i].f && c[j].f < c[i].t && c[j].t > c[i].t )return 1;
    return 0;
}
int dfs( int now ,int p, int co )
{
    cou[now] = co;
    for( int i = 0 ; i < g[now].size() ; i++ ){
        if( g[now][i] == p )continue;
        if( cou[g[now][i]] == cou[now] )return 0;
        if( cou[g[now][i]] == -1 ){
            if( !dfs( g[now][i], now, co ^ 1 ) )return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&q);
    while( q-- ){
        memset( cou, -1, sizeof cou );
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d %d",&c[i].f,&c[i].t);
        }
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = i + 1 ; j <= n ; j++ ){
                if( check( i, j ) ){
                    g[i].push_back( j );
                    g[j].push_back( i );
                }
            }
        }
        int ccc = 0, cnt = 1;
        for( int i = 1 ; i <= n ; i++ ){
            if( cou[i] == -1 ){
                if( !dfs( i, 0, 1 ) ){
                    printf("0\n");
                    ccc = 1;
                    break;
                }
                else{
                    cnt *= 2;
                    cnt %= 1001;
                }
            }
        }
        if( !ccc )printf("%d\n",cnt);
        for( int i = 0 ; i < 710 ; i++ )g[i].clear();
    }
}
