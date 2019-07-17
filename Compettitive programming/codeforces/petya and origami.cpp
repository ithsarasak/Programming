#include <bits/stdc++.h>

using namespace std;
double n, k, r, g, b, ans;
int main()
{
	scanf("%lf %lf",&n,&k);
	r = n*2, g = n*5, b = n*8;
	ans = ( ceil )( r / k ) + ( ceil )( g / k ) + ( ceil )( b / k );
	printf("%.0lf",ans);
	return 0;
}