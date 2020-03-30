#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t[N], sz[N], ti, va[N], n, key[N], st[N], en[N], hv[N], ans[N];
vector<int> g[N], coord;

void update( int idx, int va ) { for( int i = idx ; i < N ; i += i & -i ) t[i] += va; }

int query( int idx ) {
    int ret = 0;
    for( int i = N - 1 ; i > 0 ; i -= i & -i ) ret += t[i];
    for( int i = idx ; i > 0 ; i -= i & -i ) ret -= t[i];
    return ret;
}

void dfs( int u, int p ) {
    int mx = -1;
    hv[u] = -1, sz[u] = 1, st[u] = ++ti, key[ti] = u;
    for( int v : g[u] ) if( v != p ) {
        dfs( v, u );
        if( sz[v] > mx ) mx = sz[v], hv[u] = v;
    }
    en[u] = ti;
}

void sack( int u, int p, bool fill ) {
    //printf("%d %d\n",u,p);
    for( int v : g[u] ) if ( v != p && v != hv[u] ) sack( v, u, 0 );
    if( hv[u] != -1 ) sack( hv[u], u, 1 );
    //printf("U P : %d %d\n",u,p);
    //printf("%d\n",query( 0 ));
    for( int v : g[u] ) if( v != p && v != hv[u] ) {
        for( int i = st[v] ; i <= en[v] ; i++ ) update( va[key[i]], 1 );
    }
    ans[u] = query( va[u] );
    update( va[u], 1 );
    if( !fill ) for( int i = st[u] ; i <= en[u] ; i++ ) update( va[key[i]], -1 );
}

int get( int x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + 1; }

int main()
{
    freopen( "promote.in", "r", stdin );
    freopen( "promote.out", "w", stdout );
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&va[i]);
        coord.emplace_back( va[i] );
    }
    for( int i = 2, a ; i <= n ; i++ ) {
        scanf("%d",&a);
        g[a].emplace_back( i ), g[i].emplace_back( a );
    }
    sort( coord.begin(), coord.end() );
    coord.resize( unique( coord.begin(), coord.end() ) - coord.begin() );
    dfs( 1, 0 );
    for( int i = 1 ; i <= n ; i++ ) va[i] = get( va[i] );
    sack( 1, 0, 1 );
    for( int i = 1 ; i <= n ; i++ ) printf("%d\n",ans[i]);
    return 0;
}