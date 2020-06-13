#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, sz[N];
long long ans, dp[N], fac[N], inv[N], mod = 1e9 + 7;
vector<int> g[N];

long long mul( long long a, long long b ) { return ( a*b ) % mod; }

long long modpow( long long base, int pow ) {
    long long ret = 1;
    for( ; pow ; pow >>= 1 ) {
        if( pow & 1 ) ret = mul( ret, base );
        base = mul( base, base ); 
    }
    return ret;
}

void pre( int u, int p ) {
    sz[u] = 1, dp[u] = 1;
    for( int v : g[u] ) if( v != p ) {
        pre( v, u );
        sz[u] += sz[v];
        dp[u] = mul( dp[u], mul( dp[v], inv[sz[v]] ) ); 
    }
    dp[u] = mul( dp[u], fac[sz[u]-1] );
    //printf("%d : %lld\n",u,dp[u]);
}

void dfs( int u, int p, long long rest ) {
    //printf("%lld ",mul( dp[u], mul( fac[n-1], rest ) ) );
    long long x = mul( dp[u], mul( fac[n-1], mul( rest, mul( inv[n-sz[u]], inv[sz[u]-1] ) ) ) );
    //printf("%d %lld %lld\n",u,rest,x);
    ans = ( ans + x ) % mod;
    //printf("ANS : %lld %lld\n",ans,dp[u]);
    for( int v : g[u] ) if( v != p ) {
        long long nxt = mul( dp[u], mul( inv[sz[u]-1], mul( fac[sz[v]], modpow( dp[v], mod-2 ) ) ) );
        nxt = mul( nxt, mul( rest, mul( fac[n-sz[v]-1], inv[n-sz[u]] ) ) );
        dfs( v, u, nxt );
    }
}

int main()
{
    fac[0] = inv[0] = 1;
    for( int i = 1 ; i < N ; i++ ) fac[i] = mul( fac[i-1], i ), inv[i] = modpow( fac[i], mod-2 );
    scanf("%d",&n);
    //for( int i = 1 ; i <= n ; i++ ) printf("%lld ",inv[i]);
    for( int i = 1, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    pre( 0, 0 ), dfs( 0, 0, 1 );
    printf("%lld",ans);
    return 0;
}