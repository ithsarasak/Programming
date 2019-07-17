#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
long long n, p, va[N];
int main()
{
	scanf("%lld %lld",&n,&p);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%lld",&va[i]);
	}
	int l = 1, r = 1e9;
	while( l < r ) {
		int mid = ( l + r + 1 ) >> 1;
		long long sum  = 0;
		for( int i = 1 ; i <= n ; i++ ) sum += va[i] / ( long long )mid;
		if( sum >= p ) l = mid;
		else r = mid - 1;
	}
	long long sum = 0;
	for( int i = 1 ; i <= n ; i++ ) sum += va[i] / l;
	if( sum == p ) printf("YES\n");
	else printf("NO\n");
	printf("%d",l);
	return 0;
}