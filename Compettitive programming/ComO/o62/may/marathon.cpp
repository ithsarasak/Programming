#include <bits/stdc++.h>
#define pii pair<int, int>
#define t first
#define d second

using namespace std;

const int N = 5e4 + 10;
struct qq {
    int t, d;
    bool operator<( const qq &k ) const {
        return d > k.d;
    }
}t;
priority_queue<qq> q;
int n, s, tt, m, qe, dis[N], mic[20][N], lv[N], sum[N];
vector<pii> g[N];

int shortestpath( int s, int to ) {
    q.push({ s, 0 });
    memset( dis, 127, sizeof dis );
    dis[s] = 0;
    while( !q.empty() ) {
        t = q.top(); q.pop();
        //cout << "now " << t.t << " " << t.d << endl;
        for( pii i : g[t.t] ) {
            //cout << i.t << " " << i.d << endl;
            if( dis[i.t] > t.d + i.d ) {
                dis[i.t] = t.d + i.d;
                //cout << dis[i.t] << endl;
                q.push({ i.t, t.d + i.d });
            }
        }
    }
    return dis[to];
}

int lca( int a, int b ) {
    if( lv[a] < lv[b] ) swap( a, b );
    for( int i = 16 ; i >= 0 ; i-- ) if( lv[mic[i][a]] >= lv[b] ) a = mic[i][a];
    if( a == b ) return a;
    for( int i = 16 ; i >= 0 ; i-- ) if( mic[i][a] != mic[i][b] ) a = mic[i][a], b = mic[i][b];
    return mic[0][a];
}

void dfs( int now, int p, int d ) {
    sum[now] = d, lv[now] = lv[p] + 1, mic[0][now] = p;
    for( pii i : g[now] ) if( i.t != p ) dfs( i.t, now, d + i.d );
    return ;
}

int main()
{
    scanf("%d %d %d %d %d",&n,&s,&tt,&m,&qe);
    for( int i = 0, f, t, d ; i < m ; i++ ) {
        scanf("%d %d %d",&f,&t,&d);
        g[t].emplace_back( pii( f, d ) ), g[f].emplace_back( pii( t, d ) );
    }
    for( int i = 1, a ; i <= s + tt ; i++ ) scanf("%d",&a);
    if( m == n - 1 ) {
        dfs( 1, 0, 0 );
        for( int i = 1 ; i <= 16 ; i++ ) for( int j = 1 ; j <= n ; j++ )
            mic[i][j] = mic[i-1][mic[i-1][j]];
    }
    while( qe-- ) {
        int a, b;
        scanf("%d %d",&a,&b);
        if( m == n - 1 ) {
            int x = lca( a, b );
            printf("%d\n",sum[a] + sum[b] - 2 * sum[x] );
        }
        else printf("%d\n",shortestpath( a, b ) );
    }
    return 0;
}