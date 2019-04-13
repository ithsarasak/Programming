#include <bits/stdc++.h>
#define iii tuple<int, int, int>
#define mt make_tuple
using namespace std;

const int N = 3e5+100;
int k, n;
iii song[N];
long long mx, sum, mi;
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 1 ; i <= n ; i++ ) {
		long long a, b;
		scanf("%lld %lld",&a,&b);
		song[i] = mt( a * b, a, b );
	}
	sort( song + 1, song + 1 + n, greater<iii>() );
	mx = get<0>( song[1] );
	sum = get<1>( song[1] );
	mi = get<2>( song[1] );
	for( int i = 2 ; i <= n ; i++ ) {
		long long a, b, c;
		tie( a, b, c ) = song[i];
		// printf("%lld %lld %lld %lld %lld %lld\n",mx,sum,mi,a,b,c);
		if( i > k ) break;
		if( ( sum + b ) * ( min( mi, c ) ) < mx ) break;
		mi = min( mi, c );
		sum += b;
		mx = sum * mi;
	}
	printf("%lld",mx);
	return 0;
}