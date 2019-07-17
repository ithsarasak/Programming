#include <bits/stdc++.h>

using namespace std;
int n;
int shop[100100][3];
int d, s;
long long ans;
int main()
{
	d = s = 1;
	scanf("%d",&n);
	for( int i = 1 ; i <= 2*n ; i++ ){
		int t;
		scanf("%d",&t);
		if( shop[t][0] == 0 )shop[t][0] = i;
		else shop[t][1] = i;
	}
	for( int i = 1 ; i <= n ; i++ ){
		int sum = abs( d - shop[i][0] ) + abs( s - shop[i][1] );
		if( abs( d - shop[i][1] ) + abs( s - shop[i][0] ) < sum ){
			sum = abs( d - shop[i][1] ) + abs( s - shop[i][0] );
			d = shop[i][1], s = shop[i][0];
		}
		else{
			d = shop[i][0], s = shop[i][1];
		}
		ans += ( long long )sum;
	}
	printf("%lld",ans);
	return 0;
}