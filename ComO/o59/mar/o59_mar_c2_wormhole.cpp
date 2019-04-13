#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int n, m, ap[65][65];
map<pii, vector<pii> > M;
vector<pii> coord;

int get(pii x) { return lower_bound(coord.begin(), coord.end(), x) - coord.begin(); }

int dist(pii a, pii b) { return abs(a.x - b.x) + abs(a.y - b.y); }

int main()
{
	fill_n(ap[0], 65*65, INT_MAX);
	scanf("%d %d",&n,&m);
	for( int i = 0, a, b, c, d ; i < n ; i++ ) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		M[pii(a, b)].emplace_back(c, d);
		M[pii(c, d)].emplace_back(a, b);
		coord.emplace_back(a, b), coord.emplace_back(c, d);
	}
	sort(coord.begin(), coord.end());
	coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
	int n = coord.size();
	for(int i = 0; i < n; i++) {
		ap[i][i] = 0;
		for(pii p : M[coord[i]]) ap[i][get(p)] = 0;
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
		ap[i][j] = min(ap[i][j], dist(coord[i], coord[j]));
	for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
		ap[i][j] = min(ap[i][j], ap[i][k] + ap[k][j]);
	for( int i = 0, a, b, c, d ; i < m ; i++ ) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		pii st(a, b), en(c, d);
		int ret = dist(st, en);
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
			ret = min(ret, dist(st, coord[i]) + ap[i][j] + dist(coord[j], en));
		printf("%d\n", ret);
	}
	return 0;
}