#include <bits/stdc++.h>

using namespace std;
struct gg{
	int t;
	long long d;
	int ty;
};
struct qq{
	int no;
	long long d;
	int bypass;
	bool operator<( const qq &k )const{
		return d > k.d;
	}
}t;
vector<gg> g[10100];
priority_queue<qq> q;
int n, m, s, l;
long long dis[10100][60], ans = 1e17;
int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&l);
	for( int i = 0 ; i < m ; i++ ){
		int f, t;
		long long d;
		scanf("%d %d %lld",&f,&t,&d);
		g[f].push_back({ t, d, 0 });
	}
	for( int i = 0 ; i < s ; i++ )
		int f, t;
		long long d;
		scanf("%d %d %lld",&f,&t,&d);
		g[f].push_back({ t, d, 1 });
	}
	for( int i = 0 ; i < 10100 ; i++ ) for( int j = 0 ; j < 60 ; j++ ) dis[i][j] = 1e17;
	q.push({ 1, 0, 0 });
	dis[1][0] = 0;
	while( !q.empty() ){
		t = q.top();
		q.pop();
		for( int i = 0 ; i < g[t.no].size() ; i++ ){
			if( dis[g[t.no][i].t][t.bypass+g[t.no][i].ty] > t.d + g[t.no][i].d && t.bypass + g[t.no][i].ty <= l ){
				dis[g[t.no][i].t][t.bypass+g[t.no][i].ty] = t.d + g[t.no][i].d;
				q.push({ g[t.no][i].t, t.d + g[t.no][i].d, t.bypass + g[t.no][i].ty });
			} 
		}
	}
	for( int i = 0 ; i < 60 ; i++ )ans = min( ans, dis[n][i] );
	printf("%lld",ans);
	return 0;
}