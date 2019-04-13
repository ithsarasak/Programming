#include <bits/stdc++.h>

using namespace std;

int n;
long long sum;
int main()
{
	scanf("%d",&n);
	for( int i = 2 ; i <= n - 1 ; i++ )sum += i * ( i + 1 );
	printf("%lld",sum);
	return 0;
}