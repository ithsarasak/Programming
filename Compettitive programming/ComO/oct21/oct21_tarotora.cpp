#include <bits/stdc++.h>

using namespace std;
int c, n, k;	
long long mic[2][220];
int main()
{
	scanf("%d",&c);
	while( c-- ){
		long long ans = 1e17;
		for( int i = 0 ; i < 2 ; i++ ){
			for( int j = 0 ; j <= 200 ; j++ ){
				mic[i][j] = 1e17;
			}
		}
		mic[0][100] = 0;
		scanf("%d %d",&n,&k);
		for( int i = 1 ; i <= n ; i++ ){
			long long taro, tora;
			scanf("%lld %lld",&taro,&tora);
			mic[i%2][100-k] = mic[(i+1)%2][100-k+1] + taro;
			mic[i%2][100+k] = mic[(i+1)%2][100+k-1] + tora;
			for( int j = 100-k+1 ; j <= 100+k-1 ; j++ ){
				mic[i%2][j] = min( mic[(i+1)%2][j-1] + tora, mic[(i+1)%2][j+1] + taro );
			}
		}
		for( int i = 100-k ; i <= 100+k ; i++ )ans = min( ans, mic[n%2][i] );
		printf("%lld\n",ans);
	}
	return 0;
}