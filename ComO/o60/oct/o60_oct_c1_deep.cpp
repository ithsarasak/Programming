#include <bits/stdc++.h>

using namespace std;
struct gg{
	int t, d;
};
int n, qe, ti;
vector<int> g[200100];
int s, a, b, lv[200100], tim[200100], jump[200100];
int dir( ) {
	int res = ((s & 8) >> 3);
	s = (s * a + b) % 40507;
	return res;
}
void dfs( int no )
{
	tim[no] = ti;
	lv[ti] = no;
	ti++;
	if( g[no].size() == 0 )jump[no] = 0;
	else if( g[no].size() == 1 ){
		dfs( g[no][0] );
		jump[no] = jump[g[no][0]] + 1;
	}
	else{
		jump[no] = 0;
		dfs( g[no][0] ), dfs( g[no][1] );
	}
	return ;
}
int main()
{
	scanf("%d %d",&n,&qe);
	for( int i = 0 ; i < n ; i++ ){
		int a, b;
		scanf("%d %d",&a,&b);
		if( a != -1 )g[i].emplace_back( a );
		if( b != -1 )g[i].emplace_back( b );
	}
	dfs( 0 );
	while( qe-- ){
		int l;
		scanf("%d %d %d %d",&l,&s,&a,&b);
		int ans, no = 0;
		while( 1 ){
			if( g[no].empty() || l == 0 ){
				ans = no;
				break;
			}
			else if( g[no].size() == 1 ){
				if( l <= jump[no] ){
					ans = lv[tim[no]+l];
					break;
				}
				else{
					l -= jump[no] ;
					no = lv[tim[no]+jump[no]];
				}
			}
			else{
				if( dir() == 0 ){
					no = g[no][0];
					l--;
				}
				else{
					no = g[no][1];
					l--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}