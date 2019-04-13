#include <bits/stdc++.h>

using namespace std;

const int N = 7e4 + 100;
struct item{
	long long sz, sum;
	item *l, *r;
	item() {}
	item( long long sz, long long va, item* l, item* r ) : sz( sz ), sum( va ), l( l ), r( r ) {}
};

item* newleaf( int sz, long long va ) {
	return new item( sz, va, nullptr, nullptr );
}

item* newpar( item* l, item* r ) {
	return new item( l->sz + r->sz, l->sum + r->sum, l, r );
}

item* ver[N];
int n, q, e;
long long sum[N], va[N];
vector<long long> v;
unordered_map<long long, int> cnt;

int get( long long x ) { 
	cnt[x]++;
	return lower_bound( v.begin(), v.end(), x ) - v.begin() + cnt[x]; }

item* build( int l = 1, int r = n ) {
	if( l == r ) return newleaf( 0, 0 );
	int mid = ( l + r ) >> 1;
	return newpar( build( l, mid ), build( mid+1, r ) );
}

item* update( int idx, long long va, item* p, int l = 1, int r = n ){
	if( l == r ) return newleaf( p->sz + 1, p->sum + va );
	int mid = ( l + r ) >> 1;
	if( mid >= idx ) return newpar( update( idx, va, p->l, l, mid ), p->r );
	else return newpar( p->l, update( idx, va, p->r, mid+1, r ) ); 
}

long long query( item* a, item* b, int k, int l = 1, int r = n ) {
	if( l == r ) return b->sum - a->sum;
	int mid = ( l + r ) >> 1;
	int diff = b->l->sz - a->l->sz;
	if( diff >= k ) return query( a->l, b->l, k, l, mid );
	else return b->l->sum - a->l->sum + query( a->r, b->r, k - diff, mid + 1, r );
}

int main()
{
	scanf("%d %d %d",&n,&q,&e);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%lld",&va[i]);
		sum[i] = sum[i-1] + va[i];
		v.emplace_back( va[i] );
	}
	sort( v.begin(), v.end() );
	ver[0] = build();
	for( int i = 1 ; i <= n ; i++ ) ver[i] = update( get( va[i] ), va[i], ver[i-1] );
	long long x;
	for( int i = 0, l, r ; i < q ; i++ ) {
		scanf("%d %d",&l,&r);
		if( i >= 1 && e ) l = l ^ x, r = r ^ x;
		x = sum[r] - sum[l-1] - 2*query( ver[l-1], ver[r], ( r-l+1 ) >> 1 );
		printf("%lld\n",x);
	} 
	return 0;
}