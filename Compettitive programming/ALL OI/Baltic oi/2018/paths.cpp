#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int n, m, k, sz[N], c[N], book[40], now;
long long ans, dp[40];
bool chk[N];
vector<int> g[N];

int getsz( int u, int p ) { printf("u : %d\n",u );sz[u] = 1; for( int v : g[u] ) if( !chk[v] && v != p ) sz[u] += getsz( v, u ); return sz[u]; }

int find_cen( int u, int p, int all, pii &ret ) {
    int mx = all - sz[u];
    for( int v : g[u] ) if( v != p && !chk[v] ) 
        mx = max( mx, find_cen( v, u, all, ret ) );
    ret = min( ret, pii( mx, u ) );
    return sz[u];
}

void dfs( int u, int p, int bit, bool fill, int cen ) {
    if( bit & ( 1 << c[u] ) || c[u] == c[cen] ) return ;
    bit |= ( 1<<c[u] );
    //printf("U : %d %d %d %d now %d\n",u,c[u],(1<<c[u]),bit, now);
    if( !fill ) {
        ans++;
        for( int i = 0 ; i < 32 ; i++ ) {
            //printf("%d : %d %d %d\n",i,book[i],dp[i],(i&bit));
            //printf("%d\n",( i&bit ) == 0 );
            if( ( ( i & bit ) == 0 ) && ( book[i] == now ) ){
                //printf("kuay%d %d %d\n",i,book[i],dp[i]);
                ans += dp[i];
            }
        }
    }
    else {
        if( book[bit] != now ) dp[bit] = 1;
        else dp[bit]++;
        book[bit] = now;
    }
    for( int v : g[u] ) if( v != p && !chk[v] ) dfs( v, u, bit, fill, cen );
} 

void centroid( int u ) {
    pii ret( 1e9, -1 );
    printf("%d\n",u);
    getsz( u, u );
    printf("%d\n",u);find_cen( u, u, sz[u], ret );
    u = ret.y, now++;
    printf("u : %d\n",u);
    for( int v : g[u] ) if( !chk[v] ) dfs( v, u, 0, 0, u ), dfs( v, u, 0, 1, u );
    chk[u] = 1;
    printf("ans :%lld\n",ans);
    for( int v : g[u] ) if( !chk[v] ) centroid( v );
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&c[i]);
        c[i]--;
    }
    for( int i = 0, u, v ; i < m ; i++ ) {
        scanf("%d %d",&u,&v);
        g[u].emplace_back( v ), g[v].emplace_back( u );
    }
    centroid( 1 );
    printf("%lld",ans*2);
    return 0;
}