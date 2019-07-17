#include <bits/stdc++.h>

using namespace std;
struct vv{
	int t, d;
};
struct qq{
	int no, d, now;
	bool operator<( const qq &k )const{
		return d > k.d;
	}
}t;
priority_queue<qq> q;
std::vector<vv> g[50100];
int n, m, l, s, to;
int va[50100], dis[50100][40];
int main()
{
	for( int i = 0 ; i < 50100 ; i++ ){
		for( int j = 0 ; j < 40 ; j++ ){
			dis[i][j] = 1e9;
		}
	}
	scanf("%d %d %d",&n,&m,&l);
	scanf("%d %d",&s,&to);
	for( int i = 1 ; i <= n ; i++ )scanf("%d",&va[i]);
	for( int i = 0 ; i < m ; i++ ){
		int f, to, d;
		scanf("%d %d %d",&f,&to,&d);
		g[f].push_back({ to, d });
	}
	dis[s][0] = 0; 
	q.push({ s, 0, 0 });
	while( !q.empty() ){
		t = q.top();
		q.pop();
		if( t.now == va[t.no] && t.now != l + 1 ){
			t.now++;
		}
		for( int i = 0 ; i < g[t.no].size() ; i++ ){
			if( dis[g[t.no][i].t][t.now] > t.d + g[t.no][i].d ){
				dis[g[t.no][i].t][t.now] = t.d + g[t.no][i].d;
				q.push({ g[t.no][i].t, t.d + g[t.no][i].d, t.now });
			}
		}
	}
	if( dis[to][l] == 1e9 )printf("-1");
	else printf("%d",dis[to][l]);
	return 0;
}