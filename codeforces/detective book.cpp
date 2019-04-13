#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+100;
int n, book[N], cnt, mx = -1;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) scanf("%d",&book[i]);
	for( int i = 1 ; i <= n ; i++ ) {
		if( i > mx )cnt++;
		mx = max( mx, book[i]);
	}
	printf("%d",cnt);
	return 0;
}