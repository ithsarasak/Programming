#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
const long long pr = 98765431;
int n, ver[5][N], q;
char s[N];
vector<pii> t;
vector<long long> L, R;
int ans[2][N];
long long hsh[N], hsh2[N], po[N];
vector<long long> vec[4];

pii add( pii x, pii y ) { return pii( x.x + y.x, x.y + y.y ); }
pii sub( pii x, pii y ) { return pii( x.x - y.x, x.y - y.y ); }
long long f( int l, int r ) { return 1ll * r * ( r + 1 ) / 2ll - 1ll * l * ( l - 1 ) / 2ll; }

int newleaf( pii x ) {
    t.emplace_back( x ), L.emplace_back( -1 ), R.emplace_back( -1 );
    return ( int )t.size() - 1; 
}

int newpar( int l, int r ) {
    t.emplace_back( add( t[l], t[r] ) );
    L.emplace_back( l ), R.emplace_back( r );
    return ( int )t.size() - 1;
}

int build( int l = 1, int r = n ) {
    if( l == r ) return newleaf( pii( 0, 0 ) );
    int mid = l + r >> 1;
    return newpar( build( l, mid ), build( mid+1, r ) );
}

int get( int i, int x ) { return lower_bound( vec[i].begin(), vec[i].end(), x ) - vec[i].begin() + 1; }

int update( int x, pii k, long long p, int l = 1, int r = n ) {
    if( l == r ) return newleaf( add( t[p], k ) );
    int mid = l + r >> 1;
    if( x <= mid ) return newpar( update( x, k, L[p], l, mid ), R[p] );
    else return newpar( L[p], update( x, k, R[p], mid+1, r ) );
}

pii query( int ty, int a, int b, long long x, int l = 1, int r = n ) {
    if( vec[ty][l-1] > x ) return pii( 0, 0 );
    if( vec[ty][r-1] <= x ) return sub( t[b], t[a] );
    int mid = l + r >> 1;
    return add( query( ty, L[a], L[b], x, l, mid ), query( ty, R[a], R[b], x, mid+1, r ) );
}

void init() {
    po[0] = 1;
    for( int i = 1 ; i <= n ; i++ ) hsh[i] = hsh[i-1] * pr + s[i], po[i] = po[i-1] * pr;
    for( int i = n ; i >= 1 ; i-- ) hsh2[i] = hsh2[i+1] * pr + s[i];
    for( int i = 1 ; i <= n ; i++ ) {
        int l = 1, r = min( i, n-i+1 );
        while( l < r ) {
            int mid = l + r + 1 >> 1;
            if( hsh[i+mid-1] - hsh[i-1] * po[mid] == hsh2[i-mid+1] - hsh2[i+1] * po[mid] ) l = mid;
            else r = mid - 1;
        }
        ans[0][i] = l;
        l = 1, r = min( i, n-i );
        if( i == n || s[i] != s[i+1] ) continue ;
        while( l < r ) {
            int mid = l + r + 1 >> 1;
            if( hsh[i+mid] - hsh[i] * po[mid] == hsh2[i-mid+1] - hsh2[i+1] * po[mid] ) l = mid;
            else r = mid - 1;
        }
        ans[1][i+1] = l;
    }
    for( int i = 1 ; i <= n ; i++ ) {
        vec[0].emplace_back( ans[0][i] - i ), vec[1].emplace_back( i + ans[0][i] );
        vec[2].emplace_back( ans[1][i] - i ), vec[3].emplace_back( i + ans[1][i] );
    }
    for( int i = 0 ; i < 4 ; i++ ) sort( vec[i].begin(), vec[i].end() );
    ver[3][0] = ver[2][0] = ver[1][0] = ver[0][0] = build( 0 );
    for( int i = 1 ; i <= n ; i++ ) {
        int lb1 = ans[0][i]-i, lb2 = ans[1][i]-i, rb1 = i+ans[0][i], rb2 = i+ans[1][i];
        ver[0][i] = update( get( 0, lb1 ), pii( lb1, 1 ), ver[0][i-1] );
        ver[1][i] = update( get( 1, rb1 ), pii( rb1, 1 ), ver[1][i-1] );
        ver[2][i] = update( get( 2, lb2 ), pii( lb2, 1 ), ver[2][i-1] );
        ver[3][i] = update( get( 3, rb2 ), pii( rb2, 1 ), ver[3][i-1] );
    } 
}

long long cal( int a, int b, int l, int r ) {
    int mid = l + r >> 1;
    pii lhs = query( a, ver[a][l-1], ver[a][mid], 1-l );
    pii rhs = query( b, ver[b][mid], ver[b][r], r+1 );
    long long now = f( l, mid ) + lhs.x + rhs.x - f( mid+1, r );
    now -= 1ll * ( l - 1 ) * ( mid - l + 1 - lhs.y );
    now += 1ll * ( r + 1 ) * ( r - mid - rhs.y );
    return now;
}
int main()
{
    scanf("%d %s %d",&n,&s[1],&q);
    init();
    for( int i = 1, l, r; i <= q; i++ ) {
        scanf("%d %d",&l,&r);
        printf("%lld\n",cal( 0, 1, l, r ) + cal( 2, 3, l+1, r ));
    }
    return 0;
}