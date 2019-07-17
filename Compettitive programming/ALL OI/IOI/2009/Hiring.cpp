#include <bits/stdc++.h>
#define pdi pair<double, int>
#define x first
#define y second

using namespace std;

const int N = 5e5 + 100;

int n, ansmx, ansid;
double w, s[N], q[N], sum;
pdi can[N], ans[N];
priority_queue<pdi> pq;

void solve( int n ) {
	while( !pq.empty() ) pq.pop();
	int idx = 0, mx = 0;
	double sum = 0, used = 1e9;
	for( int i = 1 ; i <= n ; i++ ) {
		pq.emplace( pdi( q[can[i].y], can[i].y ) );
		sum += q[can[i].y];
		while( sum * can[i].x > w ) {
			sum -= pq.top().x;
			pq.pop();
		}
		double use = can[i].x * sum;
		if( pq.size() > mx ) mx = pq.size(), idx = i, used = use;
		else if( pq.size() == mx && use < used ) used = use, idx = i;
	}
	ansmx = mx, ansid = idx;
	return ;
}

int main()
{
	scanf("%d %lf",&n,&w);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%lf %lf",&s[i],&q[i]);
		can[i] = pdi( s[i]/q[i], i );
	}
	sort( can + 1, can + 1 + n );
	solve( n );
	printf("%d\n",ansmx);
	solve( ansid );
	while( !pq.empty() ) {
		pdi t = pq.top();
		pq.pop();
		printf("%d\n",t.y);
	}
	return 0;
}
