#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 10;

int n, q, ptr, par[N], sz[N], chk[N], dep[N], d[N][18];
ordered_set<pii> s1[N], s2[N];
vector<int> g[N];

int getsz( int u, int p ) {
    sz[u] = 1;
    for( int v : g[u] ) if( v != p && !chk[v] ) sz[u] += getsz( v, u );
    return sz[u];
}

int findcen( int u, int p, int all, pii &ret ) {
    int mx = all - sz[u];
    for( int v : g[u] ) if( v != p && !chk[v] ) 
        mx = max( mx, findcen( v, u, all, ret ) );
    ret = min( ret, pii( mx, u ) );
    return sz[u];
}

void dfs( int u, int p, int dep ) {
    for( int v : g[u] ) if( v != p && !chk[v] ) {
        d[v][dep] = d[u][dep] + 1;
        dfs( v, u, dep );
    }
}

void build_centroid( int u, int p ) {
    pii ret( 1e9, -1 );
    getsz( u, u ), findcen( u, u, sz[u], ret );
    par[u = ret.y] = p, dep[u] = dep[p] + 1, chk[u] = 1;
    dfs( u, u, dep[u] );
    for( int v : g[u] ) if( !chk[v] ) build_centroid( v, u );
}

void update( int a, int k ) {
    s1[a].insert( pii( k, ++ptr ) );
    for( int i = par[a], pv = a ; i != 0 ; pv = i, i = par[i] ) {
        //printf("A : %d I : %d %d\n",a,i,d[a][dep[i]]);
        if( k >= d[a][dep[i]] ) {
            s1[i].insert( pii( k - d[a][dep[i]], ++ptr ) );
            s2[pv].insert( pii( k - d[a][dep[i]], ptr ) );
        }
    }
}

int query( int a ) {
    int ret = s1[a].size();
    //printf("ret : %d\n",ret);
    for( int i = par[a], pv = a ; i != 0 ; pv = i, i = par[i] ) {
        ret += ( s1[i].size() - s1[i].order_of_key( pii( d[a][dep[i]], 0 ) ) );
        ret -= ( s2[pv].size() - s2[pv].order_of_key( pii( d[a][dep[i]], 0 ) ) );
    }
    return ret;
}

int main()
{
    scanf("%d %d",&n,&q);
    for( int i = 1, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    build_centroid( 1, 0 );
    while( q-- ) {
        int a, b, c;
        scanf("%d %d",&a,&b);
        if( a == 1 ) {
            scanf("%d",&c);
            update( b, c );
        }
        else printf("%d\n",query( b ) );
    }
    return 0;
}