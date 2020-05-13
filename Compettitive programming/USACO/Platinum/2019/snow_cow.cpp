#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int n, q, st[N], en[N], sz[N], ti;
set<pii> col[N];
vector<int> g[N];
vector<long long> t1, t2;

void update( vector<long long> &t, int pos, long long va ) { for( int i = pos ; i < N ; i += i & -i ) t[i] += va; }

long long query( vector<long long> &t, int pos ) {
    long long ret = 0;
    for( int i = pos ; i > 0 ; i -= i & -i ) ret += t[i];
    return ret;
}

int dfs( int u, int p ) {
    st[u] = ++ti, sz[u] = 1;
    for( int v : g[u] ) if( v != p ) sz[u] += dfs( v, u );
    en[u] = ti;
    return sz[u];
}

int main()
{
    freopen( "snowcow.in", "r", stdin );
    freopen( "snowcow.out", "w", stdout );
    t1.resize( N ), t2.resize( N );
    scanf("%d %d",&n,&q);
    for( int i = 1, a ,b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    dfs( 1, 0 );
    for( int z = 0, a, x, c ; z < q ; z++ ) {
        scanf("%d %d",&a,&x);
        if( a == 1 ) {
            scanf("%d",&c);
            auto it = col[c].upper_bound( pii( st[x], 0 ) );
            if( it != col[c].begin() && en[(*prev(it)).y] >= en[x] ) continue ;
            while( it != col[c].end() && en[(*it).y] <= en[x] ) {
                update( t1, st[(*it).y], -1 ), update( t1, en[(*it).y]+1, 1 );
                update( t2, st[(*it).y], -1LL*sz[(*it).y] );
                col[c].erase( it++ );
            }
            col[c].insert( pii( st[x], x ) );
            update( t1, st[x], 1LL ), update( t1, en[x]+1, -1LL ), update( t2, st[x], 1LL * sz[x] );
        }
        else printf("%lld\n",query( t1, st[x] ) * sz[x] + query( t2, en[x] ) - query( t2, st[x] ) );
    }
    return 0;
}