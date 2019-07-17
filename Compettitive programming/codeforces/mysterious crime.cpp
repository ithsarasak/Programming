#include <bits/stdc++.h>

using namespace std;
int n, m;
int perm[15][100100];
int pos[100100], last[100100];
long long ans;
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= m ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			scanf("%d",&perm[i][j]);
		}
	}
	for( int i = 1 ; i <= n ; i++ )perm[1][i] = pos[perm[1][i]] = i;
	for( int i = 1 ; i <= n ; i++ )last[i] = n;
	for( int i = 2 ; i <= m ; i++ ){
		for( int j =1 ; j <= n ; j++ ){
			perm[i][j] = pos[perm[i][j]];
		}
	}
	for( int i = 2 ; i <= m ; i++ ){
		int cur = 1;
		for( int j = 1 ; j <= n ; j++ ){
			while( cur < j )cur++;
			while( perm[i][cur] + 1 == perm[i][cur+1] && cur + 1 <= n )cur++;
			last[perm[i][j]] = min( last[perm[i][j]], perm[i][cur] );
		}
	}
	int now = 1;
	while( now <= n ){
		int le = last[now] - now + 1;
		ans += ( long long )( le + 1 ) * ( long long )le / 2;
		now = last[now] + 1;
	}
	printf("%lld",ans);
	return 0;
}