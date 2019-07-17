#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define x first 
#define y second 

using namespace std;

const int N = 2e5 + 10;

struct item {
    long long sum;
    int sz;
    item *l, *r;
    item() { }
    item( long long sum, int sz, item *l, item *r ) : sum( sum ), sz( sz ), l( l ), r( r ) { }  
};

item* newleaf( long long va, int sz ) {
    return new item( va, sz, nullptr, nullptr );
}

item* newpar( item *l, item *r ) {
    return new item( l->sum + r->sum, l->sz + r->sz, l, r );
}

int n, m;
item* ver[N];
pll cake[N];
long long last[N], ret = -2000000000000000;
vector<long long> v;
unordered_map<long long, int> mp;

int get( long long x ) { 
    mp[x]++;
    return lower_bound( v.begin(), v.end(), x ) - v.begin() + mp[x];
}

item* build( int l = 1, int r = v.size() ) {
    if( l == r ) return newleaf( 0, 0 );
    int mid = ( l + r ) >> 1;
    return newpar( build( l, mid ), build( mid + 1, r ) );
}

item* update( int idx, item* p, long long va, int l = 1, int r = v.size() ) {
    if( l == r ) return newleaf( va, 1 );
    int mid = ( l + r ) >> 1;
    if( idx <= mid ) return newpar( update( idx, p->l, va, l, mid ), p->r );
    else return newpar( p->l, update( idx, p->r, va, mid + 1, r ) );
}

long long query( item *a, item *b, int idx, int l = 1, int r = v.size() ) {
    if( idx == 0 ) return 0LL;
    if( l == r ) return b->sum - a->sum;
    int mid = ( l + r ) >> 1;
    int diff = b->r->sz - a->r->sz;
    //printf("L : %d R : %d diff : %d\n",l,r,diff);
    if( diff >= idx ) return query( a->r, b->r, idx, mid + 1, r );
    else return b->r->sum - a->r->sum + query( a->l, b->l, idx - diff, l, mid );
}

void solve( int l, int r, int lb, int rb ) {
    if( l > r ) return ;
    int nb = lb, mid = ( l + r ) >> 1;
    for( int i = max( mid + m - 1, lb ) ; i <= rb ; i++ ) {
        long long cur = query( ver[mid], ver[i-1], m - 2 ) + cake[i].y - 2LL*cake[i].x + cake[mid].y + 2LL * cake[mid].x;
        //if( mid == 1 ) printf("temp : %lld i : %d cur : %lld\n",temp,i,cur);
        if( cur > last[mid] ) nb = i, last[mid] = cur;
    }
    solve( l, mid - 1, lb, nb ), solve( mid + 1, r, nb, rb );
}

int main()
{
    fill( last, last + N, -2000000000000000 );
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%lld %lld",&cake[i].y,&cake[i].x);
        v.emplace_back( cake[i].y );
    }
    sort( cake + 1, cake + 1 + n );
    sort( v.begin(), v.end() );
    //printf("\n");
    //for( int i = 1 ; i <= n ; i++ ) printf("%lld %lld\n",cake[i].y,cake[i].x);
    //printf("\n");
    ver[0] = build();
    for( int i = 1 ; i <= n ; i++ ) ver[i] = update( get( cake[i].y ), ver[i-1], cake[i].y );
    //printf("lld\n")
    //printf("%lld\n",ver[6]->sum);
    solve( 1, n - m + 1, 1, n );
    //printf("SEND HELP");
    for( int i = 1 ; i <= n - m + 1 ; i++ ) ret = max( ret, last[i] );
    //for( int i = 1 ; i <= n - m + 1 ; i++ ) printf("%lld ",last[i]);
    //printf("\n");
    printf("%lld",ret);
    return 0;
}
