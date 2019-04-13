#include <bits/stdc++.h>

using namespace std;

struct item{
	int sum, va, prior, sz, lz;
	item *l, *r;
	item() {}
	item( int va ) : sum( va ), va( va ), prior( rand() ), lz( 0 ), sz( 1 ), l( nullptr ), r( nullptr ) {} 
};

int n, q;
item* t;

int sz( item* t ) { return t ? t->sz : 0; }
int sum( item* t ) { return t ? t->sum : 0; } 

void updt( item* t ){ 
	if( !t ) return ; 
	t->sz = sz( t->l ) + 1 + sz( t->r ); 
	t->sum = t->va + sum( t->l ) + sum( t->r );
	return ;
}

void push( item* t ) {
	if( !t || !t->lz ) return ;
	t->sum += t->sz * t->lz;
	t->va += t->lz;
	if( t->l ) t->l->lz += t->lz;
	if( t->r ) t->r->lz += t->lz;
	t->lz = 0;
	return ;
}

void split( item* t, item* &l, item* &r, int val ) {
	push( t );
	if( !t ) return void( l = r = nullptr );
	if( t->va < val ) split( t->r, t->r, r, val ), l = t;
	else split( t->l, l, t->l, val), r = t;
	updt( t );
}

void merge( item* &t, item* l, item* r ) {
	push( l ), push( r );
	if( !l || !r ) return void( t = l ? l : r );
	if( l->prior < r->prior ) merge( l->r, l->r, r ), t = l;
	else merge( r->l, l, r->l ), t = r;
	updt( t );
}

bool find( item* t, int val ) {
	push( t );
	if( !t ) return 0;
	if( t->va == val ) return 1;
	else if( t->va > val ) return find( t->l, val );
	else return find( t->r, val );
}

// void print( item* t ) {
// 	push( t );
// 	if( !t ) return ;
// 	print( t->l );
// 	printf("%d ",t->va);
// 	print( t->r );
// 	return ;
// }

int main()
{
	scanf("%d %d",&n,&q);
	for( int i = 1, te ; i <= n ; i++ ) {
		scanf("%d",&te);
		merge( t, t, new item( te ) );	
	}
	while( q-- ) {
		int op, num, b, c;
		scanf("%d %d",&op,&num);
		if( op == 1 ) {
			if( find( t, num ) ) printf("1\n");
			else printf("0\n");
		}
		else {
			item* r;
			scanf("%d %d",&b,&c);
			if( !find( t, num ) ) continue;
			split( t, t, r, num );
			if(t) t->lz += b;
			if(r) r->lz += c;
			merge( t, r, t );
		}
		// print( t );
		// printf("\n");
	}
	return 0;
}