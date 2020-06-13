#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 3e5 + 10;
long long high[N], slope[N], par[N];
int sz[N], hv[N], n, m;
priority_queue<long long> F;
vector<pii> g[N];


void dfs( int u, int p ) {
    pii hh( 0, -1 );
    sz[u] = 1;
    for( pii v : g[u] ) if( v.x != p ) {
        dfs( v.x, u );
        par[v.x] = v.y;
        sz[u] += sz[v.x];
        hh = max( hh, pii( sz[v.x], v.x ) );
    }
    hv[u] = hh.y;
    return ;
}

void sack( int u, int p, priority_queue<long long> &Q ) { 
    //printf("U : %d P : %d\n",u,p);
    if( sz[u] == 1 ) {
        high[u] = par[u], slope[u] = -1LL;
        Q.emplace( par[u] ), Q.emplace( par[u] );
        return ;
    }
    sack( hv[u], u, Q );
    high[u] = high[hv[u]], slope[u] = slope[hv[u]];
    priority_queue<long long> S;
    for( pii v : g[u] ) if( v.x != p && v.x != hv[u] ) {
        sack( v.x, u, S );
        high[u] += high[v.x], slope[u] += slope[v.x];
        while( !S.empty() ) {
            Q.emplace( S.top() );
            S.pop();
        }
    }
    if( !p ) {
        //printf("%d %d\n",u,p);
        vector<long long> v;
        while( !Q.empty() ) {
            v.emplace_back( Q.top() );
            Q.pop();
        }
        reverse( v.begin(), v.end() );
        long long pv = 0, no = 0;
        for( int i = 0 ; slope[u] < 0 ; slope[u]++, i++ ) {
            no += ( v[i] - pv ) * slope[u];
            pv = v[i];
        }
        printf("%lld\n",high[u]+no);
    }
    else {
        long long a, b;

        while( slope[u] + (int)Q.size() >= 0 ) {
            swap( a, b );
            a = Q.top();
            //printf("%lld %lld %d\n",a,b,(int)Q.size()); 
            Q.pop();
        }
        Q.emplace( a + par[u] ), Q.emplace( b + par[u] );
        /*printf("%d %d\nTEMP : ",u,p);
        priority_queue<long long> temp = Q;
        while( !temp.empty() ) {
            printf("%d ",temp.top());
            temp.pop();
        }
        printf("\n");*/
        high[u] += par[u];
    }
}

int main()
{
    scanf("%d %d",&n,&m); n += m;
    for( int i = 2, a, b ; i <= n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[i].emplace_back( pii( a, b ) );
        g[a].emplace_back( pii( i, b ) );
    }
    dfs( 1, 0 );
    sack( 1, 0, F );
    return 0;
}