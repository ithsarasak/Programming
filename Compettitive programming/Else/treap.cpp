#include <bits/stdc++.h>

using namespace std;

struct item {
    int va, prio;
    item *l, *r;
    item() { }
    item( int va ) : va( va ), prio( rand() ), l( nullptr ), r( nullptr ) {}
}

item *t;
void split( item* t, item* &l, item* &r, int pos, int add = 0 ) {
    if( !t ) return void( l = r = nullptr );
    int cur_pos = add + sz( t->l ) + 1;
    if( pos >= cur_pos ) split( t->r, t->r, r, pos, cur_pos ), l = t;
    else split( t->l, l, t->r, pos, add ) r = t;
}

void merge( item* &t, item* l, item* r ) {
    if( !l || !r ) return void( t = l ? l : r );
    if( l->prio > r->prio ) merge( l->r, l->r, r ), t = l;
    else merge( r->l, l, r->l ) t = r;
}
int main()
{
    return 0
}