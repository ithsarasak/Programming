#include <bits/stdc++.h>

using namespace std;
int t;
double d, a, b;
int main()
{
	scanf("%d",&t);
	while( t-- ){
		scanf("%lf",&d);
		if( d*d - 4*d < 0 ){
			printf("N\n");
			continue;
		}
		a = ( d + sqrt( d*d - 4*d ) ) / 2.00000;
		b = d - a;
		printf("Y %.9lf %.9lf\n",a,b);
	}
	return 0;
}