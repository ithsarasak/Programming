#include <bits/stdc++.h>

using namespace std;
struct gg{
	int t;
	long long d;
};
struct qq{
	int no;
	long long d;
	int use;
	bool operator<( const qq &k )const{
		return d > k.d;
	}
}t;
int n, m, k;
long long dis[100100][10], ans = 1e17;
priority_queue<qq> q;
vector<gg> g[100100];
int check( long long d ){
	if( d < -100 )return 1;
	else return 0;
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for( int i = 0 ; i < m ; i++ ){
		int f, t;
		long long d;
		scanf("%d %d %lld",&f,&t,&d);
		g[f].push_back({ t, d });
	}
	q.push({ 1, 0, 0 });
	for( int i = 0 ; i < 100100 ; i++ )for( int j = 0 ; j < 10 ; j++ )dis[i][j] = 1e17;
	dis[1][0] = 0;
	while( !q.empty() ){
		t = q.top();
		q.pop();
		//printf("%d %lld %d\n",t.no,t.d,t.use);
		for( int i = 0 ; i < g[t.no].size() ; i++ ){
			if( dis[g[t.no][i].t][t.use+check(g[t.no][i].d)] > t.d + max( ( long long )0, g[t.no][i].d ) && t.use+check(g[t.no][i].d) <= k ){
				dis[g[t.no][i].t][t.use+check(g[t.no][i].d)] = t.d + max( ( long long )0, g[t.no][i].d );
				q.push({ g[t.no][i].t, t.d + max( ( long long )0, g[t.no][i].d ), t.use+check(g[t.no][i].d) });
			} 
		}
	}
	for( int i = 0 ; i <= k ; i++ )ans = min( ans, dis[n][i] );
	if( ans == 1e17 )printf("-1");
	else printf("%lld",ans);
	return 0;
}