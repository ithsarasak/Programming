#include <bits/stdc++.h>

using namespace std;

int n, k;
long long ans;
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 0 ; i < n ; i++ ) ans += ( long long )k / ( long long )( 1 << i );
	printf("%lld",ans);
	return 0;
}