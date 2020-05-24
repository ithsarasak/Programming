#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e3 + 10;

int t, c, d, pos[N], ans[N], di[N], now;

int main()
{
    scanf("%d", &t);
    for( int z = 1 ; z <= t ; z++ ) {
        now = 0;
        vector<pii> g[N];
        vector<int> ti[N];
        memset( di, -1, sizeof di ), memset( ans, -1, sizeof ans );
        scanf("%d %d",&c,&d);
        di[1] = 0;
        for( int i = 2, pos ; i <= c ; i++ ) {
            scanf("%d",&pos);
            pos *= -1;
            ti[pos].emplace_back(i);
        }
        for( int i = 0, u, v ; i < d ; i++ ) {
            scanf("%d %d", &u, &v);
            g[u].emplace_back( pii( v, i ) );
            g[v].emplace_back( pii( u, i ) );
        }
        for( int i = 0 ; i <= c ; i++ ) {
            if( !ti[i].empty() ) now++;
            for( int u : ti[i] ) for( pii v : g[u] ) if( di[v.x] != -1 ) ans[v.y] = now - di[v.x];
            for( int u : ti[i] ) di[u] = now;
        } 
        printf("Case #%d: ",z);
        for( int i = 0 ; i < d ; i++ ) printf("%d ", ans[i] == -1 ? 1 : ans[i]);
        printf("\n");
    }
}