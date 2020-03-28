#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define vi vector<int>
using namespace std;

const int N = 2e5 + 10;
int n, m, q;
int lca[19][N], low[N], pre[N], block[N], id[N], lv[N];
bool art[N], cut[N];
vector<vi> g, ccs;
vi sz;

void find_component( int u, int p ) {
    static int idx = 0;
    static stack<int> s;
    pre[u] = low[u] = ++idx;
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
    }
    else if( v != p ) low[u] = min( low[u], pre[v] ); 
}

void gen_bct() {
    g.clear(); g.emplace_back( vi() ), sz.emplace_back( 0 );
    for( int i = 1 ; i <= n ; i++ ) if( art[i] ) {
        cut[id[i] = g.size()] = true;
        sz.emplace_back( 1 );
        g.emplace_back( vi() );
    }
    for( vi &cc : ccs ) {
        g.emplace_back( vi() );
        sz.emplace_back( cc.size() );
        for( int v : cc ) {
            if( art[v] ) g[id[v]].emplace_back( g.size() - 1 ), g[(int)(g.size())-1].emplace_back( id[v] );
            else id[v] = ((int)g.size())- 1;
        }
    }
}
 
void init_lca( int u, int p ) { 
    lca[0][u] = p, lv[u] = lv[p] + 1, block[u] = block[p] + ( sz[u] - 2*( !cut[u] ) );
    for( int i = 1 ; i <= 18 ; i++ ) lca[i][u] = lca[i-1][lca[i-1][u]];
    for( int v : g[u] ) if( v != p ) init_lca( v, u );    
}

int find_lca( int a, int b ) {
    if( lv[a] < lv[b] ) swap( a, b );
    for( int i = 18 ; i >= 0 ; i-- ) if( lv[lca[i][a]] >= lv[b] ) a = lca[i][a];
    if( a == b ) return a;
    for( int i = 18 ; i >= 0 ; i-- ) if( lca[i][a] != lca[i][b] ) a = lca[i][a], b = lca[i][b];
    return lca[0][a];
}

int main()
{
    scanf("%d %d %d",&n,&m,&q);
    g.resize( n+1 );
    for( int i = 0, a, b ; i < m ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    find_component( 1, 0 );
    gen_bct();
    //printf("\n");
    init_lca( 1, 0 );
    for( int i = 0, a, b ; i < q ; i++ ) {
        scanf("%d %d",&a,&b);
        a = id[a], b = id[b];
        if( a == b ) {
            printf("%d\n",sz[a]-2);
            continue ;
        }
        int c = find_lca( a, b );
        //printf("%d %d %d\n",a,b,c);
        //printf("%d %d %d %d\n",block[a],block[b],block[c],block[lca[0][c]]);
        int ans = block[a] + block[b] - block[c] - block[lca[0][c]];
        ans -= ( cut[a] + cut[b] );
        printf("%d\n",ans);
    } 
    return 0;
}