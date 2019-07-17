#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int n, sushi[N], sum[N];
int check( int mid ) {
	//  printf("%d\n",mid);
	for( int i = 1 ; i+2*mid-1 <= n ; i++ ) {
		// printf("%d %d %d %d %d\n",sum[i+mid-1]-sum[i-1], sum[i+mid*2-1]-sum[i+mid-1],i+mid-1,i+mid*2-1, i-1 );
		if( ( sum[i+mid-1] - sum[i-1] == mid && sum[i+2*mid-1] - sum[i+mid-1] == 2*mid ) || ( sum[i+mid-1] - sum[i-1] == 2*mid && sum[i+2*mid-1] - sum[i+mid-1] == mid ) ){
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&sushi[i]);
		sum[i] = sum[i-1] + sushi[i];
	}
	int l = 1, r = n / 2;
	while( l < r ) {
		//printf("%d %d\n",l,r);
		int mid = ( l + r + 1 ) / 2;
		if( check( mid ) )l = mid;
		else r = mid - 1 ;
	}
	printf("%d",2*l);
	return 0;
}