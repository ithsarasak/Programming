#include <bits/stdc++.h>

using namespace std;
int n;
int main() 
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		long long k, x;
		scanf("%lld %lld",&k,&x);
		printf("%lld\n",(k-1)*9+x);
	}
	return 0;
}