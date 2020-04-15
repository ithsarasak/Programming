#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int par[N], rot[N], sz[N], hv[N], c[N], pos[N], n;
long long t[N];
deque<pii> col[N];
vector<pii> qq;
vector<int> g[N];

int dfs( int u, int p ) {
    sz[u] = 1, hv[u] = -1, par[u] = p;
    int mx = -1;
    for( int v : g[u] ) if( v != p ) {
        int now = dfs( v, u );
        sz[u] += now;
        if( now > mx ) mx = now, hv[u] = v;
    }
    return sz[u];
}

void hld() {
    for( int i = 1, idx = 0; i <= n ; i++ ) if( hv[par[i]] != i ) 
        for( int j = i ; j != -1 ; j = hv[j] ) 
            rot[j] = i, pos[j] = ++idx;
}

long long query( int u ) {
    long long ret = 0;
    vector<int> coord;
    vector<pii> ar;
    //printf("U:%d\n",u);
    while( u ) {
        //printf("%d\n",u);
        vector<pii> all;
        int sz = pos[u] - pos[rot[u]] + 1;
        for( pii i : col[rot[u]] ) {
            if( i.y >= sz ) {
                all.emplace_back( i.x, sz );
                break;
            }
            else all.emplace_back( i ), sz -= i.y;
        }
        reverse( all.begin(), all.end() );
        for( pii i : all ) ar.emplace_back( i ), coord.emplace_back( i.x );
        u = par[rot[u]];
    }
    sort( coord.begin(), coord.end() );
    coord.resize( unique( coord.begin(), coord.end() ) - coord.begin() );
    vector<long long> t( coord.size() + 10, 0 );
    for( pii i : ar ) {
        //printf("%d %d\n",i.x,i.y);
        long long sum = 0;
        int x = lower_bound( coord.begin(), coord.end(), i.x ) - coord.begin() + 1;
        for( int j = x-1 ; j > 0 ; j -= j & -j ) sum += t[j];
        ret += sum * i.y; 
        for( int j = x ; j < ( int )coord.size() + 10 ; j +=  j & -j ) t[j] += i.y;
    }
    return ret;
}

void update( int u, int c ) {
    while( u ) {
        int sz = pos[u] - pos[rot[u]] + 1;
        while( !col[rot[u]].empty() ) {
            if( col[rot[u]].front().y <= sz ) sz -= col[rot[u]].front().y, col[rot[u]].pop_front();
            else {
                col[rot[u]].front().y -= sz; 
                break;
            }
        }
        col[rot[u]].emplace_front( c, pos[u] - pos[rot[u]] + 1 );
        u = par[rot[u]];
    }
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&c[i]);
    for( int i = 1, s, t ; i < n ; i++ ) {
        scanf("%d %d",&s,&t);
        g[s].emplace_back( t ), g[t].emplace_back( s );
        qq.emplace_back( pii( s, t ) );
    }
    dfs( 1, 0 ), hld();
    col[1].emplace_back( pii( c[1], 1 ) );
    for( pii i : qq ) {
        printf("%lld\n",query( i.x ) );
        update( i.y, c[i.y] );
    }
    return 0;
}