#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

vector<pii> edge, g[N], g2[N], query, coord;
int n, m, q, pre[N], low[N], lca[18][N], dep[N], co[N], e[N], dir[N], c;
bool bridge[M];
char label[N];

void find_bridge( int u, int p, int ee ) {
    static int idx = 0;
    pre[u] = low[u] = ++idx;
    for( pii v : g[u] ) if( !pre[v.x] ) {
        find_bridge( v.x, u, v.y );
        low[u] = min( low[u], low[v.x] );
        if( low[v.x] > pre[u] ) bridge[v.y] = 1; 
    } else if( v.y != ee ) low[u] = min( low[u], pre[v.x] );
}

void component( int u, int p ) {
    co[u] = c;
    for( pii v : g[u] ) if( v.x != p ) {
        if( !co[v.x] && !bridge[v.y] ) component( v.x, u );
    }
}

void init_lca( int u, int p, int ee ) {
    lca[0][u] = p, dep[u] = dep[p] + 1, e[u] = ee;
    for( int i = 1 ; i <= 17 ; i++ ) lca[i][u] = lca[i-1][lca[i-1][u]];
    for( pii v : g2[u] ) if( v.x != p ) init_lca( v.x, u, v.y );
}

int find_lca( int a, int b ) {
    if( dep[a] < dep[b] ) swap( a, b );
    for( int i = 17 ; i >= 0 ; i-- ) if( dep[lca[i][a]] >= dep[b] ) a = lca[i][a];
    if( a == b ) return a;
    for( int i = 17 ; i >= 0 ; i-- ) if( lca[i][a] != lca[i][b] ) a = lca[i][a], b = lca[i][b];
    return lca[0][a];
}

void direct( int x, int z, int di ) {
    if( x == z ) return ;
    if( dir[x] == 0 ) {
        dir[x] = di;
        int y = lca[0][x], i = e[x];
        int a = co[edge[i].x], b = co[edge[i].y];
        if( di == -1 ) {
            if( a == x && b == y ) label[i] = 'R'; 
            else label[i] = 'L'; 
        } else {
            if( a == y && b == x ) label[i] = 'R';
            else label[i] = 'L';
        }
        direct( y, z, di );
    } 
}

int main() 
{
	scanf("%d %d",&n,&m);
    edge.emplace_back( pii( 0, 0 ) );
    for( int i = 1, a, b ; i <= m ; i++ ) {
        scanf("%d %d",&a,&b);
        if( a == b ) continue;
        g[a].emplace_back( pii( b, i ) ), g[b].emplace_back( pii( a, i ) );
        edge.emplace_back( pii( a, b ) );
    }
    for( int i = 1 ; i <= n ; i++ ) if( !pre[i] ) find_bridge( i, 0, 0 );
    for( int i = 1 ; i <= n ; i++ ) if( !co[i] ) ++c, component( i, 0 );
    for( int i = 1 ; i <= m ; i++ ) if( bridge[i] ) {
        int f = co[edge[i].x], t = co[edge[i].y];
        g2[f].emplace_back( pii( t, i ) ), g2[t].emplace_back( pii( f, i ) );
    }
    for( int i = 1 ; i <= n ; i++ ) if( !dep[i] ) init_lca( i, 0, 0 );
    for( int i = 1 ; i <= m ; i++ ) label[i] = 'B';
    scanf("%d",&q);
    query.emplace_back( pii( 0, 0 ) );
    for( int i = 1, a, b ; i <= q ; i++ ) {
        scanf("%d %d",&a,&b);
        a = co[a], b = co[b];
        int c = find_lca( a, b );
        query.emplace_back( pii( a, b ) );
        coord.emplace_back( pii( dep[c], i ) );
    }
    sort( coord.begin(), coord.end() );
    for( pii i : coord ) {
        int y = i.y;
        int a = query[y].x, b = query[y].y;
        int c = find_lca( a, b );
        direct( a, c, -1 ), direct( b, c, 1 );
    }
    for( int i = 1 ; i <= m ; i++ ) printf("%c",label[i]);
    return 0;
}
