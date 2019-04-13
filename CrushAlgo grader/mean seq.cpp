#include<bits/stdc++.h>

using namespace std;

int sum, now, ma = -1e9 - 10, mi = 1e9 + 10, n;
int main()
{
	scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&now);
		if( i % 2 == 1 ){
			sum += now;
			mi = min( mi, sum );
			sum += now;
		}
		else{
			sum -= now;
			ma = max( ma, sum );
			sum -= now;
		}
	}
	printf("%d",max( 0, mi - ma + 1 ) );
	return 0;
}
