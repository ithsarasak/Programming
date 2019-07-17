#include <bits/stdc++.h>

using namespace std;
long long n, book[2100];
long long dp[2][2100];
int main()
{
	scanf("%lld",&n);
	for( long long i = 1 ; i <= n ; i++ ){ 	
		scanf("%lld",&book[i]);
	}
	for( long long i = 1 ; i <= n ; i++ ){
		for( long long j = 0 ; j <= i ; j++ ){
			if( j == 0 )dp[i%2][j] = max( dp[(i+1)%2][j], dp[(i+1)%2][j+2] - book[i] );
			else{
				dp[i%2][j] = max( dp[(i+1)%2][j-1] + book[i],dp[(i+1)%2][j+2] - book[i] );
			}
		}
	}
	printf("%lld",dp[n%2][0]);
	return 0;
}