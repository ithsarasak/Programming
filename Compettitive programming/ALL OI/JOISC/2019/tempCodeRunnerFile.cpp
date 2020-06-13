#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second 

using namespace std;

const int N = 2e5 + 10;

int n, m, ver[N];
pii cake[N];
vector<long long> t, coord;
vector<int> sz, L, R;
unordered_map<long long, int> mp;
long long ans[N], ret = -2e18;

int newleaf( long long va, int ss ) {
    t.emplace_back( va ), sz.emplace_back( ss ), L.emplace_back( -1 ), R.emplace_back( -1 );
    return (int)t.size() - 1;
}

int newpar( int l, int r ) {
    t.emplace_back( t[l] + t[r] ), sz.emplace_back( sz[l] + sz[r] );
    L.emplace_back( l ), R.emplace_back( r );
    return (int)t.size() - 1;
}

int get( long long x ) { 
    mp[x]++;
    return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + mp[x]; 
}

int build( int l = 1, int r = coord.size() ) {
    if( l == r ) return newleaf( 0, 0 );
    int mid = l + r >> 1;
    return newpar( build( l, mid ), build( mid+1, r ) );
}

int update( int x, long long va, int p, int l = 1, int r = coord.size() ) {
    if( l == r ) return newleaf( va, 1 );
    int mid = l + r >> 1;
    if( mid >= x ) return newpar( update( x, va, L[p], l, mid ), R[p] );
    else return newpar( L[p], update( x, va, R[p], mid+1, r ) );
}

long long query( int a, int b, int x, int l = 1, int r = coord.size() ) {
    if( x == 0 ) return 0LL;
    if( l == r ) return t[b] - t[a];
    int mid = l + r >> 1;
    if( sz[R[b]] - sz[R[a]] >= x ) return query( R[a], R[b], x, mid+1, r );
    else return t[R[b]] - t[R[a]] + query( L[a], L[b], x - sz[R[b]] + sz[R[a]], l, mid );
}

void solve( int l, int r, int optl, int optr ) {
    if( l > r ) return ;
    int mid = l + r >> 1, idx = optl;
    for( int i = max( mid + m - 1, optl ) ; i <= optr ; i++ ) {
        long long now = query( ver[mid], ver[i-1], m-2 ) + cake[i].x + cake[mid].x - 2*cake[i].y + 2*cake[mid].y;
        if( now > ans[mid] ) ans[mid] = now, idx = i;
    }
    solve( l, mid-1, optl, idx ), solve( mid+1, r, idx, optr );
}

int main()
{
    fill_n( ans, N, -2e18 );
    t.emplace_back( 0 ), sz.emplace_back( 0 ), R.emplace_back( 0 ), L.emplace_back( 0 );
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%lld %lld",&cake[i].x,&cake[i].y);
        coord.emplace_back( cake[i].x );
    }
    sort( cake + 1, cake + 1 + n, [&]( const pii &a, const pii &b ) {
        return a.y < b.y;
    });
    sort( coord.begin(), coord.end() );
    ver[0] = build();
    //for( int i = 1 ; i < L.size() ; i++ ) printf("%d %d\n",L[i],R[i]);
    for( int i = 1 ; i <= n ; i++ ) ver[i] = update( get( cake[i].x ), cake[i].x, ver[i-1] );
    solve( 1, n-m+1, 1, n );
    for( int i = 1 ; i <= n-m+1 ; i++ ) {
        printf("%lld",ans[i]);
        ret = max( ret, ans[i] );
    }
    printf("%lld",ret);
    return 0;
}