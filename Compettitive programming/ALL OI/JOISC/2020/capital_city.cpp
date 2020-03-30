#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
 
using namespace std;
 
const int N = 2e5 + 10;
int par[N], cc[N], sz[N], c[N], cnt[N], ans = 1e9, n, k;
bool chk[N];
vector<int> col[N], g[N];
queue<int> q;
 
int getsz( int u, int p ) { sz[u] = 1; for( int v : g[u] ) if( v != p && !chk[v] ) sz[u] += getsz( v, u ); return sz[u]; }
 
int findcen( int now, int p, int all, pii &ret ) {
	int mx = all - sz[now];
	for( int v : g[now] ) if( v != p && !chk[v] ) mx = max( mx, findcen( v, now, all, ret ) );
	ret = min( ret, pii( mx, now ) );
	return sz[now];
}
 
void dfs( int u, int p, bool fill ) {
    if( fill ) col[c[u]].emplace_back( u ), par[u] = p;
    else col[c[u]].clear(), par[u] = -1, cc[c[u]] = false;
    for( int v : g[u] ) if( v != p && !chk[v] ) dfs( v, u, fill ); 
}
 
void centroid( int u ) {
    pii ret( 1e9, -1 );
    getsz( u, u );
    findcen( u, u, sz[u], ret );
    u = ret.y;
    dfs( u, u, true );
    bool check = true;
    int cou = 1;
    q.emplace( c[u] ), cc[c[u]] = true;
    while( !q.empty() ) {
        int now = q.front(); q.pop();
        if( col[now].size() != cnt[now] ) { 
            check = false;
            break ;
        }
        for( int x : col[now] ) if( x != u && !cc[c[par[x]]] ) {
            cc[c[par[x]]] = true;
            cou++;
            q.emplace( c[par[x]] );
        }
    }
    while( !q.empty() ) q.pop();
    if( check ) ans = min( ans, cou );
    dfs( u, u, false ), chk[u] = true;
    for( int v : g[u] ) if( !chk[v] ) centroid( v );
 
}
 
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&c[i]);
        cnt[c[i]]++;
    }
    centroid( 1 );
    printf("%d\n",ans-1);
    return 0;
}   