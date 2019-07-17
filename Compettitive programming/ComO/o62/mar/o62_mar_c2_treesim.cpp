#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second
using namespace std;

const int N = 2e5 + 10;
int n, rt1, rt2;
long long va[N], ind[N], base[N], va2[N], ind2[N], inf = 11, ans;
pii dp[N], dp2[N];
map<pii,int> m1;
vector<int> g[N], g2[N];

void dfs( int now, int p ) {
	if( ind[now] == 1 ) va[now] = base[now];
	else va[now] = 0;
	for( int i : g[now] ) if( i != p ) dfs( i, now );
}

void dfs2( int now, int p ) {
	if( ind2[now] == 1 ) va2[now] = base[now];
	else va[now] = 0;
	for( int i : g2[now] ) if( i != p ) dfs2( i, now );
}

void solve1( int now, int p ) {
	// printf("%d %d\n",now,p);
	dp[now].x = va[now];
	if( ind[now] == 1 ) dp[now].y = 1;
	else dp[now].y = 0;
	for( int i : g[now] ) if( i != p ) {
		solve1( i, now );
		dp[now].x += dp[i].x;
		dp[now].y += dp[i].y;
	}
	return ;
}

void solve2( int now, int p ) {
	dp2[now].x = va2[now];
	if( ind2[now] == 1 ) dp2[now].y = 1;
	else dp2[now].y = 0;
	for( int i : g2[now] ) if( i != p ) {
		solve2( i, now );
		dp2[now].x += dp2[i].x;
		dp2[now].y += dp2[i].y;
	}
	return ;
}
int main()
{
	base[0] = 1;
	for( int i = 1 ; i <= 2e5 ; i++ ) base[i] = base[i-1] * inf;
	scanf("%d",&n);
	for( int i = 0, a, b ; i < 2*n - 3 ; i++ ) {
		scanf("%d %d",&a,&b);
		g[a].emplace_back( b ), g[b].emplace_back( a );
		ind[a]++, ind[b]++;
	}
	for( int i = 0, a, b ; i < 2*n - 3 ; i++ ) {
		scanf("%d %d",&a,&b);
		g2[a].emplace_back( b ), g2[b].emplace_back( a );
		ind2[a]++, ind2[b]++;
	}
	// cout << endl << endl;
	for( int i = 1 ; i <= 2*n-2 ; i++ ) if( ind[i] != 1 ) {
		rt1 = i;
		dfs( i, 0 );
		break;
	}
	for( int i = 1 ; i <= 2*n-2 ; i++ ) if( ind2[i] != 1 ) {
		rt2 = i;
		dfs2( i, 0 );
		break;
	}
	solve1( rt1, 0 ), solve2( rt2, 0 );

	// for( int i = 1 ; i <= 2*n-2 ; i++ ) printf("%d : %lld %lld %lld\n",i,va[i],dp[i].x,dp[i].y);
	// printf("\n");
	// for( int i = 1 ; i <= 2*n-2 ; i++ ) printf("%d : %lld %lld %lld\n",i,va2[i],dp2[i].x,dp2[i].y);
	// printf("\n");	
	// printf("%d %d\n",rt1,rt2);
	for( int i = 1 ; i <= 2*n-2 ; i++ ) if( i != rt1 ) {
		// printf("%d\n",rt1);
		long long a = dp[i].x, b = dp[i].y, c = dp[rt1].x - dp[i].x, d = dp[rt1].y - dp[i].y;
		// printf("%d : %lld %lld %lld %lld\n",i,a,b,c,d);
		if( b > d ) swap( a, c ), swap( b, d );
		// printf("swap : %lld %lld %lld %lld\n",a,b,c,d);
		if( b == d ) m1[pii(c,a)] = 1;
		m1[pii( a, c )] = 1;
	}
	// cout << endl;
	for( int i = 1 ; i <= 2*n-2 ; i++ ) if( i != rt2 ) {
		long long a = dp2[i].x, b = dp2[i].y, c = dp2[rt2].x - dp2[i].x, d = dp2[rt2].y - dp2[i].y;
		// printf("%d : %lld %lld %lld %lld\n",i,a,b,c,d);
		if( b > d ) swap( a, c ), swap( b, d );
		// printf("swap : %lld %lld %lld %lld\n",a,b,c,d);
		if( m1[pii( a, c )] == 0 ) {
			// printf("BUGG %lld %lld\n",a,c);
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}