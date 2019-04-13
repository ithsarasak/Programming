#include <bits/stdc++.h>

using namespace std;
int n, m, dis[300100];
long long choc[300100], sum;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%lld",&choc[i]);
		sum += choc[i];
	}
	scanf("%d",&m);
	for( int i = 1 ; i <= m ; i++ ){
		scanf("%d",&dis[i]);
	}
	sort( choc + 1, choc + 1 + n, greater<int>() );
	for( int i = 1 ; i <= m ; i++ ){
		printf("%lld\n",sum-choc[dis[i]]);
	}
	return 0;
}