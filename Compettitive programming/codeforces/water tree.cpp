#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+100;
int fil[4*N], lz[4*N], em[4*N], n, ti, st[N], en[N], m;
vector<int> g[N];

void dfs( int now, int p ) {
    st[now] = ++ti;
    for( int i : g[now] ) if( i != p ){
        dfs( i, now );
    }
    en[now] = ti;
    return ;
}

void push( int now, int l, int r ) {
    if( !lz[now] ) return ;
    fil[now] = lz[now];
    if( l != r ) lz[now<<1] = lz[now<<1|1] = lz[now];
    lz[now] = 0;
    return ;
}

void filup( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
    push( now, l, r );
    if( l > rr || r < ll || l > r ) return ;
    if( l >= ll && r <= rr ) {
        fil[now] = m;
        if( l != r ) lz[now<<1] = lz[now<<1|1] = m;
        return ;
    }
    int mid = ( l + r ) >> 1;
    filup( ll, rr, l, mid, now<<1 ), filup( ll, rr, mid+1, r, now<<1|1 );
    fil[now] = min( fil[now<<1], fil[now<<1|1] );
    return ;
}

void emp( int idx, int l = 1, int r = n, int now = 1 ) {
    if( l > idx || r < idx || l > r ) return ;
    if( l == r ) {
        em[now] = m;
        return ;
    }
    int mid = ( l + r ) >> 1;
    emp( idx, l, mid, now<<1 ), emp( idx, mid+1, r, now<<1|1 );
    em[now] = min( em[now<<1], em[now<<1|1] );
    return ;
}

int filled( int idx, int l = 1, int r = n, int now = 1 ) {
    push( now, l, r );
    if( l > idx || r < idx || l > r ) return 1e9+100;
    if( l == r ) return fil[now];
    int mid = ( l + r ) >> 1;
    return min( filled( idx, l, mid, now<<1 ), filled( idx, mid+1, r, now<<1|1 ) );
}

int empt( int ll, int rr, int l = 1, int r = n, int now = 1 ) {
    push( now, l, r );
    if( l > rr || r < ll || l > r ) return 1e9+100;
    if( l >= ll && r <= rr ) return em[now];
    int mid = ( l + r ) >> 1;
    return min( empt( ll, rr, l, mid, now<<1 ), empt( ll, rr, mid+1, r, now<<1|1 ) );
}

int main()
{
    fill( fil, fil + 4*N, 1e9+10 ), fill( em, em + 4*N, 1e9+9 );
    scanf("%d",&n);
    for( int i = 0, u, v ; i < n - 1 ; i++ ) {
        scanf("%d %d",&u,&v);
        g[u].emplace_back( v ), g[v].emplace_back( u );
    }
    dfs( 1, 0 );
    // for( int i = 1 ; i <= n ; i++ ) printf("%d %d\n",st[i],en[i]);
    scanf("%d",&m);
    while( m-- ) {
        int a, b;
        scanf("%d %d",&a,&b);
        if( a == 1 ) filup( st[b], en[b] );
        else if( a == 2 ) emp( st[b] );
        else{
            int x = filled( st[b] ), y = empt( st[b], en[b] );
            // printf("%d %d %d %d %d\n",m,st[b],en[b],x,y);
            if( x < y ) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}