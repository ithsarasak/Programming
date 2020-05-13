#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
 
using namespace std;
 
const int N = 1e5 + 10;
int n, m, dp[21][2*N], d[2*N], mn[2*N], dep[2*N], k, Q, par[2*N], cnt, mark[N];
vector<int> t[2*N];
vector<pii> g[N], all;
priority_queue<pii> q;
void dijk() {
    //fill( d, d+N, 2e9 );
    while( !q.empty() ) {
        pii temp = q.top(); q.pop();
        //printf("%d\n",temp.y);
        for( pii i : g[temp.y] ) {
            int v = i.x, di = i.y - temp.x;
            if( di < d[v] ) { d[v] = di; q.emplace( -1*di, v ); }
        }
    }
}
 
void dfs( int u = cnt, int p = 0 ) {
    //printf("%d\n",u);
    dp[0][u] = p;
    dep[u] = dep[p] + 1;
    for( int i = 1 ; i < 20 ; i++ ) dp[i][u] = dp[i-1][dp[i-1][u]];
    for( int v : t[u] ) if( v != p ) {
        dfs( v, u );
        if( u > n ) mn[u] = min( mn[u], mn[v] );
    }
}
 
int lca( int a, int b ) {
    if( dep[a] < dep[b] ) swap( a, b );
    for( int i = 19 ; i >= 0 ; i-- ) if( dep[dp[i][a]] >= dep[b] ) a = dp[i][a];
    if( a == b ) return a;
    for( int i = 19 ; i >= 0 ; i-- ) if( dp[i][a] != dp[i][b] ) a = dp[i][a], b = dp[i][b];
    return dp[0][a];
}
 
int findroot( int a ) {
    if( a == par[a] ) return a;
    else return par[a] = findroot( par[a] );
}
 
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0, a, b, c ; i < m ; i++ ) {
        scanf("%d %d %d",&a,&b,&c);
        g[a].emplace_back( pii( b, c ) ), g[b].emplace_back( pii( a, c ) );
    }
    scanf("%d",&k);
    fill( d, d+2*N, 2e9 );
    for( int i = 0, a ; i < k ; i++ ) {
        scanf("%d",&a);
        d[a] = 0;
        q.emplace( 0, a );
    }
    dijk();
    //printf("HEY");
    for( int i = 1 ; i <= n ; i++ ) all.emplace_back( pii( d[i], i ) );
    sort( all.begin(), all.end(), greater<pii>() );
    for( int i = 1 ; i <= 2*n ; i++ ) par[i] = i;
    cnt = n;
    for( pii i : all ) {
        int u = i.y, di = i.x;
        mark[u] = 1;
        for( pii x : g[u] ) {
            int v = x.x;
            if( mark[v] ) {
                int a = findroot( u ), b = findroot( v );
                if( a == b ) continue ;
                par[a] = par[b] = ++cnt;
                t[cnt].emplace_back( a ), t[cnt].emplace_back( b );
            }
        }
    }
    for( int i = 1 ; i <= cnt ; i++ ) mn[i] = d[i];
    dfs();
    scanf("%d",&Q);
    for( int i = 0, a, b ; i < Q ; i++ ) {
        scanf("%d %d",&a,&b);
        int c = lca( a, b );
        printf("%d\n", mn[c] );
    }
    return 0;
}