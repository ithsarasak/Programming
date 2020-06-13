#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

struct ee {
    int u, v, d;
    ee( int u, int v, int d ) : u( u ), v( v ), d( d ) {};
    friend bool operator<( const ee &a, const ee &b ) {
        return a.d < b.d;
    }
};

int n, m, q, par[N], x[N*10], y[N*10], l[N*10], r[N*10];
vector<ee> edge;
vector<int> ask[10*N];

int findroot( int now ) { return par[now] == now ? now : par[now] = findroot( par[now] ); }

void clear() {
    for( int i = 0 ; i < m ; i++ ) ask[i].clear();
    for( int i = 0 ; i <= n ; i++ ) par[i] = i;
}

void apply( int i ) {
    int f = edge[i].u, t = edge[i].v;
    f = findroot( f ), t = findroot( t );
    if( f != t ) par[f] = t;
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1, a, b, c ; i <= m ; i++ ) {
        scanf("%d %d %d",&a,&b,&c);
        edge.emplace_back(ee( a, b, c));
    }
    sort( edge.begin(), edge.end() );
    scanf("%d",&q);
    for( int i = 1 ; i <= q ; i++ ) {
        scanf("%d %d",&x[i],&y[i]);
        l[i] = 0, r[i] = m-1;
    }
    bool check = true;
    for( ; check ; ) {
        clear();
        check = false;
        for( int i = 1 ; i <= q ; i++ ) if( l[i] != r[i] ) {
            check = true;
            //printf("%d %d\n",)
            ask[(l[i]+r[i])>>1].emplace_back( i );
        }
        for( int i = 0 ; i < (int)edge.size() ; i++ ) {
            apply( i );
            for( int now : ask[i] ) {
                if( findroot( x[now] ) == findroot( y[now] ) ) r[now] = i;
                else l[now] = i+1;
            }
        }
    }
    for( int i = 1 ; i <= q ; i++ ) printf("%d\n",edge[l[i]].d);
    return 0;
}