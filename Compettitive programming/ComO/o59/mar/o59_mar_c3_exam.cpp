#include <bits/stdc++.h>

using namespace std;
struct item{
	int data;
	item* l;
	item* r;
	item() { }
	item( int data, item* l, item* r ) : data( data ), l( l ), r( r ) { }
};

item* newleaf( int data ) {
	return new item( data, nullptr, nullptr );
}

item* newpar( item* l, item* r ) {
	return new item( l->data+r->data, l, r );
}

const int N = 5e4 + 500;
int exam[N], n, q;
map<int, int> last;
item* ver[N];
item* cur;

item* build( int l = 1, int r = n ) {
	if( l == r ) return newleaf( 0 );
	int mid = ( l + r ) >> 1;
	return newpar( build( l, mid ), build( mid + 1, r ) );
}

item* update( item* p, int idx, int va, int l = 1, int r = n ) {
	if( l == r )return newleaf( va );
	int mid = ( l + r ) >> 1;
	if( idx <= mid )return newpar( update( p->l, idx, va, l, mid ), p->r );
	else return newpar( p->l, update( p->r, idx, va, mid+1, r ) );
}

int query( item* p, int ll, int rr, int l = 1, int r = n ) {
	if( l > rr || r < ll || l > r ) return 0;
	if( l >= ll && r <= rr )return p->data;
	int mid = ( l + r ) >> 1;
	return query( p->l, ll, rr, l, mid ) + query( p->r, ll, rr, mid + 1, r );
}

int main()
{
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )scanf("%d",&exam[i]);
	
	// for( int i = 1 ; i <= n ; i++ )printf("%d ",mark[i]);
	ver[0] = build();
	for( int i = 1;  i <= n ; i++ ){
		cur = ver[i-1];
		if( last[exam[i]] == 0 )last[exam[i]] = i;
		else{
			cur = update( cur, last[exam[i]], 1 );
			last[exam[i]] = i;
		}
		cur = update( cur, i, 0 ); 
		ver[i] = cur;
	}
	scanf("%d",&q);
	for( int i = 0, l, r ; i < q ; i++ ){
		scanf("%d %d",&l,&r);
		l++, r++;
		int t = query( ver[r], l, r );
		// int t = 5;
		printf("%d\n",t);
	}
	return 0;
}