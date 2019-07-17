#include <bits/stdc++.h>

using namespace std;

struct item {
	int num, prio, lz, sz;
	item *l, *r;
	item() {}
	item( int num ) : num( num ), prio( rand() ), lz( 0 ), sz( 1 ), l( nullptr ), r( nullptr ) {}  
};
item* t;
int n, q;

int sz( item* t ) { return t ? t->sz : 0; }

void updt( item* t ) { if( t ) t->sz = sz( t->l ) + 1 + sz( t->r ); }

void push( item* t ) {
	if( !t || !t->lz ) return ;
	swap( t->l, t->r );
	if( t->l ) t->l->lz ^= 1;
	if( t->r ) t->r->lz ^= 1;
	t->lz = 0;
	return ;
}
void split( item* t, item* &l, item* &r, int pos, int add = 0 ) {
	push( t );
	if( !t ) return void( l = r = nullptr );
	int cur_pos = add + 1 + sz( t->l );
	if( pos >= cur_pos ) split( t->r, t->r, r, pos, cur_pos ), l = t;
	else split( t->l, l, t->l, pos, add ), r = t;
	updt( t );
	return ;
}

void merge( item* &t, item* l, item* r ) {
	push( l ), push( r );
	if( !l || !r ) return void( t = l ? l : r );
	if( l->prio < r->prio ) merge( l->r, l->r, r ), t = l;
	else merge( r->l, l, r->l ), t = r;
	updt( t ); 
	return ;
}

int main()
{
	scanf("%d %d",&n,&q);
	for( int i = 1, num ; i <= n ; i++ ) {
		scanf("%d",&num);
		merge( t, t, new item( num ) );
	}
	for( int i = 0, x, y ; i < q ; i++ ) {
		char c;
		item *mid, *mid2, *r, *r2;
		scanf(" %c %d",&c,&x);
		if( c == 'a' ) {
			scanf("%d",&y);
			if( x == y ) continue;
			if( x > y ) swap( x, y );
			split( t, t, r, y ), split( t, t, mid, y-1 );
			split( t, t, r2, x ), split( t, t, mid2, x-1 );
			merge( t, t, mid ), merge( t, t, r2 );
			merge( t, t, mid2 ), merge( t, t, r );
		}
		else if( c == 'b' ) {
			scanf("%d",&y);
			split( t, t, r, x ), split( t, t, mid, x-1 );
			mid->num = y;
			merge( t, t, mid ), merge( t, t, r );
		}
		else if( c == 'c' ) {
			split( t, t, r, x );
			t->lz ^= 1, r->lz ^= 1;
			merge( t, t, r );
		}
		else {
			split( t, t, r, x ), split( t, t, mid, x-1 );
			printf("%d\n",mid->num);
			merge( t, t, mid ), merge( t, t, r ); 
		}
	}
	return 0;
}