#include <bits/stdc++.h>

using namespace std;

struct item{
	int va, sz, prio;
	item *l, *r;
	item() { }
	item( int va ) : va( va ), sz( 1 ), prio( rand() ), l( nullptr ), r ( nullptr ) {}
};

const int N = 1e5+100;
int n, m, lego[N];
item* t;

int sz( item* t ) { return t ? t->sz : 0 ; }

void updt( item* t ) { if( t ) t->sz = sz( t->l ) + 1 + sz( t->r ); }

void split( item* t, item* &l, item* &r, int pos, int add = 0 ) {
	if( !t ) return void( l = r = nullptr );
	int cur_pos = add + sz( t->l ) + 1;
	if( pos >= cur_pos ) split( t->r, t->r, r, pos, cur_pos ), l = t;
	else split( t->l, l, t->l, pos, add ), r = t;
	updt( t );
}

void merge( item* &t, item*l, item*r ) {
	if( !l || !r ) return void( t = l ? l : r );
	if( l->prio < r->prio ) merge( l->r, l->r, r ), t = l;
	else merge( r->l, l, r->l ), t = r;
	updt( t );
}

int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) scanf("%d",&lego[i]);
	for( int i = 1 ; i <= n ; i++ ) merge( t, t, new item( lego[i] ) );
	while( m-- ) {
		int op, a, b, L;
		scanf("%d %d",&op,&a);
		if( op == 1 ) {
			scanf("%d %d",&L,&b);
			item *l, *r, *r2;
			if( a > b ){
				split( t, t, r2, a+L-1 );
				split( t, t, r, a-1 );
				split( t, t, l, b-1 );
				merge( t, t, r );
				merge( t, t, l );
				merge( t, t, r2 );
				
			} else{
				split( t, t, r2, b-1 );
				split( t, t, r, a+L-1 );
				split( t, t, l, a-1 );
				merge( t, t, r );
				merge( t, t, l );
				merge( t, t, r2 );
			}
		} else{
			item *l, *r;
			split( t, t, r, a );	
			split( t, l, t, a-1 );
			printf("%d\n",t->va);
			merge( t, l, t );
			merge( t, t, r );
		}
	}
	return 0;
}