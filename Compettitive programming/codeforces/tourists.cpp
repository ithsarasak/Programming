#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, m, q, w[N], low[N], pre[N], t[4*N], par[N][20], mincom[N], id[N], idx[N], sz[N], cnt;
int rot[N], dep[N];
bool art[N];
vector<vector<int>> g(N), ccs;
multiset<int> s[N];

void update( int x, int va, int l = 1, int r = cnt, int idx = 1 ) {
    if( l > x || r < x ) return ;
    if( l == r ) return void( t[idx] = va );
    int mid = l + r >> 1;
    update( x, va, l, mid, idx<<1 ), update( x, va, mid+1, r, idx<<1|1 );
    t[idx] = min( t[idx<<1], t[idx<<1|1] );
}

int query( int ll, int rr, int l = 1, int r = cnt, int idx = 1 ) {
    if( l > rr || r < ll ) return 1e9;
    if( l >= ll && r <= rr ) return t[idx];
    int mid = l + r >> 1;
    return min( query( ll, rr, l, mid, idx<<1 ), query( ll, rr, mid+1, r, idx<<1|1 ) );
}

void tarjan( int u, int p ) {
    static stack<int> st;
    static int ti;
    pre[u] = low[u] = ++ti;
    int chk = 0;
    st.emplace( u );
    for( int v : g[u] ) if( !pre[v] ) {
        tarjan( v, u );
        chk++;
        low[u] = min( low[u], low[v] );
        if( !p && chk > 1 || p && low[v] >= pre[u] ) {
            id[u] = u;
            art[u] = true;
        }
        if( low[v] >= pre[u] ) {
            ccs.emplace_back( vector<int>() );
            ccs.back().emplace_back( u );
            while( ccs.back().back() != v ) ccs.back().emplace_back( st.top() ), st.pop();
        }
    } else if( v != p ) low[u] = min( low[u], pre[v] );
}

void gen_bct() {
    g.clear(), g.resize( n+1 );
    for( auto &cc : ccs ) {
        g.emplace_back( vector<int>() );
        int idx = g.size() - 1;
        for( int u : cc ) {
            if( art[u] ) g[u].emplace_back( g.size() - 1 ), g[idx].emplace_back( u );
            else id[u] = idx;
        }
    }
}

int dfs( int u, int p ) {
    sz[u] = 1, par[u][0] = p;
    dep[u] = dep[p] + 1;
    for( int i = 1 ; i <= 18 ; i++ ) par[u][i] = par[par[u][i-1]][i-1];
    if( p ) g[u].erase( find( g[u].begin(), g[u].end(), p ) );
    for( int &v : g[u] ) {
        sz[u] += dfs( v, u );
        if( sz[v] > sz[g[u][0]] ) swap( v, g[u][0] );
    }
    return sz[u];
}

void hld( int u ) {
    if( !par[u][0] || u != g[par[u][0]][0] ) rot[u] = u;
    else rot[u] = rot[par[u][0]];
    if( art[u] ) s[u].insert( w[u] );
    else for( int x : ccs[u-n-1] ) if( x != par[u][0] ) s[u].insert( w[x] ); 
    idx[u] = ++cnt;
    for( int v : g[u] ) hld( v );
}

void dfs2( int u ) {
    update( idx[u], *s[u].begin() );
    for( int v : g[u] ) dfs2( v );
}

int queryhld( int a, int b ) {
    int ret = 1e9;
    while( rot[a] != rot[b] ) {
        if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
        ret = min( ret, query( idx[rot[a]], idx[a] ) );
        a = par[rot[a]][0];
    }
    if( dep[a] > dep[b] ) swap( a, b );
    ret = min( ret, query( idx[a], idx[b] ) );
    return ret;
}

int findlca( int a, int b ) {
    if( dep[a] < dep[b] ) swap( a, b );
    for( int i = 18 ; i >= 0 ; i-- ) if( dep[par[a][i]] >= dep[b] ) a = par[a][i];
    if( a == b ) return a;
    for( int i = 18 ; i >= 0 ; i-- ) if( par[a][i] != par[b][i] ) a = par[a][i], b = par[b][i];
    return par[a][0];
}

int main()
{
    memset( t, 127, sizeof t );
    scanf("%d %d %d",&n,&m,&q);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&w[i]);
    for( int i = 1, a, b ; i <= m ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    tarjan( 1, 0 ), gen_bct(), dfs( n+1, 0 ), hld( n+1 ), dfs2( n+1 );
    while( q-- ) {
        char c;
        int a, b;
        scanf(" %c %d %d",&c,&a,&b);
        if( c == 'A' ) {
            if( a == b ) {
                printf("%d\n",w[a]);
                continue ;
            }
            a = id[a], b = id[b];
            int x = findlca( a, b ), ret = queryhld( a, b );
            if( !art[x] && par[x][0] != 0 ) ret = min( ret, *s[par[x][0]].begin() );
            printf("%d\n",ret);
        }
        else {
            s[id[a]].erase( s[id[a]].lower_bound( w[a] ) );
            s[id[a]].insert( b );
            update( idx[id[a]], *s[id[a]].begin() );
            if( art[a] ) {
                int p = par[id[a]][0];
                s[p].erase( s[p].lower_bound( w[a] ) );
                s[p].insert( b );
                update( idx[p], *s[p].begin() );
            }
            w[a] = b;
        }
    }
    return 0;
}