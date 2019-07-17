#include <bits/stdc++.h>

using namespace std;
int n, k, mx;
int pos[10][1010], per, best[1010], visit[1010];
vector<int> g[1010];
void dfs( int no )
{ 
	// printf("%d\n",no);
	visit[no] = 1;
	for( int i = 0 ; i < g[no].size() ; i++ ){
		if( !visit[g[no][i]] )dfs( g[no][i] );
		best[no] = max( best[no] , best[g[no][i]] + 1 );
	}
	best[no] = max( best[no], 1 );
	mx = max( best[no], mx );
	return ;
}
int main()
{
	scanf("%d %d",&n,&k);
	for( int i = 1 ; i <= k ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			scanf("%d",&per);
			pos[i][per] = j;
		}
	}
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j++ ){
			if( i == j )continue;
			int cc = 1;
			for( int l = 1 ; l <= k ; l++ ){
				if( pos[l][i] > pos[l][j] ){
					cc = 0;
					break;
				}
			}
			if( cc ){
				g[i].push_back( j );
			}
		}
	}
	for( int i = 1 ; i <= n ; i++ ){
		if( !visit[i] )dfs( i );
	}
	// for( int i = 1 ; i <= n ; i++ ){
	// 	printf("%d : ",i);
	// 	for( int j = 0 ; j < g[i].size();  j++ ){
	// 		printf("%d ",g[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// for( int i = 1 ; i <= n ; i++ )printf("%d ",best[i]);
	// printf("\n");
	printf("%d",mx);
	return 0;
}