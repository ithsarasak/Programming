#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+100;
long long n, prop[N], dpl[N], dpr[N], mx = -1e9, mi = 1e9, ans;
int main()
{
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&prop[i]);
	for( int i = 1 ; i <= n ; i++ ) {
		mx = max( mx, prop[i] ), mi = min( mi, prop[i] );
		dpl[i] = mx - mi;
	}
	mx = -1e9, mi = 1e9;
	for( int i = n ; i >= 1 ; i-- ) {
		mx = max( mx, prop[i] ), mi = min( mi, prop[i] );
		dpr[i] = mx - mi;
	}
	for( int i = 1 ; i < n ; i++ ) {
		ans = max( ans, dpl[i] + dpr[i+1] );
	}
	printf("%lld",ans);
	return 0;
}