#include <bits/stdc++.h>

using namespace std;
struct po{
	long long x, y, p;
}tt;
struct gg{
	int t;
	long long d;
};
struct qq{
	int no;
	long long d;
	int bit;
	bool operator<( const qq &k )const{
		return d > k.d;
	}
}t;
int k;
long long n, m;
long long dis[20][5000];
vector <po> v;
vector <gg> g[20];
priority_queue <qq> q;
long long ans = 1e17;
int main()
{
	scanf("%lld %lld %d",&n,&m,&k);
	v.push_back({ 0, 0, 0 }); 
	for( int i = 1 ; i <= k ; i++ ){
		scanf("%lld %lld %lld",&tt.x,&tt.y,&tt.p);
		v.push_back( tt );
	}
	v.push_back({ n-1, m-1, 0 });
	for( int i = 0 ; i < v.size() ; i++ ){
		for( int j = i + 1 ; j < v.size() ; j++ ){
			g[i].push_back({ j, ( long long )ceil(sqrt(( double )(v[i].x-v[j].x)*( double )(v[i].x-v[j].x) + ( double )(v[i].y-v[j].y)*( double )(v[i].y-v[j].y) ))});
			g[j].push_back({ i, ( long long )ceil(sqrt(( double )(v[i].x-v[j].x)*( double )(v[i].x-v[j].x) + ( double )(v[i].y-v[j].y)*( double )(v[i].y-v[j].y) ))});
		}
	}
	q.push({ 0, 0, 0 });
	for( int i = 0 ; i < 20 ; i++ )for( int j = 0 ; j < 5000 ; j++ )dis[i][j] = 1e17;
	dis[0][0] = 0;
	while( !q.empty() ){
		t = q.top();
		q.pop();
		if( ( t.bit & ( 1 << t.no ) ) == 0 ){
			t.d -= v[t.no].p;
			t.bit |= ( 1 << t.no );
		}
		for( int i = 0 ; i < g[t.no].size() ; i++ ){
			if( dis[g[t.no][i].t][t.bit] > t.d + g[t.no][i].d ){
				dis[g[t.no][i].t][t.bit] = t.d + g[t.no][i].d;
				q.push({ g[t.no][i].t, t.d + g[t.no][i].d, t.bit });
			}
		}
	}
	for( int i = 0 ; i < 5000 ; i++ ){
		ans = min( ans, dis[v.size()-1][i] );
	}
	printf("%lld",ans);
	return 0;
}		