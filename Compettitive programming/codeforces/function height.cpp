#include<bits/stdc++.h>

using namespace std;
long long n, k, h;
int main()
{
	scanf("%lld %lld",&n,&k);
	h = k / n;
	if( h * n < k )h++;
	cout << h ;
	return 0;
}