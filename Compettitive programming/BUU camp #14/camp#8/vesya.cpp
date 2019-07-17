#include <bits/stdc++.h>

using namespace std;
long long dp[300100], ans;
long long mush[2][300100];
long long sum1[300100], sum2[300100], sum[300100];
int n;
int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= 2 ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			scanf("%lld",mush[i][j]);
		}
	}
	for( int i = n ; i >= 1 ; i-- ){
		sum[i] = sum[i+1] + mush[1][i] + mush[2][i];
	}
	long long cnt = 0;
	for( int i = 1 ; i <= n ; i++ )sum1[1] += cnt * mush[1][i], cnt++;
	for( int i = n ; i >= 1 ; i-- )sum1[1] += cnt * mush[2][i], cnt++;
	for( int i = 2 ; i <= n ; i++ ){
		sum1[i] = sum1[i-1];
		sum1[i] -= mush[2][i-1] * ( 2 * ( n - i + 2 ) - 1 );
		sum1[i] -= sum[i];
	}
	cnt = 0;
	for( int i = 1 ; i <= n ; i++ )sum2[1] += cnt * mush[2][i], cnt++;
	for( int i = n ; i >= 1 ; i-- )sum2[1] += cnt * mush[1][i], cnt++;
	for( int i = 2 ; i <= n ; i++ ){
		sum2[i] = sum2[i-1];
		sum2[i] -= mush[1][i-1] * ( 2 * ( n - i + 2 ) - 1 );
		sum2[i] -= sum[i];
	}
	cnt = 0;
	long long sumn = 0;
	for( int i = 1 ; i <= n ; i++ ){
		if( i % 2 ){
			ans = max( ans, sumn + ((i/2)*4)*sum[i] + sum1[i] );
			sumn += mush[1][i] * cnt;
			cnt++;
			sumn += mush[2][i] * cnt;
			cnt++;
		}
		else{
			ans = max( ans, sumn + (((i-1)/2)*4+2)*sum[i] + sum2[i] );
			sumn += mush[2][i] * cnt;
			cnt++;
			sumn += mush[1][i] * cnt;
			cnt++;
		}
	}
	printf("%lld",max( ans, sumn ));
	return 0;
}