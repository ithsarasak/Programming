#include <bits/stdc++.h>

using namespace std;

struct item {
    long long va, now, sum, mx, lz, sz, prio, ai;
    item *l, *r;
    item() { }
    item( long long va, long long now, long long ai ) : va( va ), now( now ), ai( ai ), sum( 0 ), mx( now ), lz( 0 ), sz( 1 ), prio( rand() ), l( nullptr ), r( nullptr ) { }
};
item* t;
long long n, test, m1, m2, ans;

void push( item *t ) {
    if( !t || !t->lz ) return ;
    t->mx += t->lz, t->now += t->lz;
    if( t->r ) t->r->lz += t->lz;
    if( t->l ) t->l->lz += t->lz;
    t->lz = 0;
}

long long sum( item* t ) { return t ? t->sum : 0; }
long long sz( item* t ) { return t ? t->sz : 0; }
long long mx( item* t ){ return t ? t->mx : 0; }

void updt( item *t ) {
    if( !t ) return ;
    push( t );
    if( t->l ) push( t->l );
    if( t->r ) push( t->r );
    t->sz = sz( t->l ) + 1 + sz( t->r );
    t->mx = max( mx( t->l ), max( mx( t->r ), t->now ) );
    t->sum = sum( t->l ) + t->ai + sum( t->r );
}

void split( item* t, item* &l, item* &r, long long va ) {
    push( t );
    if( !t ) l = r = nullptr;
    else if( va <= t->va ) split( t->r, t->r, r, va ), l = t;
    else split( t->l, l, t->l, va ), r = t;
    updt( t );
}

void merge( item* &t, item* l, item* r ) {
    push( l ), push( r );
    if( !l || !r ) t = l ? l : r ;
    else if( l->prio < r->prio ) merge( l->r, l->r, r ), t = l;
    else merge( r->l, l, r->l ), t = r;
    updt( t ); 
}

int main()
{
    scanf("%lld %lld %lld %lld",&n,&test,&m1,&m2);
    for( long long i = 1, a, b ; i <= n ; i++ ) {
        scanf("%lld %lld",&a,&b);
        if( test == 2 ) a = a + ( ans % m1 ), b = b + ( ans % m2 );
        item* r = nullptr;
        split( t, t, r, b );
        if( r ) r->lz += a;
        merge( t, t, new item( b, sum( t ) + a + b, a ) ); 
        merge( t, t, r );
        ans = t->mx;
        printf("%lld\n",ans);
    }
    return 0;
}