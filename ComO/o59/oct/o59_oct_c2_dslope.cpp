#include <bits/stdc++.h>

using namespace std;
int n, k;
const int mod = 1e9-1;
int dp[3][80100], num[80100], fen[80100];
void up( int idx , int va)
{
	for( int i = idx ; i <= n ; i += ( i & -i ) ){
		fen[i] += va;
		fen[i] %= mod;
	}
	return ;
}
int query( int idx )
{
	int sum = 0;
	for( int i = idx - 1 ; i > 0 ; i -= ( i & -i ) ){
		sum += fen[i];
		sum %= mod;
	}
	return sum;
}
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&num[i]);
	}
	for( int i = 1 ; i <= n ; i++ ){
		dp[1][i] = 1;
	}
	for( int i = 2 ; i <= k ; i++ ){
		memset( fen, 0, sizeof fen );
		for( int j = n ; j >= 1 ; j -- ){
			if( n-j+1 < i )dp[i%2][j] = 0;
			else{
				dp[i%2][j] = query( num[j] );
			}
			dp[i%2][j] %= mod;
			up( num[j], dp[(i+1)%2][j] );
		}
	}
	int ans = 0;
    for( int i = 1 ; i <= n ; i++ ){
        ans += dp[k%2][i];
        ans %= mod;
    }
    printf("%d",ans);
    return 0;
}