#include <bits/stdc++.h>
#define long long long

using namespace std;

const int N = 1e5 + 10;

struct item {
    int sz, prio;
    long d, sum;
    item *l, *r;
    item( long d ) : d(d), sum(d), sz(1), l(nullptr), r(nullptr), prio( rand() ) { }
};

item *t[N];
int n, q, w, h;

int sz( item* t ) { return t ? t->sz : 0; }
long sum( item* t ) { return t ? t->sum : 0LL; }

void updt( item* t ) {
    if( !t ) return ;
    t->sz = sz(t->l) + 1 + sz(t->r);
    t->sum = sum(t->l) + t->d + sum(t->r);
}

void split( item *t, item* &l, item* &r, long pos ) {
    if( !t ) return void( l = r = nullptr );
    if( t->d <= pos ) split( t->r, t->r, r, pos ), l = t;
    else split( t->l, l, t->l, pos ), r = t;
    updt( t );
}

void merge( item* &t, item* l, item* r ) {
    if( !l || !r ) return void( t = l ? l : r );
    if( l->prio < r->prio ) merge( l->r, l->r, r ), t = l;
    else merge( r->l, l, r->l ), t = r;
    updt( t );
}

void update( int x, long y ) {
    for( int i = x ; i <= w ; i += i & -i ) {
        item *r;
        split( t[i], t[i], r, y );
        merge( t[i], t[i], new item( y ) );
        merge( t[i], t[i], r );
    }
}

long query( int x, long b, long d ) {
    long ret = 0;
    for( int i = x ; i ; i -= i & -i ) {
        item *l, *r;
        split( t[i], t[i], r, d ), split( t[i], l, t[i], b );
        ret += sz(r)*(d-b) + sum(t[i]) - (b*sz(t[i]));
        merge( t[i], l, t[i] ), merge( t[i], t[i], r );
    }
    return ret;
}

int main()
{
    scanf("%d %d %d %d",&n,&q,&w,&h);
    ++w, ++h, q += n;
    for( int i = 1, t ; i <= q ; i++ ) {
        long a, b, c, d;
        scanf("%d %lld %lld",&t,&a,&b);
        a++;
        if( t == 1 ) update( a, b );
        else {
            scanf("%lld %lld",&c,&d);
            c++;
            printf("%lld\n",query(c, b, d) - query( a-1, b, d ) );
        }
    }
    return 0;
}