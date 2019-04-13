#include <bits/stdc++.h>

using namespace std;
int n;
long long ans, num[300100];
int main()
{
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )scanf("%d",&num[i]);
	sort( num, num + n );
	for( int i = 0 ; i < n / 2 ; i++ ){
		ans += num[i]*num[i] + 2*num[i]*num[n-i-1] + num[n-i-1]*num[n-i-1];
	}
	printf("%lld", ans);
	return 0;
}