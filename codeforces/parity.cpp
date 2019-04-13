#include <bits/stdc++.h>

using namespace std;
int b, k;
int odd, num[100010];
int check( int a, int b )
{
	if( a % 2 == 0 || b % 2 == 0 )return 0;
	else return 1;
}
int main()
{
	scanf("%d %d",&b,&k);
	for( int i = 1 ; i <= k ; i++ ){
		scanf("%d",&num[i]);
	}
	for( int i = 1 ; i <= k - 1 ; i++ )odd += check( b, num[i] ); 
	if( num[k] % 2 == 1 )odd++;
	if( odd % 2 )printf("odd");
	else printf("even");
	return 0;
}