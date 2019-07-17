#include <bits/stdc++.h>

using namespace std;
int q, l, r;
int main()
{
	scanf("%d",&q);
	while( q-- ){
		int l, r, sum = 0;
		scanf("%d %d",&l,&r);
		if( l % 2 == 0 ){
			sum += l;
			l++;
		}
		if( r % 2 ){
			sum -= r;
			r--;
		}
		sum += ( ( r - l + 1 ) / 2 );
		printf("%d\n",sum);
	}
	return 0;
}