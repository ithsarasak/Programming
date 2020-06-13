#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define iii tuple<int, int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

vector<pii> g[N];
vector<iii> edge;
int n, m, q, dep[N], par[N], lca[N][19];
long long d[N][19], mod = 33331;

long long modpow( long long base, int pow ) {
    long long ret = 1;
    for( ; pow ; pow >>= 1 ) {
        if( pow & 1 ) ret = ( ret * base ) % mod;
        base = ( base * base ) % mod;
    }
    return ret;
}

int findroot( int now ) { return now == par[now] ? now : par[now] = findroot( par[now] ); }

void init_lca( int u, int p, long long dis ) {
    lca[u][0] = p, d[u][0] = dis, dep[u] = dep[p] + 1;
    for( int i = 1 ; i <= 17 ; i++ ) {
        lca[u][i] = lca[lca[u][i-1]][i-1];
        d[u][i] = ( d[u][i-1] + d[lca[u][i-1]][i-1] ) % mod;
    }
    for( pii v : g[u] ) if( v.x != p ) init_lca( v.x, u, v.y );
}

long long findlca( int a, int b ) {
    long long ret = 0;
    if( dep[a] < dep[b] ) swap( a, b );
    for( int i = 17 ; i >= 0 ; i-- ) if( dep[lca[a][i]] >= dep[b] ) {
        ret = ( ret + d[a][i] ) % mod, a = lca[a][i];
    }
    if( a == b ) return ret;
    for( int i = 17 ; i >= 0 ; i-- ) if( lca[a][i] != lca[b][i] ) {
        ret = ( ret + d[a][i] + d[b][i] ) % mod;
        a = lca[a][i], b = lca[b][i];
    }
    return ( ret + d[a][0] + d[b][0] ) % mod;
}

int main()
{
    scanf("%d %d %d",&n,&m,&q);
    for( int i = 1, a, b, c ; i <= m ; i++ ) {
        scanf("%d %d %d",&a,&b,&c);
        edge.emplace_back( iii( a, b, c ) );
    }
    sort( edge.begin(), edge.end(), [&]( const iii &a, const iii &b ) {
        return get<2>(a) < get<2>(b);
    });
    for( int i = 1 ; i <= n ; i++ ) par[i] = i;
    for( iii i : edge ) {
        int a, b, c, pa, pb;
        tie( a, b, c ) = i;
        //printf("%d %d %d\n",a,b,c);
        pa = findroot( a ), pb = findroot( b );
        if( pa != pb ) {
            par[pa] = pb;
            long long we = modpow( 2, c );
            g[a].emplace_back( pii( b, we ) );
            g[b].emplace_back( pii( a, we ) );
        }
    }
    init_lca( 1, 0, 0 );
    while( q-- ) {
        int u, v;
        scanf("%d %d",&u,&v);
        printf("%lld\n",findlca( u, v ));
    }
    return 0;
}