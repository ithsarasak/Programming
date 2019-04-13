#include <bits/stdc++.h>

using namespace std;

struct item {
	int d;
	item *l, *r;
	item() { }
	item(int d, item *l, item *r) : d(d), l(l), r(r) { }
};

item* newleaf(int d) {
	return new item(d, nullptr, nullptr);
}

item* newpar(item* l, item* r) {
	return new item(l->d + r->d, l, r);
}

const int N = 1e5+5;

int n, m, A[N];
item* ver[N];
vector<int> coord;

int get(int x) { return lower_bound(coord.begin(), coord.end(), x) - coord.begin() + 1; }

item* build(int l = 1, int r = coord.size()) {
	if(l == r) return newleaf(0);
	int mid = (l + r) >> 1;
	return newpar(build(l, mid), build(mid+1, r));
}

item* update(int x, item* p, int l = 1, int r = coord.size()) {
	if(l == r) return newleaf(p->d + 1);
	int mid = (l + r) >> 1;
	if(x <= mid) return newpar(update(x, p->l, l, mid), p->r);
	else return newpar(p->l, update(x, p->r, mid+1, r));
}

int query( item* a, item* b, int k, int l = 1, int r = coord.size() ) {
	if( l == r )return l;
	int m = ( l + r ) >> 1;
	int diff = b->l->d - a->l->d;
	if( diff >= k )return query( a->l, b->l, k, l, m );
	else return  query( a->r, b->r, k-diff, m+1, r );
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", A+i);
		coord.emplace_back(A[i]);
	}
	sort(coord.begin(), coord.end());
	coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
	ver[0] = build();
	for(int i = 1; i <= n; i++) ver[i] = update(get(A[i]), ver[i-1]);
	for(int i = 1, a, b, c; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		int ret = query(ver[a-1], ver[b], c);
		printf("%d\n", coord[ret-1]);
	}	
	return 0;
}