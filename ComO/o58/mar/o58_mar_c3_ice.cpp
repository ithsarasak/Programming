#include <bits/stdc++.h>
#define iii tuple<int, int, int>
#define pii pair<int, int>
#define t first
#define d second 
#define mp make_pair
#define mt make_tuple

using namespace std;

const int N = 2e5+200;
priority_queue<iii> q;
iii t;
int n, m, s[N];
pii dis[N];
vector<pii> g[N];
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&s[i]);
		dis[i].d = s[i];
		if( s[i] )dis[i].t = i;
	}
	for( int i = 0, u, v, d ; i < m ; i++ ) {
		scanf("%d %d %d",&u,&v,&d);
		g[u].emplace_back( mp( v, d ) ), g[v].emplace_back( mp( u, d ) );
	}
	for( int i = 1 ; i <= n ; i++ )if( s[i] )q.push( mt( s[i], i, i ) );

	while( !q.empty() ) {
		t = q.top();
		q.pop();
		int now, di, fr;
		tie( di, now, fr ) = t;
		for( pii go : g[now] ) {
			if( ( dis[go.t].d < di-go.d )||( dis[go.t].d == di-go.d && di-go.d != 0 && dis[go.t].t > fr ) ){
				dis[go.t].t = fr, dis[go.t].d = di-go.d;
				q.push( mt( di-go.d, go.t, fr ) );
			}
		}
	}
	for( int i = 1;  i <= n ; i++ ) {
		printf("%d %d\n",dis[i].t,dis[i].d);
	}
	return 0;
}