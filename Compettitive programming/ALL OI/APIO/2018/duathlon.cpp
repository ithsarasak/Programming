#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, m, pre[N], low[N], subsz[N], compsz[N];
long long ans;
bool art[N];

vector<vector<int>> g(N), ccs;
void tarjan( int u, int p ) {
    static int ti = 0;
    static stack<int> s;
    int chk = 0;
    low[u] = pre[u] = ++ti;
    s.emplace( u );
    for( int v : g[u] ) if( !pre[v] ) {
        tarjan( v, u );
        chk++;
        low[u] = min( low[u], low[v] );
        if( !p && chk > 1 || p && low[v] >= pre[u] ) art[u] = true;
        if( low[v] >= pre[u] ) {
            ccs.emplace_back( vector<int>() );
            ccs.back().emplace_back( u );
            while( ccs.back().back() != v ) ccs.back().emplace_back( s.top() ), s.pop();
        }
    }
    else if( v != p ) low[u] = min( low[u], pre[v] );
}

void genbcc() {
    g.clear(), g.resize( n+1 );
    for( vector<int> &cc : ccs ) {
        g.emplace_back( vector<int>() );
        compsz[(int)g.size()-1] = cc.size();
        for( int u : cc ) g[u].emplace_back( ( int )g.size() - 1 ), g[(int)g.size() - 1].emplace_back( u );
    }
}

int getsz( int u, int p ) {
    if( u <= n ) subsz[u] = 1;
    for( int v : g[u] ) if( v != p ) 
        subsz[u] += getsz( v, u );
    return subsz[u];
}

void bad( int u, int p, int all ) {
    //printf("%d %d\n",u,p);
    if( u <= n ) for( int v : g[u] ) {
        if( v != p ) ans -= 1ll * ( compsz[v] - 1 ) * ( all - subsz[v] ) * ( all - subsz[v] - 1 );
        else ans -= 1ll * ( compsz[v] - 1 ) * subsz[u] * ( subsz[u] - 1 );
    }
    for( int v : g[u] ) if( v != p ) bad( v, u, all );
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0, a, b ; i < m ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    for( int i = 1 ; i <= n ; i++ ) if( !pre[i] ) tarjan( i, 0 );
    genbcc();
    for( int i = 1 ; i <= n ; i++ ) if( !subsz[i] ) {
        getsz( i, 0 );
        //printf("%d\n",subsz[i]);
        ans += 1ll * subsz[i] * ( subsz[i] - 1 ) * ( subsz[i] - 2 );
        bad( i, 0, subsz[i] );
    }
    printf("%lld",ans);
    return 0;
}