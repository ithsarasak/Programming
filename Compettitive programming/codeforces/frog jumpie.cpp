#include <bits/stdc++.h>

using namespace std;
int t;
long long a, b, k;
int main()
{
	scanf("%d",&t);
	while( t-- ){
		scanf("%lld %lld %lld",&a,&b,&k);
		printf("%lld\n",(k+1)/2*a - (k/2)*b);
	}
	return 0;
}