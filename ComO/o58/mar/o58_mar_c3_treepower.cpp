#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int mod = 9907;
const int N = 1e5+100;
int n, sz[N], x[N], y[N], z[N], l[N];
int ans, chk[N], sum1[N], sum2[N], sum, sumpow;
vector<int> g[N];

int modpow( int base, int power) {
	int ret = 1;
	for( ; power; power >>= 1) {
		if(power & 1) ret = (ret * base) % mod;
		base = (base * base) % mod;
	}
	return ret;
}

int getsz( int u, int p ) {
	sz[u] = 1;
	for( int i : g[u] ) if( i != p && !chk[i] ) sz[u] += getsz( i, u );
	return sz[u];
}

int find_cen( int u, int p, int all, pii &ret ) {
	int mx = all - sz[u];
	for( int i : g[u] ) if( i != p && !chk[i] ) mx = max( mx, find_cen( i, u, all, ret ) );
	ret = min( ret, pii( mx, u ) );
	return sz[u];
}

void dfs( int u, int p, int cen, int len ) {
	if( len == 2 ) {
		sum1[cen] = ( sum1[cen] + x[u] ) % mod, sum1[u] = ( sum1[u] + x[cen] ) % mod;
		sum2[cen] = ( sum2[cen] + x[u]*x[u] ) % mod, sum2[u] = ( sum2[u] + x[cen]*x[cen] ) % mod;
		return ;
	}
	sum = ( sum + x[u] ) % mod, sumpow = ( sumpow + x[u] * x[u] ) % mod;
	for( int i : g[u] ) if( i != p && !chk[i] ) dfs( i, u, cen, len + 1 );
	return ;
}

void solve( int u ) {
	getsz( u, u );
	pii ret( sz[u]+1, -1 );
	find_cen( u, u, sz[u], ret );
	u = ret.y;
	sum = 0, sumpow = 0;
	for( int i : g[u] ) if( !chk[i] ) {
		dfs( i, u, u, 1 );
	}
	// printf("%d %d %d\n",sum,sumpow,u);
	for( int i : g[u] ) if( !chk[i] ) {
		sum1[i] = ( sum1[i] + sum - x[i] + mod ) % mod;
		sum2[i] = ( sum2[i] + sumpow - x[i]*x[i] + mod ) % mod;
	}
	chk[u] = true;
	for( int i : g[u] )if( !chk[i] ) solve( i );
}

int main()
{
	scanf("%d",&n);
	for( int i = 0, u, v ; i < n - 1 ; i++ ) {
		scanf("%d %d",&u,&v);
		g[u].emplace_back( v ), g[v].emplace_back( u );
	}
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
	}
	solve( 1 );
	for( int i = 1 ; i <= n ; i++ ){
		// printf("%d %d\n",sum1[i],sum2[i] );
		l[i] = ( sum1[i]*sum1[i] - sum2[i] + mod ) % mod;
	}

	for( int i = 1 ; i <= n ; i++ ) {
		// printf("%d\n",l[i] );	
		l[i] = ( l[i] * modpow(2, mod-2) ) % mod;
		l[i] = ( l[i] * y[i] ) % mod;
		l[i] = ( l[i] + z[i] ) % mod;
		ans = ( ans + l[i] ) % mod;
	}	
	printf("%d\n", ans);

	return 0;
}