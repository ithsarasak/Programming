#include <bits/stdc++.h>
#define long long long 

using namespace std;

const int N = 1e5 + 10;
int n, k, x[N], y[N];
long ans;
vector<int> coord[N];
vector<long> t[N];

void update( vector<long> &t, int idx ) { for( int i = idx ; i < t.size() ; i += i & -i ) t[i] += 1LL; }

long query( vector<long> &t, int idx ) {
    long ret = 0;
    for( int i = idx ; i > 0 ; i -= i & -i ) ret += t[i];
    return ret;
}

long query2d( int x, int y ) {
    long ret = 0;
    for( int i = x ; i > 0 ; i -= i & -i ) {
        int idx = upper_bound( coord[i].begin(), coord[i].end(), y ) - coord[i].begin();
        ret += query( t[i], idx );
    }
    return ret;
}

void update2d( int x, int y ) {
    for( int i = x ; i <= n ; i += i & -i ) {
        int idx = lower_bound( coord[i].begin(), coord[i].end(), y ) - coord[i].begin() + 1;
        update( t[i], idx );
    }
}

int main()
{
    freopen("friendcross.in", "r", stdin);
    freopen("friendcross.out", "w", stdout);
    scanf("%d %d",&n,&k);
    for( int i = 1, a ; i <= n ; i++ ) scanf("%d",&a), x[a] = i;
    for( int i = 1, a ; i <= n ; i++ ) scanf("%d",&a), y[a] = i;
    for( int i = 1 ; i <= n ; i++ ) for( int j = x[i] ; j <= n ; j += j & -j ) coord[j].emplace_back( y[i] );
    for( int i = 1 ; i <= n ; i++ ) {
        sort( coord[i].begin(), coord[i].end() );
        coord[i].resize( unique( coord[i].begin(), coord[i].end() ) - coord[i].begin() );
        t[i].resize( coord[i].size() + 10 );
    }
    for( int i = 1, j = k + 2 ; j <= n ; i++, j++ ) {
        update2d( x[i], y[i] );
        ans += query2d( n, y[j] ) + query2d( x[j], n ) - 2LL*query2d( x[j], y[j] );
    }
    printf("%lld\n",ans);
    return 0;
}