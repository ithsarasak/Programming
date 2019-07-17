#include <bits/stdc++.h>
#define pii pair<int, int>
#define t first
#define d second 
using namespace std;

const int N = 1e5+100;
int n, sz[N];
bool chk[N];
int ans, cou;
vector<pii> g[N];

int getsz( int now, int p ) {
	sz[now] = 1;
	for( pii i : g[now] ) if( i.t != p && !chk[i.t] ) sz[now] += getsz( i.t, now );
	return sz[now];
}

int find_cen( int now, int p, int all, pii &ret ) {
	int mx = all - sz[now];
	for( pii i : g[now] ) if( i.t != p && !chk[i.t] ) mx = max( mx, find_cen( i.t, now, all, ret ) );
	ret = min( ret, pii( mx, now ) );
	return sz[now];
}

void dfs( int now, int p, int sum ) {
	if( !sum ) cou++;
	if( chk[now] ) return ;
	for( pii i : g[now] ) if( i.t != p ) dfs( i.t, now, sum + i.d );
	return ;
}

void solve( int now ) {
	getsz( now, now );
	pii ret( sz[now] + 1, -1 );
	find_cen( now, now, sz[now], ret );
	now = ret.d;
	int sum = 0;
	for( pii i : g[now] ) if( !chk[i.t] ) {	
		cou = 0;
		dfs( i.t, now, i.d );
		ans += sum * cou;
		sum += cou;
	}
	chk[now] = true;
	for( pii i : g[now] ) if( !chk[i.t] ) solve( i.t );
}

int main()
{
	freopen("yinyang.in", "r", stdin);
	freopen("yinyang.out", "w",stdout);
	scanf("%d",&n);
	for( int i = 0, a, b, c ; i < n - 1 ; i++ ) {
		scanf("%d %d %d",&a,&b,&c);
		g[a].emplace_back( pii( b, c ? 1 : -1  ) ), g[b].emplace_back( pii( a, c ? 1 : -1 ) );
	}
	solve( 1 );
	printf("%d",ans);
	return 0;
}