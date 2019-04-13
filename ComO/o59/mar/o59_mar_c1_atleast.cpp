#include <bits/stdc++.h>
#define pii pair<int, double>
#define x first
#define y second
#define mp make_pair
using namespace std;

struct item {
	pii d;
	item *l, *r;
	item() { }
	item( pii d, item *l, item *r ) : d(d), l(l), r(r) { }
};

item* newleaf( int cnt, double val ) {
	return new item( mp( cnt, val ), nullptr, nullptr);
}

item* newpar(item* l, item* r) {
	return new item( mp( l->d.x + r->d.x, l->d.y+r->d.y ), l, r );
}

const int N = 1e5+5;

int 	n, m;
double A[N], S[N];
item* ver[N];
vector<double> coord;
map<double,int> cnt;

int get(double x) { 
	cnt[x]++;
	return lower_bound(coord.begin(), coord.end(), x) - coord.begin() + cnt[x];
}

item* build(int l = 1, int r = coord.size()) {
	if(l == r) return newleaf( 0, 0.00 );
	int mid = (l + r) >> 1;
	return newpar(build(l, mid), build(mid+1, r));
}

item* update(int x, item* p, double va, int l = 1, int r = coord.size()) {
	//printf("%d %d %d\n",l,r,x);
	if(l == r) return newleaf( p->d.x + 1, p->d.y + va );
	int mid = (l + r) >> 1;
	if(x <= mid) return newpar(update(x, p->l, va, l, mid), p->r);
	else return newpar(p->l, update(x, p->r, va, mid+1, r));
}

double query( item* a, item* b, int k, int l = 1, int r = coord.size() ) {
	if( k == 0 )return 0.00;
	if( l == r )return b->d.y - a->d.y;
	int m = ( l + r ) >> 1;
	int diff = b->l->d.x - a->l->d.x;
	//printf("%d %d %f %f %d %d\n",l,r,b->l->d.y, a->l->d.y,b->l->d.x, a->l->d.x);
	if( diff >= k )return query( a->l, b->l, k, l, m );
	else return b->l->d.y - a->l->d.y + query( a->r, b->r, k-diff, m+1, r );
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lf",&A[i]);
		S[i] = S[i-1] + A[i];
		coord.emplace_back(A[i]);
	}
	sort(coord.begin(), coord.end());
	ver[0] = build();
	for(int i = 1; i <= n; i++)ver[i] = update(get(A[i]), ver[i-1], A[i] );
	for(int i = 1, a, b ; i <= m; i++) {
		double c;
		scanf("%d %d %lf", &a, &b, &c);
		int l = 0, r = b - a + 1, le = b - a + 1, allsum = S[b] - S[a-1];
		while( l < r ){
			int m = ( l + r ) / 2;
			double sum = query( ver[a-1], ver[b], m );
			//printf("->%d %d %d %f\n",l,r,m,sum);
			if( ( allsum - sum ) / ( le - m ) >= c )r = m;
			else l = m + 1;
		}
		if( l == le )printf("-1\n");
		else printf("%d\n",l);
	}	
	return 0;
}