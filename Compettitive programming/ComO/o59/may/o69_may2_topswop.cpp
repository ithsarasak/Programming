#include <bits/stdc++.h>

using namespace std;

struct item {
    int va, sz, prio, lz;
    item *l, *r;
    item() { }
    item( int va ) : va( va ), sz( 1 ), lz( 0 ), prio( rand() ), l( nullptr ), r( nullptr ) { }
};
item *t;

int n, ans;

void push( item* t ) {
    if( !t || !t->lz ) return ;
    swap( t->l, t->r );
    if( t->l ) t->l->lz ^= 1;
    if( t->r ) t->r->lz ^= 1;
    t->lz = 0;
    return ;
}

int sz( item* t ) { return t ? t->sz : 0; }

void updt( item* t ) {
    if( !t ) return ;
    push( t );
    if( t->l ) push( t->l );
    if( t->r ) push( t->r );
    t->sz = sz( t->l ) + 1 + sz( t->r );
}

void split( item* t, item* &l, item* &r, int add, int pos ) {
    push( t );
    if( !t ) return void( l = r = nullptr );
    int curpos = add + sz( t->l ) + 1;
    if( pos >= curpos ) split( t->r, t->r, r, curpos, pos ), l = t;
    else split( t->l, l, t->l, add, pos ), r = t;  
    updt( t );
}

void merge( item* &t, item* l, item* r ) {
    push( l ), push( r );
    if( !l || !r ) return void( t = l ? l : r );
    if( l->prio < r->prio ) merge( l->r, l->r, r ), t = l;
    else merge( r->l, l, r->l ), t = r;
    updt( t );
}

void print( item* t ) {
    push( t );
    if( !t ) return ;
    print( t->l );
    printf("%d ",t->va);
    print( t->r );
}

int main()
{  
    scanf("%d",&n);
    for( int i = 1, a ; i <= n ; i++ ) {
        scanf("%d",&a);
        merge( t, t, new item( a ) );
    }
    while( 1 ) {
        item* r;
        split( t, t, r, 0, 1 );
        if( t->va == 1 ) break;
        int k = t->va;
        merge( t, t, r );

        split( t, t, r, 0, k );
        t->lz ^= 1;
        merge( t, t, r );
        ans++;
    }
    printf("%d",ans);
    return 0;
}