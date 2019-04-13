#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 2e5+100;
const long base = 1e9+7;
struct item{
	long sz, prio, hash1, hash2, me, lz;
	item *l, *r;
	item() {} 
	item( int me ) : sz( 1 ), prio( rand() ), hash1( me ), hash2( me ), me( me ), lz( 0 ), l( nullptr ), r( nullptr ) {} 
};

int n, m;
char s[N];
item* t;
long po[N];

int sz( item* t ) { return t ? t->sz : 0 ; }
long hash1( item* t ) { return t ? t->hash1 : 0; }
long hash2( item* t ) { return t ? t->hash2 : 0; }

void updt( item* t ) {
	if( !t ) return ;
	t->hash1 = hash1( t->l ) + po[sz(t->l)]*t->me + po[sz( t->l )+1]* hash1( t->r );
	t->hash2 = hash2( t->r ) + po[sz(t->r)]*t->me + po[sz( t->r )+1]* hash2( t->l );
	t->sz = sz( t->l ) + 1 + sz( t->r );
	return ;
}

void push( item* t ) {
	if( !t || !t->lz ) return ;
	swap( t->l, t->r );
	if( t->l ) t->l->lz ^= 1, swap( t->l->hash1, t->l->hash2 );
	if( t->r ) t->r->lz ^= 1, swap( t->r->hash1, t->r->hash2 );
	t->lz = 0;
	return ;
}

void split( item* t, item* &l, item* &r, int pos, int add = 0 ) {
	push( t );
	if( !t ) return void( l = r = nullptr );
	int cur_pos = add + 1 + sz( t->l );
	if( pos >= cur_pos )split( t->r, t->r, r, pos, cur_pos ), l = t;
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
	po[0] = 1;
	for( int i = 1 ; i < N ; i++ )po[i] = po[i-1] * base;
	scanf("%d %d",&n,&m);
	scanf("%s",&s[1]);
	for( int i = 1 ; s[i] ; i++ ) merge( t, t, new item( s[i]-'a'+1 ) );
	while( m-- ) {
		char op, c;
		int i, j, k, ty;
		item *l, *mid, *r, *temp;
		scanf(" %c %d %d",&op,&ty 	,&i);
		if( op == 'Q' ) {
			split( t, t, r, i );
			split( t, t, mid, ty - 1 );
			if( mid->hash1 == mid->hash2 )printf("YES\n");
			else printf("NO\n");
			merge( t, t, mid );
			merge( t, t, r );
		}
		else if( op == 'M' && ty == 1 ) {
			scanf("%d %d",&j,&k);
			split( t, t, r, j );
			split( t, t, mid, i-1 );
			merge( t, t, r );
			split( t, t, temp, k );
			merge( t, t, mid );
			merge( t, t, temp );
		}
		else if( op == 'M' && ty == 2 ) {
			scanf("%d",&j);
			split( t, t, r, j );
			split( t, t, mid, i-1 );
			mid->lz ^= 1;
			merge( t, t, mid );
			merge( t, t, r );
		}
		else{
			scanf(" %c",&c);
			split( t, t, r, i-1 );
			merge( t, t, new item( c-'a'+1 ) );
			merge( t, t, r );
		}
	}
	return 0;
}
