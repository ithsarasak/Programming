#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int N = 1e3+100;
int q, par[N], n, ind[N];
vector<iii> e;

int findroot( int now ) {
	if( now == par[now] ) return now;
	else return par[now] = findroot( par[now] );
}

int main()
{
	scanf("%d",&q);
	while( q-- ) {
		int mx = 0, ans = 0;
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ ) par[i] = i;
		for( int i = 1 ; i <= n ; i++ ) for( int j = 1, t ; j <= n ; j++ ) {
			scanf("%d",&t);
			if( i == j ) continue ;
			e.emplace_back( iii( t, i, j ) );
		}
		sort( e.begin(), e.end() );
		for( iii i : e ) {
			int d, f, t, a, b;
			tie( d, f, t ) = i;
			a = findroot( f ), b = findroot( t );
			if( a != b ) {
				// printf("%d %d %d %d\n",f,t,a,b);
				ind[f]++, ind[t]++;
				par[a] = b;
			}
		}
		for( int i = 1 ; i <= n ; i++ ) if( mx < ind[i] ) {
			mx = ind[i], ans = i;
		}
		printf("%d %d\n",ans,mx);
	}
	return 0;
}