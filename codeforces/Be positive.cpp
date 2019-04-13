#include <bits/stdc++.h>

using namespace std;
int n;
int m, o, p;
int main()
{
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		int t;
		scanf("%d",&t);
		if( t < 0 )m++;
		else if( t == 0 )o++;
		else p++;
	}
	int half = n/2;
	if( n % 2 )half++;
	if( m >= half )printf("-1000");
	else if( p >= half )printf("1000");
	else printf("0");
	return 0;
}