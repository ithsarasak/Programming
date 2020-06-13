#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int INF = 1e9;

const int N = 1e5 + 10;
int n, par[N], rot[N], lev[N], col[N], sz[N], pos[N], dep[N];
pii pv[N];
vector<int> g[N];

struct node {
    vector<int> v;
    node() { 
        v = vector<int>( 4, INF );
        v[0] = v[3] = 0;
    }
    friend node operator+( const node &a, const node &b ) {
        node ret;
        ret.v = vector<int>( 4, INF );
        for( int i = 0 ; i < 4 ; i++ ) for( int j = 0 ; j < 4 ; j++ ) {
            int bit = ( i&2 ) + ( j&1 );
            int dif = ( i&1 ) != ( (j>>1)&1 );
            ret.v[bit] = min( ret.v[bit], a.v[i] + b.v[j] + dif );
        }
        return ret;
    }
}t[N*4];

node query( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    if( l >= ll && r <= rr ) return t[idx];
    int mid = l + r >> 1;
    if( rr <= mid ) return query( ll, rr, l, mid, idx<<1 );
    else if( ll > mid ) return query( ll, rr, mid+1, r, idx<<1|1 );
    return query( ll, rr, l, mid, idx<<1 ) + query( ll, rr, mid+1, r, idx<<1|1 );
}

void update( int x, pii k, int l = 1, int r = n, int idx = 1 ) {
    if( l == r ) {
        t[idx].v[0] += k.x, t[idx].v[3] += k.y;
        return ;
    }
    int mid = l + r >> 1;
    if( x <= mid ) update( x, k, l, mid, idx<<1 );
    else update( x, k, mid+1, r, idx<<1|1 );
    t[idx] = t[idx<<1] + t[idx<<1|1];
}

void build( int l = 1, int r = n, int idx = 1 ) {
    if( l == r ) return ;
    int mid = l + r >> 1;
    build( l, mid, idx<<1 ), build( mid+1, r, idx<<1|1 );
    t[idx] = t[idx<<1] + t[idx<<1|1];
}

void updatehld( int u, pii now ) {
    while( u ) {
        update( pos[u], now );
        node que = query( pos[rot[u]], pos[lev[rot[u]]] );
        int x = min( que.v[0], que.v[1] ), y = min( que.v[2], que.v[3] );
        now = pii( min( x, y+1 ), min( x+1, y ) );
        pii temp = now;
        now.x = now.x - pv[rot[u]].x, now.y = now.y - pv[rot[u]].y;
        pv[rot[u]] = temp;
        u = par[rot[u]];
    }
    return ;
}

void dfs( int u, int p ) {
    sz[u] = 1, par[u] = p, dep[u] = dep[p] + 1;
    if( p ) g[u].erase( find( g[u].begin(), g[u].end(), p ) );
    for( int &v : g[u] ) {
        dfs( v, u );
        sz[u] += sz[v];
        if( sz[v] > sz[g[u][0]] ) swap( v, g[u][0] );
    }
}

void hld( int u ) {
    static int idx = 0;
    if( !par[u] || u != g[par[u]][0] ) rot[u] = u;
    else rot[u] = rot[par[u]];
    lev[rot[u]] = u;
    pos[u] = ++idx;
    for( int v : g[u] ) hld( v );
} 

int cat( int u ) {
    col[u] = 1;
    updatehld( u, pii( 0, INF ) );
    node ans = query( pos[rot[1]], pos[lev[1]] );
    int ret = INF;
    for( int i = 0 ; i < 4 ; i++ ) ret = min( ret, ans.v[i] );
    return ret;
}

int dog( int u ) {
    col[u] = 2;
    updatehld( u, pii( INF, 0 ) );
    node ans = query( pos[rot[1]], pos[lev[1]] );
    int ret = INF;
    for( int i = 0 ; i < 4 ; i++ ) ret = min( ret, ans.v[i] );
    return ret;
}

int neighbor( int u ) {
    if( col[u] == 1 ) updatehld( u, pii( 0, -INF ) );
    else if( col[u] == 2 ) updatehld( u, pii( -INF, 0 ) );
    col[u] = 0;
    node ans = query( pos[rot[1]], pos[lev[1]] );
    int ret = INF;
    for( int i = 0 ; i < 4 ; i++ ) ret = min( ret, ans.v[i] );
    return ret;
}

void initialize( int _N, vector<int> A, vector<int> B ) {
    n = _N;
    for( int i = 0 ; i < n-1 ; i++ ) {
        g[A[i]].emplace_back( B[i] );
        g[B[i]].emplace_back( A[i] );
    }
    dfs( 1, 0 ), hld( 1 ), build();
}
