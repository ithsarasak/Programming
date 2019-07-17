#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+100;
int n, sz[N], book[N], k, a[N], chk[N], nub;
long long ans[N], dp[N];
vector<int> g[N];

int getsz( int now, int p ) {
	sz[now] = 1;
	for( int i : g[now] ) if( i != p && !chk[i] ) sz[now] += getsz( i, now );
	return sz[now];
}

int find_cen( int now, int p, int all, pii &ret ) {
	int mx = all - sz[now];
	for( int i : g[now] ) if( i != p && !chk[i] ) mx = max( mx, find_cen( i, now, all, ret ) );
	ret = min( ret, pii( mx, now ) );
	return sz[now];
}

void dfs( int now, int p, int cnt, bool fill ) {
	if( !fill ) {
		for( int i = 1 ; i <= k ; i++ ) if( a[i] == cnt ) {
			ans[i]++;
		}
		for( int i = 1 ; i <= k ; i++ ) if( cnt < a[i] && book[a[i]-cnt] == nub ) {
			ans[i] += dp[a[i]-cnt];
		}
	}
	else {
		if( book[cnt] < nub ) dp[cnt] = 1;
		else dp[cnt]++;
		book[cnt] = nub;
	}
	for( int i : g[now] ) if( !chk[i] && i != p ) dfs( i, now, cnt+1, fill );
}

int solve( int now ) {
	getsz( now, now );
	pii ret( sz[now]+1, -1 );
	find_cen( now, now, sz[now], ret );
	now = ret.y;
	nub++;
	// printf("%d\n",now);
	for( int i : g[now] ) if( !chk[i] ) {
		dfs( i, now, 1, 0 );
		dfs( i, now, 1, 1 );
	}
	chk[now] = 1;
	for( int i : g[now] ) if( !chk[i] ) solve( i );
}
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 1 ; i <= k ; i++ ) scanf("%d",&a[i]);
	for( int i = 1, a, b ; i < n ; i++ ) {
		scanf("%d %d",&a,&b);
		g[a].emplace_back( b ), g[b].emplace_back( a );
	}
	solve( 1 );
	for( int i = 1 ; i <= k ; i++ ) {
		printf("%lld\n",ans[i]*2);
	}
	return 0;
}
