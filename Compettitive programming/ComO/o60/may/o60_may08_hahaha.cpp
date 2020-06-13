#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct item {
    int sz, prio, val, lz, st, cnt[5];
    long long inv, inc;
    item *l, *r;
    item() { }
    item( int val ) : sz(1), prio(rand()), val(val), lz(0), st(0), inv(0), inc(0), l(NULL), r(NULL) {
        memset( cnt, 0, sizeof cnt );
        cnt[val] = 1;
    }
};

item* t;

int sz( item* t ) { return t ? t->sz : 0; }
long long inv( item* t ) { return t ? t->inv : 0; }
long long inc( item* t ) { return t ? t->inc : 0; }

void updt( item* t ) {
    if( !t ) return ;
    t->sz = sz( t->l ) + 1 + sz( t->r );
    t->inv = inv( t->l ) + inv( t->r );
    t->inc = inc( t->l ) + inc( t->r );
    memset( t->cnt, 0, sizeof t->cnt );
    t->cnt[t->val] = 1;
    if( t->l ) {
        for( int i = 0 ; i < 5 ; i++ ) t->cnt[i] += t->l->cnt[i];
        for( int i = t->val + 1 ; i < 5 ; i++ ) t->inv += t->l->cnt[i];
        for( int i = 0 ; i < t->val ; i++ ) t->inc += t->l->cnt[i];
    }
    if( t->r ) {
        for( int i = 0 ; i < 5 ; i++ ) t->cnt[i] += t->r->cnt[i];
        for( int i = 0 ; i < t->val ; i++ ) t->inv += t->r->cnt[i];
        for( int i = t->val+1 ; i < 5 ; i++ ) t->inc += t->r->cnt[i];
    }
    if( t->l && t->r ) {
        for( int i = 0 ; i < 5 ; i++ ) for( int j = 0 ; j < i ; j++ ) t->inv += t->l->cnt[i] * t->r->cnt[j];
        for( int i = 0 ; i < 5 ; i++ ) for( int j = i+1 ; j < 5 ; j++ ) t->inc += t->l->cnt[i] * t->r->cnt[j]; 
    }
    //printf("%d %lld %lld\n",t->val,t->inv,t->inc);
}

void push( item* t ) {
    if( !t || !t->st ) return ;
    if( t->st == 1 ) {
        swap( t->l, t->r );
        if( t->l && t->l->st != 2 ) {
            t->l->st ^= 1;
            swap( t->l->inv, t->l->inc );
        }
        if( t->r && t->r->st != 2 ) {
            t->r->st ^= 1;
            swap( t->r->inv, t->r->inc );
        }
    }
    else if( t->st == 2 ) {
        t->val = t->lz;
        //printf("%d\n",t->val);
        //printf("LZ : %d\n",t->lz);
        if( t->l ) {
           // printf("L : %d\n",t->l->val);
            t->l->st = 2, t->l->lz = t->lz;
            t->l->inv = t->l->inc = 0;
            memset( t->l->cnt, 0, sizeof t->l->cnt );
            t->l->cnt[t->lz] = t->l->sz;
        }
        if( t->r ) {
            //printf("R : %d\n",t->r->val);
            t->r->st = 2, t->r->lz = t->lz;
            t->r->inv = t->r->inc = 0;
            memset( t->r->cnt, 0, sizeof t->r->cnt );
            t->r->cnt[t->lz] = t->r->sz;
        }
    }
    t->st = t->lz = 0;
    updt( t );
}

void split( item* t, item* &l, item* &r, int pos, int add = 0 ) {
    push( t );
    if( !t ) return void( l = r = NULL );
    int now = add + sz( t->l ) + 1;
    //printf("%d %d %d NOW : %d\n",t->val,pos,add,now);
    if( now <= pos ) split( t->r, t->r, r, pos, now ), l = t;
    else split( t->l, l, t->l, pos, add ), r = t;
    updt( t );
}

void merge( item* &t, item* l, item* r ) {
    push( l ), push( r );
    if( !l || !r ) return void( t = l ? l : r );
    if( l->prio < r->prio ) merge( l->r, l->r, r ), t = l;
    else merge( r->l, l, r->l ), t = r;
    updt( t );
}

/*void print( item* t ) {
    push( t );
    if( !t ) return ;
    print( t->l );
    printf("%d ",t->val);
    print( t->r );
}*/

int n, q;
char s[N];
int main()
{
    scanf("%d %d",&n,&q);
    scanf("%s",&s[1]);
    for( int i = 1 ; i <= n ; i++ ) merge( t, t, new item( s[i] - '0' ) );
    while( q-- ) {
        int tt, a, b, c;
        item *l, *r;
        scanf("%d %d %d",&tt,&a,&b);
        if( tt == 1 ) {
            scanf("%d",&c);
            split( t, t, r, b ), split( t, t, l, a-1 );
            l->st = 2, l->lz = c;
            merge( t, t, l ), merge( t, t, r );
        }
        else if( tt == 2 ) {
            split( t, t, r, b ), split( t, t, l, a-1 );
            if( l->st != 2 ) l->st ^= 1;
            merge( t, t, l ), merge( t, t, r );
        }
        else {
            split( t, t, r, b );
            split( t, t, l, a-1 ); 
            printf("%lld\n",l->inv);
            merge( t, t, l ), merge( t, t, r );
        }
    }
    return 0;
} 