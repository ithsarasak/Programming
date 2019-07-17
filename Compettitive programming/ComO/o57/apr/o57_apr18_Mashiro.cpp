#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100;
vector<long long> prime, cnt1, cnt2;
long long n, mark[N];
long long ans = 1, m;

void genprime() {
	for( int i = 2 ; i <= N - 1 ; i++ ) {
		if( mark[i] )continue;
		prime.emplace_back( i );
		for( int j = i ; j <= N ; j += i )mark[j] = 1;
	}
}

long long cal( long long p, long long num ) {
	long long mp = p, sum = 0;
	while( mp <= num ) {
		sum += num / mp;
		mp *= p;
	}
	return sum;
}

long long mul( long long times, long long p ) {
	long long ret = 1;
	for( ; times; times >>= 1) {
		if(times & 1) ret = (ret * p) % m;
		p = (p * p) % m;
	}
	return ret;
}

int main()
{
	genprime();
//	for( int i = 0 ; i < 20 ; i++ )printf("%lld ",prime[i] );
//	printf("\n");
	scanf("%lld %lld",&n,&m);
	for( int i = 0 ; i < prime.size() ; i++ ) {
		cnt1.emplace_back( cal( prime[i], 2*n ) );
	}
	for( int i = 0 ; i < prime.size() ; i++ ) {
		cnt2.emplace_back( cal( prime[i], n ) );
	}
//	for( int i = 0 ; i < 20 ; i++ )printf("%lld ",cnt1[i] );
//	printf("\n");
//	for( int i = 0 ; i < 20 ; i++ )printf("%lld ",cnt2[i] );
	for( int i = 0 ; i < prime.size() ; i++ ) {
		ans *= mul( cnt1[i] - 2*cnt2[i] , prime[i] );
		ans %= m;
	}
	printf("%lld",(ans*ans)%m);
	return 0;
}
