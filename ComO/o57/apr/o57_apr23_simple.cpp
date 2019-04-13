#include <bits/stdc++.h>
#define long long long

using namespace std;

const int mod = 1e9+7;
long fac[60], x, k, ans;

long modpower( long times, long num ) {
	long ret = 1;
	for( ; times ; times >>= 1 ) {
		if( times & 1 )ret = ( ret * num ) % mod;
		num = ( num * num ) % mod;
	}
	return ret;
}

long ncr( int n, int r ) {
	long ret = ( fac[n] * modpower( mod-2, fac[r] ) ) % mod;
	return ( ret * modpower( mod - 2, fac[n-r] ) ) % mod;
}

long b( long m, long x ) {
	long ret = 0;
	for( int n = 0 ; n <= m ; n++ ) {
		long sum = 0;
		for( int k = 0 ; k <= n ; k++ ) {
			long now = ( k % 2 ) ? mod -1 : 1;
			now = ( now * ncr( n, k ) ) % mod;
			now = ( now * modpower( m, x + k ) ) % mod;
			sum = ( sum + now ) % mod;
		}
		sum = ( sum * modpower( mod - 2, n + 1 ) ) % mod;
		ret = ( ret + sum ) % mod;
	}
	return ret;
}

int main()
{
	fac[0] = 1;
	for( int i = 1 ; i <= 51 ; i++ )fac[i] = ( fac[i-1] * i ) % mod;
	scanf("%lld %lld",&x,&k);
	for( int p = 1 ; p <= k ; p++ ) {
		long now = ( b( p + 1, x + 1 ) - b( p + 1, 0 ) + mod ) % mod;	
		now = ( now * modpower( mod - 2, p + 1 ) ) % mod;
		now = ( now * p ) % mod;
		ans = ( ans + now ) % mod;
	}
	printf("%lld",ans);
	return 0;
}