#include <bits/stdc++.h>
#define pii pair<int, long long>
#define t first
#define d second

using namespace std;

const int N = 1e5 + 10;
const long long inf= 1e18 + 10;
int n, m, a, b, c, d, mark[N];
struct qq{
    int t;
    long long d;
    bool operator<( const qq &k ) const {
        return d > k.d;
    }
}t;
priority_queue<qq> q;
vector<pii> g[N];
long long dis[N], dis2[N], dis3[N];
int main()
{
    memset( dis, 127, sizeof dis ), memset( dis2, 127, sizeof dis2 );
    fill( dis3, dis3 + N, inf );
    scanf("%d %d",&n,&m);
    for( int i = 1, u, v ; i <= m ; i++ ) {
        long long w;
        scanf("%d %d %lld",&u,&v,&w);
        g[u].emplace_back( pii( v, w ) ), g[v].emplace_back( pii( u, w ) );
    }
    scanf("%d %d %d %d",&a,&b,&c,&d);
    dis[a] = 0, dis2[b] = 0, dis3[c] = 0;
    q.push({ a, 0 });
    while( !q.empty() ) {
        t = q.top(); q.pop();
        for( pii i : g[t.t] ) if( dis[i.t] > t.d + i.d ) {
            dis[i.t] = t.d + i.d;
            q.push({ i.t, t.d + i.d });
        }
    }
    q.push({ b, 0 });
    while( !q.empty() ) {
        t = q.top(); q.pop();
        for( pii i : g[t.t] ) if( dis2[i.t] > t.d + i.d ) {
            dis2[i.t] = t.d + i.d;
            q.push({ i.t, t.d + i.d });
        }
    }
    for( int i = 1 ; i <= n ; i++ ) if( dis[i] + dis2[i] == dis[b] ) mark[i] = 1;
    q.push({ c, 0 });
    while( !q.empty() ) {
        t = q.top(); q.pop();
        for( pii i : g[t.t] ) if( dis3[i.t] > t.d + i.d && !mark[i.t] ) {
            dis3[i.t] = t.d + i.d;
            q.push({ i.t, t.d + i.d });
        }
    }
    printf("%lld",dis3[d] == inf ? -1 : dis3[d]);
    return 0;
}