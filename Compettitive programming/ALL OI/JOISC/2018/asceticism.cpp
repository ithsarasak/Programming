#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
long long mod = 1e9 + 7;
long long fac[N], inv[N], ans, n, k;
long long pow( long long base, long long p ) {
    long long ret = 1;
    for( ; p ; p >>= 1 ) {
        if( p & 1 ) ret = ( ret * base ) % mod;
        base = ( base * base ) % mod;
    }
    return ret;
}

long long ncr( long long a, long long b ) { return ( ( ( fac[a] * inv[b] ) % mod ) * inv[a-b] ) % mod; }

int main()
{
    fac[0] = inv[0] = 1;
    for( int i = 1 ; i < N ; i++ ) fac[i] = fac[i-1] * i % mod, inv[i] = pow( fac[i], mod-2 );
    scanf("%lld %lld",&n,&k);
    for( int i = 0 ; i <= k ; i++ ) {
        long long l = ncr( n, i ), r = pow( k - i, n );
        if( i < k ) r = ( r - pow( k - i - 1, n ) + mod ) % mod;
        l = l * r % mod;
        if( i & 1 ) ans = ( ans - l + mod ) % mod;
        else ans = ( ans + l ) % mod;
    }
    printf("%lld",ans);
    return 0;
}