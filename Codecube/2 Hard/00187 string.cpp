#include <bits/stdc++.h>

using namespace std;

struct item{
	char c;
	int lz, prior, sz;
	item* l;
	item* r;
	item() { }
	item( char c ) : c( c ), lz( 0 ), prior( rand() ), sz( 1 ), l( NULL ), r( NULL ) { } 
};

const int N = 1e5+100;
char s[N];
int m;
item* t;

int siz( item* t ){ return t ? t->sz : 0; }

void updt( item* t ) { if( t ) t->sz = siz( t->l ) + siz( t->r ) + 1; }

void push( item* t ) {
	if( !t || !t->lz )return ;
	swap( t->l, t->r );
	if( t->l ) t->l->lz ^= 1;
	if( t->r ) t->r->lz ^= 1;
	t->lz = 0;
	return ;
}

void split( item* t, item* &l, item* &r, int pos, int add = 0 ) {
	push( t );
	if( !t ) return void( l = r = NULL );
	int cur_pos = add + siz( t-> l ) + 1;
	if( pos >= cur_pos ) split( t->r, t->r, r, pos, cur_pos ), l = t;
	else split( t->l, l, t->l, pos, add ), r = t;
	updt( t );
}

void merge( item* &t, item* l, item* r ) {
	push( l ), push( r );
	if( !l || !r )return void( t = l ? l : r );
	else if( l->prior < r->prior ) merge( l->r, l->r, r ), t = l;
	else merge( r->l, l, r->l ), t = r;
	updt( t );
} 

void print( item* t ) {
	push( t );
	if( !t ) return;
	print( t->l );
	printf("%c",t->c);
	print( t->r );
	return ;
}

int main()
{
	scanf(" %s %d",s+1,&m);
	for( int i = 1 ; s[i] ; i++ ) merge( t, t, new item( s[i] ) );
	while( m-- ) {
		int a, b;
		char k[N], op;
		scanf(" %c %d",&op,&a);
		if( op == 'R' ) {
			scanf("%d",&b);
			item* l;
			item* r;
			split( t, t, r, b );
			split( t, l, t, a-1 );
			t->lz ^= 1;
			merge( t, t, r );
			merge( t, l, t );
		} else{
			scanf(" %s",k+1);
			item *r;
			split( t, t, r, a );
			for( int i = 1 ; k[i] ; i++ ) merge( t, t, new item( k[i] ) );
			merge( t, t, r );
		}
		//print(t);
	}
	print( t );
	printf("\n");
	return 0;
}
