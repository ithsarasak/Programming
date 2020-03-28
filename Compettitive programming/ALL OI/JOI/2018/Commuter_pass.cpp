#include <bits/stdc++.h>
#define pli pair<long long, int>
#define x first
#define y second 

using namespace std;

const int N = 1e5 + 10;

vector<pli> g[N];
int n, m, u, v, s, t;
long long ds[N], dt[N], du[N], dv[N];
priority_queue<pli, vector<pli>, greater<pli> > q;

void shortest( int st, long long d[] ) {
    fill( d, d+N, 1e18 );
    d[st] = 0;
    q.emplace( pli( 0, st ) );
    while( !q.empty() ) {
        long long di = q.top().x; int u = q.top().y; q.pop();
        //cout << st << " " << u << " " << di << endl;
        for( pli v : g[u] ) if( d[v.x] > di + v.y ) q.emplace( pli( d[v.x] = di + v.y, v.x ) );
    }
}

long long solve( int a, int b, long long da[], long long db[] ) {
    long long dp[N], len = da[b], ret = 1e18;
    bool chk[N]; 
    memset( chk, 0, sizeof chk );
    for( int i = 1 ; i <= n ; i++ ) dp[i] = du[i];
    //for( int i = 1 ; i <= n ; i++ ) cout << dp[i] << endl;
    q.emplace( pli( 0, a ) ), chk[a] = true;
    while( !q.empty() ) {
        pli now = q.top(); q.pop();
        if( now.x != da[now.y] ) continue;
        long long di;
        int u; 
        tie( di, u ) = now;
        for( pli v : g[u] ) if( di + v.y + db[v.x] == len ) {
            dp[v.x] = min( dp[v.x], dp[u] );
            if( !chk[v.x] ) chk[v.x] = true, q.emplace( pli( di + v.y, v.x ) );
        }
    }
    
    for( int i = 1 ; i <= n ; i++ ) if( da[i] + db[i] == len ) ret = min( ret, dp[i] + dv[i] );
    return ret;
}

int main()
{
    scanf("%d %d %d %d %d %d",&n,&m,&s,&t,&u,&v);
    for( int i = 1, a, b ; i <= m ; i++ ) {
        long long c;
        scanf("%d %d %lld",&a,&b,&c);
        g[a].emplace_back( pli( b, c ) ), g[b].emplace_back( pli( a, c ) );
    }
    shortest( s, ds ), shortest( t, dt ), shortest( u, du ), shortest( v, dv );
    printf("%lld",min( du[v], min( solve( s, t, ds, dt ), solve( t, s, dt, ds ) ) ) );
    return 0;
}