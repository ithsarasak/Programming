#include <bits/stdc++.h>
#include "teams.h"

using namespace std;

const int N = 5e5 + 10;
int chosen, pre[N], n, start;
vector<int> t, L, R, kid[N];

int newleaf( int va ) {
    t.emplace_back( va );
    L.emplace_back( -1 ), R.emplace_back( -1 );
    return t.size() - 1;
}

int newpar( int l, int r ) {
    t.emplace_back( t[l] + t[r] );
    L.emplace_back( l ), R.emplace_back( r );
    return t.size() - 1;
}

int build( int l = 0, int r = N-1 ) {
    if( l == r ) return newleaf( 0 );
    int mid = l + r >> 1;
    return newpar( build( l, mid ), build( mid+1, r ) );
}

int update( int x, int pv, int l = 0, int r = N-1 ) {
    if( l == r ) return newleaf( t[pv] + 1 );
    int mid = l + r >> 1;
    if( x <= mid ) return newpar( update( x, L[pv], l, mid ), R[pv] );
    else return newpar( L[pv], update( x, R[pv], mid+1, r ) );
}

int remove( int x, int pv, int ze, int l = 0, int r = N-1 ) {
    if( r <= x ) return ze;
    if( l > x ) return pv;
    int mid = l + r >> 1;
    return newpar( remove( x, L[pv], L[ze], l, mid ), remove( x, R[pv], R[ze], mid+1, r ) );
}

int choose( int k, int all, int cho, int l = 0, int r = N-1 ) {
    //printf("%d %d %d %d %d\n",k,all,cho,l,r);
    if( l == r ) return newleaf( t[cho] + k );
    int sum = t[L[all]] - t[L[cho]];
    int mid = l + r >> 1;
    if( sum < k ) return newpar( L[all], choose( k-sum, R[all], R[cho], mid+1, r ) );
    else return newpar( choose( k, L[all], L[cho], l, mid ), R[cho] );
}

int can( int m, int k[] ) {
    sort( k, k+m );
    int chosen = start;
    for( int i = 0 ; i < m ; i++ ) {
        chosen = remove( k[i]-1, chosen, pre[0] );
        if( t[pre[k[i]]] - t[chosen] < k[i] ) return 0;
        chosen = choose( k[i], pre[k[i]], chosen );
    }
    return 1;
}

void init( int _n, int a[], int b[] ) {
    n = _n;
    pre[0] = build();
    for( int i = 0 ; i < n ; i++ ) kid[a[i]].emplace_back( b[i] );
    for( int i = 1 ; i <= n ; i++ ) {
        pre[i] = remove( i-1, pre[i-1], pre[0] );
        for( int b : kid[i] ) pre[i] = update( b, pre[i] );
    }
    start = build();
}

/*int main()
{
    int n, m, a[100], b[100], k[100], q;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ) scanf("%d %d",&a[i],&b[i]);
    scanf("%d",&q);
    init( n, a, b );
    while( q-- ) {
        scanf("%d",&m);
        for( int i = 0 ; i < m ; i++ ) scanf("%d",&k[i]);
        printf("%d \n",can( m, k ));
    }
}*/