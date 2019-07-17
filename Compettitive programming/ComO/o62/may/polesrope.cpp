#include <bits/stdc++.h>

using namespace std;

struct item {
    long long va, sum, lz, ty, sz, prio;
    item *l, *r;
    item() { }
    item( int va ) : va( va ), sum( 0 ), ty( -1 ), lz( 0 ), sz( 1 ), prio( rand() ), l( nullptr ), r( nullptr ) { }
};
item* t;

int n, m;
long long sum( item* t ) { return t ? t->sum : 0; }
long long sz( item* t ) { return t ? t->sz : 0; }

void push( item *t ) {
    if( !t || !t->lz ) return ;
    t->sum += t->lz;
    if( t->lz > 0 || ( !t->r && !t->l ) ) {
        t->va += t->lz;
        t->lz = 0, t->ty = -1;
        return ;
    }
    if( t->ty == 0 ) {
        if( sum( t->r ) < -1*( t->lz ) ) {
            if( t->r ) {
                t->r->lz += -1*sum( t->r ), t->r->ty = t->ty;
            }
            if( t->va >= -1*( t->lz + sum( t->r ) ) ) t->va += t->lz + sum( t->r );
            else if( t->l ) {
                t->va += -1*t->va;
                t->l->lz += t->lz + t->va + sum( t->r ), t->l->ty = t->ty;
            }
        }
        else {
            t->r->lz += t->lz, t->r->ty = t->ty;
        }
    }
    else if( t->ty == 1 ) {
        if( sum( t->l ) < -1*( t->lz ) ) {
            if( t->l ) t->l->lz += -1*sum( t->l ), t->l->ty = t->ty;
            if( t->va >= -1*( t->lz + sum( t->l ) ) ) t->va += t->lz + sum( t->l );
            else if( t->r ) {
                t->va += -1*t->va;
                t->r->lz += t->lz + t->va + sum( t->l ), t->r->ty = t->ty;
            }
        }
        else t->l->lz += t->lz, t->l->ty = t->ty;
    }
    t->lz = 0, t->ty = -1;
}

void updt( item *t ) {
    if( !t ) return ;
    push( t );
    if( t->l ) push( t->l );
    if( t->r ) push( t->r );
    t->sz = sz( t->l ) + 1 + sz( t->r );
    t->sum = sum( t->l ) + t->va + sum( t->r );
}

void split( item* t, item* &l, item* &r, int pos, int add = 0 ) {
    push( t );
    if( !t ) return void( l = r = nullptr );
    int curpos = add + 1 + sz( t->l );
    if( pos >= curpos ) split( t->r, t->r, r, pos, curpos ), l = t;
    else split( t->l, l, t->l, pos, add ), r = t;
    updt( t );
}

void merge( item* &t, item* l, item* r ) {
    push( l ), push( r );
    if( !l || !r ) t = l ? l : r ;
    else if( l->prio < r->prio ) merge( l->r, l->r, r ), t = l;
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
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n - 1 ; i++ ) merge( t, t, new item( 10 ) );
    //print( t );
    //printf("\n");
    while( m-- ) {
        int tt, a, b;
        scanf("%d %d",&tt,&a);
        if( tt == 1 ) {
            scanf("%d",&b);
            //cout << b << endl;
            int pull = b / 2, pulll = 0, pullr = 0, nr = 0, nl = 0; 
            item *l, *r;
            l = r = nullptr;
            //cout <<"hye";
            split( t, t, r, a );
            //print( t );
            //printf("\n");
            //print( r );
            //printf("\n%d\n",t->sum);
            if( a != 1 ) split( t, l, t, a-1 );
            //printf("%d\n",t->sum);
            //print( l );
            if( a != 1 ) nl = l->sum;
            if( a != n - 1 ) nr = r->sum;
            if( pull > nl ) pulll = nl, pullr = b - nl;
            else if( pull > nr ) pullr = nr, pulll = b - nr;
            else pulll = pull, pullr = pull;
            //cout << "uuu";
            if( a != 1 ) l->lz += -1*pulll, l->ty = 0;
            if( a != n - 1 ) r->lz += -1*pullr, r->ty = 1;
            t->lz += b, t->ty = 2;
            //push( t );
            //if( a != 1 && l->r ) cout << l->va << endl << l->lz << endl << l->r->va << endl;
            //print( l ); cout << endl; print( t ); cout << endl; print( r );
            cout << pullr << endl;
            //printf("\n");
            //printf("\n");
            //print( t );
            //printf("\n");
            //cout << " hh";
            merge( t, l, t );
            //print( t );
            merge( t, t, r );
        }
        else {
            item *l, *r;
            l = r = nullptr;
            split( t, t, r, a );
            //print( t );
            //printf("\n");
            if( a != 1 ) split( t, l, t, a - 1 );
            // print( l );
            // printf("\n");
            // print( t );
            // printf("\n");
            // print( r );
            // printf("\n");
            push( t );
            printf("%d\n",t->va);
            merge( t, l, t ), merge( t, t, r );
        }
        print( t );
        printf("\n");
    }
    return 0;
}