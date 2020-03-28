#include <bits/stdc++.h>
#include "beauty.h"
#define vi vector<int>

using namespace std;

const int N = 2e5 + 10;
vector<vi> g, ccs;
int n, m, q, lca[19][N], pre[N], low[N], cost[N], dep[N], id[N], mx[19][N], a[N];
bool cut[N], art[N];

void find_component( int u, int p ) {
    static int idx = 0;
    static stack<int> s;
    low[u] = pre[u] = ++idx;
    s.emplace( u );
    int chk = 0;
    for( int v : g[u] ) if( !pre[v] ) {
        find_component( v, u );
        chk++;
        low[u] = min( low[u], low[v] );
        if( !p && chk > 1 || p && low[v] >= pre[u] ) art[u] = true;
        if( low[v] >= pre[u] ) {
            ccs.emplace_back( vi() );
            ccs.back().emplace_back( u );
            while( ccs.back().back() != v ) ccs.back().emplace_back( s.top() ), s.pop();
        }
    } else if( v != p ) low[u] = min( low[u], pre[v] );
}

void gen_bct() {
    g.clear(), g.emplace_back( vi() );
    for( int i = 1 ; i <= n ; i++ ) if( art[i] ) {
        cut[id[i]=g.size()] = true;
        cost[id[i]] = a[i];
        g.emplace_back( vi() );
    }
    for( vi &cc : ccs ) {
        g.emplace_back( vi() );
        for( int v : cc ) {
            if( art[v] ) g[id[v]].emplace_back( (int)g.size() - 1 ), g[(int)g.size()-1].emplace_back( id[v] );
            else id[v] = (int)g.size() - 1;
            cost[(int)g.size()-1] = max( cost[(int)g.size()-1], a[v] );
        }
    }
}

void init_lca( int u, int p ) {
    lca[0][u] = p, mx[0][u] = cost[u], dep[u] = dep[p] + 1; 
    for( int i = 1 ; i <= 18 ; i++ ) {
        mx[i][u] = max( mx[i-1][u], mx[i-1][lca[i-1][u]] );
        lca[i][u] = lca[i-1][lca[i-1][u]];
    }
    for( int v : g[u] ) if( v != p ) init_lca( v, u );
}

int solve( int a, int b ) {
    int ret = 0;
    if( dep[a] < dep[b] ) swap( a, b );
    for( int i = 18 ; i >= 0 ; i-- ) if( dep[lca[i][a]] >= dep[b] ) {
        ret = max( ret, mx[i][a] );
        //printf("%d %d\n",i,mx[i][a]);
        a = lca[i][a];
    }
    if( a == b ) return max( ret, mx[0][a] );
    for( int i = 18 ; i >= 0 ; i-- ) if( lca[i][a] != lca[i][b] ) {
        ret = max( ret, max( mx[i][a], mx[i][b] ) );
        a = lca[i][a], b = lca[i][b];
    }
    //printf("%d %d %d %d\n",ret,mx[1][a],mx[1][b]);
    return max( ret, max( mx[1][a], mx[1][b] ) );
}

vector<int> getMaximumBeauty(int _n, int _m, int _q, vector<int> T, vector<int> U, vector<int> V, vector<int> A, vector<int> B) {
    n = _n, m = _m, q = _q;
    g.resize( n + 1 );
    for( int i = 1 ; i <= n ; i++ ) a[i] = T[i-1];
    for( int i = 0 ; i < m ; i++ ) g[U[i]].emplace_back(V[i]), g[V[i]].emplace_back(U[i]);
    find_component( 1, 0 ), gen_bct(), init_lca( 1, 0 );
    /*printf("\n");
    for( int i = 1 ; i <= n ; i++ ) printf("%d ",id[i]);
    printf("\n");*/
    vector<int> ans;
    for(int i = 0; i < q; i++) {
        //printf("%d %d %d %d\n",id[A[i]],cost[id[A[i]]],id[B[i]], cost[id[B[i]]] );
        if(id[A[i]] == id[B[i]]) ans.emplace_back(cost[id[A[i]]]);
        else ans.emplace_back(solve(id[A[i]], id[B[i]]));
    }
    return ans;
}

/*int main() {
    int n, m, q;
    vi t, u, v, a, b;
    scanf("%d %d %d",&n,&m,&q);
    for( int i = 1, te ; i <= n ; i++ ) {
        scanf("%d",&te);
        t.emplace_back( te );
    }
    for( int i = 1, be ; i <= m ; i++ ) {
        scanf("%d",&be);
        u.emplace_back( be );
    }
    for( int i = 1, be ; i <= m ; i++ ) {
        scanf("%d",&be);
        v.emplace_back( be );
    }
    for( int i = 1, x ; i <= q ; i++ ) {
        scanf("%d",&x);
        a.emplace_back( x );
    }
    for( int i = 1, x ; i <= q ; i++ ) {
        scanf("%d",&x);
        b.emplace_back( x );
    }
    vi ans = getMaximumBeauty( n, m, q, t, u, v, a, b );
    for( int i = 0 ; i < q ; i++ ) printf("%d ",ans[i]);
}*/