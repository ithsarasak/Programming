#include <bits/stdc++.h>

using namespace std;
struct qq{
	int x, y, d, k;
	bool operator<( const qq &o )const{
		return d > o.d;
	}
}t;
struct papo{
	int x, y;
}pa[30][30];
int mark[30][30], va[30][30];
int dis[30][30][30];
priority_queue<qq> q;
int n, p, k, ans = 1e9;
vector<papo> w;
int main()
{
	for( int i = 0 ; i < 30 ; i ++ )for( int j = 0 ; j < 30 ; j ++ )for( int l = 0 ; l < 30 ; l ++ )dis[i][j][l] = 1e9;
	w.push_back({ 1, 0 });
	w.push_back({ 0, 1 });
	w.push_back({ -1, 0 });
	w.push_back({ 0, -1 });
	scanf("%d %d %d",&n,&p,&k);
	for( int i = 1 ; i <= n ; i++ )for( int j = 1 ; j <= n ; j++ )scanf("%d",&va[i][j]);
	for( int i = 0 ; i < p ; i++ ){
		int a, b, c, d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a++,b++,c++,d++;
		mark[a][b] = 1;
		pa[a][b].x = c;
		pa[a][b].y = d;
 	}
 	q.push({ 1, 1, 0, 0 });
 	dis[1][1][0] = 0;
 	while( !q.empty() ){
 		t = q.top();
 		q.pop();
 		//printf("%d %d %d %d\n",t.x,t.y,t.d,t.k);
 		for( int i = 0 ; i < 4 ; i++ ){
 			int a = t.x+w[i].x, b = t.y+w[i].y;
			if( dis[a][b][t.k] > t.d + va[a][b] && a >= 1 && a <= n && b >= 1 && b <= n ){
 				dis[a][b][t.k] = t.d + va[a][b];
 				q.push({ a, b, t.d + va[a][b], t.k });
 			}
 		}
 		if( mark[t.x][t.y] && dis[pa[t.x][t.y].x][pa[t.x][t.y].y][t.k] > t.d && t.k + 1 <= k )q.push({ pa[t.x][t.y].x, pa[t.x][t.y].y, t.d , t.k + 1 });
 	}
 	for( int i = 0 ; i <= k ; i++ )ans = min( ans, dis[n][n][i] );
 	printf("%d",ans);
 	return 0;
}