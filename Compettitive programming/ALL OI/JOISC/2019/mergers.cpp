#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first 
#define y second 

using namespace std;

const int N = 5e5 + 10;

int par[N], dep[N], dsu[N], deg[N], n, k, cnt;
vector<int> g[N], co[N];
vector<pii> e;

void pre( int now, int p ) {
    par[now] = p, dep[now] = dep[p] + 1;
    for( int i : g[now] ) if( i != p ) pre( i, now );
}

int find( int now ) { return dsu[now] = dsu[now] == now ? now : find( dsu[now] ); }

int main()
{
    scanf("%d %d",&n,&k);
    e.reserve(n);
    for( int i = 1 ; i <= n ; i++ ) dsu[i] = i;
    for( int i = 1, u, v ; i <= n - 1 ; i++ ) {
        scanf("%d %d",&u,&v);
        g[u].emplace_back( v ), g[v].emplace_back( u );
        e.emplace_back( pii( u, v ) ); 
    }
    for( int i = 1, s ; i <= n ; i++ ) {
        scanf("%d",&s);
        co[s].emplace_back( i );
    }
    pre( 1, 0 );
    for( int i = 1 ; i <= k ; i++ ) if( co[i].size() > 1 ) {
        for( int j = 1 ; j < co[i].size() ; j++ ) {
            int a = find( co[i][j] ), b = find( co[i][j-1] );
            while( a != b ) {
                if( dep[a] < dep[b] ) swap( a, b );
                a = dsu[a] = find( par[a] );
            }
        }
    }
    for(auto &x : e) if(find(x.x) != find(x.y)) deg[find(x.x)]++, deg[find(x.y)]++;
    for( int i = 1 ; i <= n ; i++ ) if( deg[i] == 1 ) cnt++;
    printf("%d",( cnt + 1 ) / 2);
}