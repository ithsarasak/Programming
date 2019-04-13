#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

struct node {
    int pre, suf, mx, sum;
    node() { }
    node(int x) : pre(x), suf(x), mx(x), sum(x) { }
    friend node operator+(const node &a, const node &b) {
        node ret;
        ret.sum = a.sum + b.sum;
        ret.pre = max( a.pre, a.sum + b.pre );
        ret.suf = max( b.suf, b.sum + a.suf );
        ret.mx = max({ a.mx, b.mx, a.suf + b.pre });
        return ret;
    }
}seg[N<<2];

int n, m, house[N];

void build( int l = 1 , int r = n, int now = 1 ) {
    if( l == r ) return void( seg[now] = node(  house[l] ) );
    int mid = ( l + r ) >> 1;
    build(l, mid, now<<1), build(mid + 1, r, now<<1|1);
    return void( seg[now] = seg[now<<1] + seg[now<<1|1] );
}

void update( int idx, int va, int l = 1, int r = n, int now = 1 ) {
    if( l == r ) return void( seg[now] = node( va ) );
    int mid = ( l + r ) >> 1;
    if( idx <= mid ) update( idx, va, l, mid, now<<1 );
    else update( idx, va, mid+1, r, now<<1|1 );
    return void( seg[now] = seg[now<<1] + seg[now<<1|1] );
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ )scanf("%d",&house[i]);
    build();
    printf("%d\n",seg[1].mx);
    for( int i = 0, a, b ; i < m ; i++ ) {
        scanf("%d %d",&a,&b);
        a++;
        update( a, b );
        printf("%d\n",seg[1].mx);
    }
    return 0;
}