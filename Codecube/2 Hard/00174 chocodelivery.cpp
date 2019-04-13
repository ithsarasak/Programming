#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

const int N = 1e3+100;
const long long mod = 1e9 + 7;
pii point[N]; 
int n, q;
long long dp[N], fac[200*N], ans, inv[200*N];

long long modpower( long long base, long long power ) {
	long long ret = 1;
	for( ; power ; power >>= 1 ) {
		if( power & 1 )ret = ( ret * base ) % mod;
		base = ( base * base ) % mod;
	}
	return ret;
}

long long cal( long long x, long long y ) {
	long long ret = fac[x+y];
	// printf("%lld %lld %lld\n",fac[x+y],fac[x],fac[y]);
	ret = ( ret * inv[x] ) % mod;
	ret = ( ret * inv[y] ) % mod;
	return ret;
}

int main()
{
	fac[0] = 1LL;
	inv[0] = 1LL;
	for( int i = 1 ; i <= 2e5 ; i++ ) fac[i] = ( fac[i-1] * ( long long )i ) % mod;
	for( int i = 1 ; i <= 2e5 ; i++ ) inv[i] = modpower( fac[i], mod-2 ) % mod;
	scanf("%d %d",&n,&q);
	for( int i = 1 ; i <= n ; i++ ) {
		long long a, b;
		scanf("%lld %lld",&a,&b);
		point[i] = pii( a, b );
	}
	sort( point + 1, point + 1 + n );
	for( int i = 1 ; i <= n ; i++ ) {
		dp[i] = cal( point[i].x - 1, point[i].y - 1 ) % mod;
		// printf("DP%lld %lld %lld\n",dp[i],point[i].x-1,point[i].y-1);
		for( int j = 1 ; j < i ; j++ ) {
			if( point[j].x <= point[i].x && point[j].y <= point[i].y ) {
				// printf("%lld %lld %lld\n",point[i].x-point[j].x,point[i].y-point[j].y,cal( point[i].x - point[j].x, point[i].y - point[j].y ));
				dp[i] = ( dp[i] - ( ( dp[j] * cal( point[i].x - point[j].x, point[i].y - point[j].y ) ) % mod ) + mod ) % mod;
			}
		}
	}
	// for( int i = 1 ; i <= n ; i++ ) printf("%lld ",dp[i]);
	// printf("\n");
	while( q-- ) {
		long long x, y;
		scanf("%lld %lld",&x,&y);
		long long ans = cal( x-1, y-1 );
		for( int i = 1 ; i <= n ; i++ ) {
			if( point[i].x <= x && point[i].y <= y )
				ans = ( ans - ( ( dp[i] * cal( x - point[i].x, y - point[i].y ) ) % mod ) + mod ) % mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}