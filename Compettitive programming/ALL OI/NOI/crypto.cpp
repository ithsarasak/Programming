#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int n, a[N], t[N];
long long fac[N], ans, mod = 1000000007;
vector<int> coord;

int get( int x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + 1; }

int query( int idx ) { 
    int ret = 0;
    for( int i = idx ; i > 0 ; i -= i & -i ) ret += t[i];
    return ret;
}

void update( int idx, int va ) {
    for( int i = idx ; i < N ; i += i & -i ) t[i] += va;
}

int main()
{
    fac[0] = 1;
    for( int i = 1 ; i < N ; i++ ) fac[i] = ( fac[i-1] * i ) % mod;
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&a[i]);
        coord.emplace_back( a[i] );
    }
    for( int i = 1 ; i <= n ; i++ ) update( i, 1 );
    sort( coord.begin(), coord.end() );
    for( int i = 1 ; i <= n ; i++ ) {
        int p = get( a[i] );
        ans = ( ans + 1ll * query( p-1 ) * ( fac[n-i] ) ) % mod;
        update( p, -1 );
    }
    printf("%lld",(ans+1)%mod);
    return 0;
}