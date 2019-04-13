#include <bits/stdc++.h>
#define pdi pair<double, int>
#define x first
#define y second

using namespace std;

const int N = 5e5 + 100;

int n, idx, mx, m, used = 1e9;
double w, s[N], q[N], sum;
pdi can[N], ans[N];
priority_queue<double> pq;

int main()
{
	scanf("%d %lf",&n,&w);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%lf %lf",&s[i],&q[i]);
		can[i] = pdi( s[i]/q[i], i );
	}
	sort( can + 1, can + 1 + n );
	for( int i = 1 ; i <= n ; i++ ) {
		pq.emplace( q[can[i].y] );
		sum += q[can[i].y];
		while( sum * can[i].x > w ) {
			sum -= pq.top();
			pq.pop();
		}
		int use = can[i].x * sum;
		if( pq.size() > mx ) mx = pq.size(), idx = i, used = use;
		else if( pq.size() == mx && use < used ) used = use, idx = i;
	}
	printf("%d\n",mx);
	return 0;
}
