#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

const int N = 2e5 + 10;

int n, t, d, dep[N], sz[N], st[N], en[N], hv[N];
vector<int> g[N];
multiset<int> s;

void dfs( int u, int p ) {
    st[u] = ++t, sz[u] = 1, dep[u] = dep[p] + 1;
    pii ret( -1e9, -1 );
    for( int v : g[u] ) if( v != p ) {
        dfs( v, u );
        sz[u] += sz[v];
        ret = max( ret, pii( sz[v], v ) );
    }
    hv[u] = ret.y, en[u] = t;
}

void sack( multiset<int> &s, int u, int p ) {
    if( hv[u] != -1 ) sack( s, hv[u], u );
    multiset<int> t;
    for( int v : g[u] ) if( v != p && v != hv[u] ) {
        sack( t, v, u );
        while( !s.empty() && !t.empty() && *s.begin() + *t.begin() - 2*dep[u] < d ) {
            if( *s.begin() < *t.begin() ) s.erase( s.begin() );
            else t.erase( t.begin() );
        }
        for( int x : t ) s.emplace( x );
        t.clear();
    }
    t.emplace( dep[u] );
    while( !s.empty() && !t.empty() && *s.begin() + *t.begin() - 2*dep[u] < d ) {
        if( *s.begin() < *t.begin() ) s.erase( s.begin() );
        else t.erase( t.begin() );
    }
    for( int x : t ) s.emplace( x );
    t.clear();
}

int main()
{
    scanf("%d %d",&n,&d);
    for( int i = 1, a ; i < n ; i++ ) {
        scanf("%d",&a);
        g[a].emplace_back( i ), g[i].emplace_back( a );
    }
    dfs( 0, 0 );
    sack( s, 0, 0 );
    printf("%d",s.size());
    return 0;
}