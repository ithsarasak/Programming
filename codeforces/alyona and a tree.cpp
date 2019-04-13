#include <bits/stdc++.h>

using namespace std;
struct gg{
	int no;
	long long d;
};
vector<gg> g[200100];
long long n, fen[200100], mark[200100], dis[200100], va[200100], ans[200100];
void up( int idx, int va )
{
	for( int i = idx ; i <= 200000 ; i += ( i & -i ) )fen[i] += va;
}
long long query( int idx )
{
	long long sum = 0;
	for( int i = idx ; i > 0 ; i -= ( i & -i ) )sum += fen[i];
	return sum;
}
void dfs( int now, int pos, long long d )
{
	dis[pos] = d;
	mark[now] = 1;
	for( int i = 0 ; i < g[now].size() ; i++ ){
		if( !mark[g[now][i].no] )dfs( g[now][i].no, pos + 1, d + g[now][i].d );
	}
	int l = 1, r = pos;
	while( l < r ){
		int mid = ( l + r ) / 2;
		if( dis[mid] < dis[pos] - va[now] )l = mid + 1;
		else r = mid;
	}
	up( l, 1 ), up( pos, -1 );
	int w = query( pos );
	ans[now] += w;
	up( pos, -1*w ), up( pos + 1, w );
	return ; 
}
int main()
{
	scanf("%I64d",&n);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%lld",&va[i]);
	}
	for( int i = 2 ; i <= n ; i++ ){
		int no;
		long long d;
		scanf("%d %lld",&no,&d);
		g[i].push_back({ no, d });
		g[no].push_back({ i, d });
	}
	dfs( 1, 1, 0 );
	for( int i = 1 ; i <= n ; i++ )cout << ans[i] << " ";
	return 0;
}