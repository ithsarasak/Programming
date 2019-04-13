#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+100;
struct car {
	long long st, sp;
	bool operator<( const car &k )const{
		if( st == k.st ) return sp > k.sp;
		else return st < k.st;
	}
}car[N];
long long n, t, mx, ans;
int main()
{
	scanf("%lld %lld",&n,&t);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%lld %lld",&car[i].st,&car[i].sp);
	}
	sort( car + 1, car + 1 + n );
	for( int i = 1 ; i <= n ; i++ ) {
		if( car[i].st + car[i].sp*t > mx ) {
			ans++;
			mx = max( mx, car[i].st + car[i].sp*t );
		}
	}
	printf("%d",ans);
	return 0;
}