#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

int n, m, vis[N], cc[N], cnode[N], idx, cycsz, lz[N*4], lz2[N*4];
int id[N], par[N], dep[N], rot[N], pos[N], t1[N*4], t2[N*4], sz[N];
vector<int> g[N], cyc;

void findcyc( int u, int p ) {
    static vector<int> s;
    s.emplace_back( u );
    vis[u] = 1;
    for( int v : g[u] ) if( v != p ) {
        if( !vis[v] ) findcyc( v, u );
        else if( vis[v] == 1 ) {
            for( int i = (int)s.size() - 1 ; i >= 0 ; i-- ) {
                cyc.emplace_back( s[i] );
                cc[s[i]] = 1;
                if( s[i] == v ) break;
            }
        }
    }
    s.pop_back(), vis[u] = 2;
}

void dfs( int u, int p, int ro, int ind ) {
    if( p ) g[u].erase( find( g[u].begin(), g[u].end(), p ) );
    par[u] = p, sz[u] = 1, cnode[u] = ro, id[u] = ind, dep[u] = dep[p] + 1;
    for( int &v : g[u] ) if( v != p && !cc[v] ) {
        dfs( v, u, ro, ind );
        sz[u] += sz[v];
        if( sz[v] > sz[g[u][0]] ) swap( v, g[u][0] );
    }
}

void hld( int u ) {
    if( !par[u] || u != g[par[u]][0] ) rot[u] = u;
    else rot[u] = rot[par[u]];
    pos[u] = ++idx;
    for( int v : g[u] ) if( !cc[v] ) hld( v );
}

void push1( int l, int r, int now ) {
    if( !lz[now] ) return ;
    if( lz[now] == 1 ) t1[now] = r - l + 1;
    else t1[now] = 0;
    if( l != r ) lz[now<<1] = lz[now<<1|1] = lz[now];
    lz[now] = 0;
}

void update1( int ll, int rr, int c, int l = 1, int r = n, int now = 1 ) {
    push1( l, r, now );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz[now] = c;
        push1( l, r, now );
        return ;
    }
    int mid = l + r >> 1;
    update1( ll, rr, c, l, mid, now<<1 ), update1( ll, rr, c, mid+1, r, now<<1|1 );
    t1[now] = t1[now<<1] + t1[now<<1|1];
    return ;
}

void push2( int l, int r, int now ) {
    if( !lz2[now] ) return ;
    if( lz2[now] == 1 ) t2[now] = r - l + 1;
    else t2[now] = 0;
    if( l != r ) lz2[now<<1] = lz2[now<<1|1] = lz2[now];
    lz2[now] = 0;
}

void update2( int ll, int rr, int c, int l = 1, int r = n, int now = 1 ) {
    push2( l, r, now );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz2[now] = c;
        push2( l, r, now );
        return ;
    }
    int mid = l + r >> 1;
    update2( ll, rr, c, l, mid, now<<1 ), update2( ll, rr, c, mid+1, r, now<<1|1 );
    t2[now] = t2[now<<1] + t2[now<<1|1];
    return ;
}


void updatehld( int a, int b, int c ) {
    while( rot[a] != rot[b] ) {
        if( dep[rot[a]] < dep[rot[b]] ) swap( a, b );
        update1( pos[rot[a]], pos[a], c );
        a = par[rot[a]];
    }
    if( dep[a] > dep[b] ) swap( a, b );
    update1( pos[a]+1, pos[b], c );
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    findcyc( 1, 0 );
    for( int i : cyc ) {
        dfs( i, 0, i, ++cycsz );
        hld( i );
       // printf("%d ",i);
    }
    //printf("\n");
    while( m-- ) {
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        c = c ? -1 : 1;
        if( id[a] == id[b] ) updatehld( a, b, c );
        else {
            if( id[a] > id[b] ) swap( a, b );
            updatehld( a, cnode[a], c ), updatehld( b, cnode[b], c );
            //printf("%d %d\n",id[a],id[b]);
            if( 2*( id[b] - id[a] ) <= cycsz ) update2( id[a], id[b]-1, c );
            if( 2*( id[b] - id[a] ) >= cycsz ) update2( id[b], cycsz, c ), update2( 1, id[a]-1, c );
        }
        printf("%d\n",1+t1[1]+max( 0,t2[1]-1 ) );
    }
    return 0;
}