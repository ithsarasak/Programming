#include <bits/stdc++.h>

using namespace std;
long long n, n2;
vector<long long> prime;
int mark[100010];
void genprime()
{
	for( int i = 2 ; i <= 100000 ; i++ ){
		if( !mark[i] ){
			mark[i] = 1;
			prime.push_back( i );
			for( int j = i + i ; j <= 100000 ; j += i )mark[j] = 1;
		}
	}
}
int main()
{
	genprime();
	scanf("%lld",&n);
	n2 = n;
	for( int i = 0 ; i < prime.size() ; i++ ){
		if( n % prime[i] == 0 ){
			n -= prime[i];
			break;
		}
	}
	if( n == n2 )printf("1");
	else printf("%lld",n/2+1);
	return 0;
}