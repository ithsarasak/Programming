#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

const int mod = 1e9+7;
int n, m, k, valid;
long long ans;

long long cal( long long a, long long b ) {
    long long ret = 1, mul;
    for( ; b ; b >>= 1 ) {
        if( b & 1 ) ret = ( ret * a ) % mod;
        a = ( a * a ) % mod;
    }
    return ret;
}
void solve( int si, vector<int> &x, vector<int> &y, vector<int> &type ) {
    map<int,int> mp;
    for( int i = 0 ; i < x.size() ; i++ ) {
        int now = x[i], val = type[i];
        if( y[i] % 2 == 0 ) val ^= 1;
        if( !mp.count( now ) ) mp[now] = val;
        else if( mp[now] != val ) return ;
    }
    ans = ( ans + cal( 2, si - mp.size() ) ) % mod;
    int b = -1;
    for( pii p : mp ) {
        int now = ( ( p.x & 1 ) == p.y );
        if( b == -1 ) b = now;
        else if( b != now ) return;
    }
    ++valid;
}
vector<int> x, y, type;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    if( k == 0 ) return !printf("%lld\n",( cal( 2, n ) + cal( 2, m ) - 2 + mod ) % mod );
    for( int i = 1 ; i <= k ; i++ ) {
        int a, b;
        char c;
        scanf(" %c %d %d",&c,&a,&b);
        x.emplace_back( a ), y.emplace_back( b ), type.emplace_back( c == '+' );
    }
    solve( n, x, y, type ), solve( m, y, x, type );
    if( valid == 2 ) ans = ( ans - 1 + mod ) % mod;
    printf("%lld",ans);
    return 0;
}