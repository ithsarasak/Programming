#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, q, dis[N], in[N], out[N], ti, cnt, seg[4*N], lz[4*N], arr[N];
vector<int> ans, g[N];

void pre( int now, int p ) {
    dis[now] = dis[p] + 1;
    arr[++cnt] = now, in[now] = ++ti;
    for( int i : g[now] ) if( i != p ) pre( i, now );
    out[now] = ti;
}

void push( int now, int l, int r ) {
    if( !lz[now] ) return;
    seg[now] += lz[now];
    if( l != r ) lz[now<<1] += lz[now], lz[now<<1|1] += lz[now];
    lz[now] = 0;
    return ;
}

void build( int l = 1, int r = cnt, int now = 1 ) {
    if( l == r ) return void( seg[now] = dis[arr[l]] );
    int mid = ( l + r ) >> 1;
    build( l, mid, now << 1 ), build( mid + 1, r, now << 1 | 1 );
    seg[now] = max( seg[now<<1], seg[now<<1|1] );
    return ;
}

void update( int ll, int rr, int va, int l = 1, int r = 1, int now = 1 ) {
    push( now, l, r );
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz[now] -= va;
        push( now, l, r );
        return ;
    }
    int mid = ( l + r ) >> 1;
    update( ll, rr, va, l, mid, now << 1 ), update( ll, rr, va, mid + 1, r, now << 1 | 1 );
    seg[now] = max( seg[now<<1], seg[now<<1|1] );
    return ;
}

vector<int> getRadius( int N, int Q, int u[], int v[], int a[] ) {
    n = N, q = Q;
    for( int i = 0 ; i < n - 1 ; i++ ) g[u[i]].emplace_back( v[i] ), g[v[i]].emplace_back( u[i] );
    dis[0] = -1;
    pre( 1, 0 );
    build();
    printf("%d\n",cnt);
    for( int i = 1 ; i <= cnt ; i++ ) printf("%d ",arr[i]);
    printf("\n");
    for( int i = 1 ; i <= cnt ; i++ ) printf("%d ",dis[arr[i]]);
    printf("\n");
    for( int i = 1 ; i <= n ; i++ ) printf("%d %d\n",in[i],out[i]);
    printf("%d\n",seg[1]);
    for( int i = 0 ; i < q ; i++ ) {
        printf("%d %d\n",in[a[i]],out[a[i]]);
        update( in[a[i]], out[a[i]], dis[a[i]] - 1 );
        ans.emplace_back( seg[1] );
        update( in[a[i]], out[a[i]], -1*dis[a[i]] + 1 );
    }
    return ans;
}

int main() {
    int n, q, u[100], v[100], a[100];
    scanf("%d %d",&n,&q);
    for( int i = 0 ; i < n - 1 ; i++ ) scanf("%d",&u[i]);
    for( int i = 0 ; i < n - 1 ; i++ ) scanf("%d",&v[i]);
    for( int i = 0 ; i < q ; i++ ) scanf("%d",&a[i]);
    vector<int> vv = getRadius( n, q, u, v, a );
    for( int i : vv ) printf("%d ",i);
    return 0;
}