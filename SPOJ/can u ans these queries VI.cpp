#include <bits/stdc++.h>

using namespace std;

struct dataa{
	int pre, suf, mx, sum;
	dataa() {}
	dataa( int d ) : pre( d ), suf( d ), mx( d ), sum( d ) {} 
	dataa( int pre, int suf, int mx, int sum ) : pre( pre ), suf( suf ), mx( mx ), sum( sum ) {} 
	friend dataa operator+( const dataa &a, const dataa &b ) {
		dataa ret;
		ret.pre = max( a.pre, a.sum + b.pre );
		ret.suf = max( b.suf, a.suf + b.sum );
		ret.mx = max({ a.mx, b.mx, a.suf + b.pre });
		ret.sum = a.sum + b.sum;
		return ret;
	}
};

struct item{
	dataa d, data;
	int prio, sz;
	item *l, *r;
	item() {} 
	item( dataa d ) : d( d ), data( d ), prio( rand() ), sz( 1 ), l( nullptr ), r( nullptr ) {};	
};

int n, q;
item* t;

int sz( item* t ) { return t ? t->sz : 0; }
dataa data( item *t ) { return t ? t->data : dataa( -1e9, -1e9, -1e9, 0 ); }

void updt( item* t ) {
	if( !t ) return ;
	t->sz = sz( t->l ) + sz( t->r ) + 1;
	t->data = data( t->l ) + t->d + data( t->r );
	return ;
}

void split( item* t, item* &l, item* &r, int pos, int add = 0 ) {
	if( !t ) return void( l = r = nullptr );
	int cur_pos = add + sz( t->l ) + 1;
	if( pos >= cur_pos )split( t->r, t->r, r, pos, cur_pos ), l = t;
	else split( t->l, l, t->l, pos, add ), r = t;
	updt( t );
}

void merge( item* &t, item* l, item* r ) {
	if( !l || !r ) return void( t = l ? l : r );
	if( l->prio < r->prio )merge( l->r, l->r, r ), t = l;
	else merge( r->l, l, r->l ), t = r;
	updt( t );
}

// void print( item* t ) {
// 	if( !t )return ;
// 	print( t->l );
// 	printf("%d ",t->va);
// 	print( t->r );
// 	return ;
// }
int main()
{
	scanf("%d",&n);
	 for( int i = 1, te ; i <= n ; i++ ) {
	 	scanf("%d",&te);
	 	merge( t, t, new item( dataa( te ) ) );
	 }
	 scanf("%d",&q);
	 while( q-- ) {
	 	char op;
	 	int x, y;
	 	scanf(" %c %d",&op,&x);
	 	if( op == 'I' ) {
	 		scanf("%d",&y);
	 		item* r;
	 		split( t, t, r, x - 1 );
	 		merge( t, t, new item( dataa( y ) ) );
	 		merge( t, t, r );
	 	}
	 	else if( op == 'D' ) {
	 		item *l, *r;
	 		split( t, t, r, x );
	 		split( t, t, l, x-1 );
	 		merge( t, t, r );
	 	}
	 	else if( op == 'R' ) {
	 		scanf("%d",&y);
	 		item *l, *r;
	 		split( t, t, r, x );
	 		split( t, t, l, x-1 );
	 		merge( t, t, new item( dataa( y ) ) );
	 		merge( t, t, r );
	 	}
	 	else {
	 		scanf("%d",&y);
	 		item *mid, *r;
	 		split( t, t, r, y );
	 		split( t, t, mid, x-1 );
	 		// print( mid );
	 		// printf("\n");
	 		int ans = mid->data.mx;
	 		merge( t, t, mid );
	 		merge( t, t, r );
	 		printf("%d\n",ans);
	 	}
	 }
	return 0;
}