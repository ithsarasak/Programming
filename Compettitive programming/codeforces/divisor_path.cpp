#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353;
vector<long long> prime;
long long fac[150], inv[150], sq;
int q;
long long modpower( long long base, int pow ) {
    long long ret = 1;
    for( ; pow ; pow >>= 1 ) {
        if( pow & 1 ) ret = ( ret * base ) % mod;
        base = ( base * base ) % mod;
    }
    return ret;
}

unordered_map<long long,int> m;
void gen_prime()
{
    for( long long i = 2 ; i <= sq ; i++ ) {
        if( !m[i] ) for( long long j = i ; j <= sq ; j += i ) m[j] = 1;   
        prime.emplace_back( i );
    }
}

long long cal( vector<long long> &vec ) {
    long long sum = 0;
    for( long long i : vec ) sum += i;
    long long ret = fac[sum];
    for( long long i : vec ) {
        ret = ( ret * inv[i] ) % mod;
    }
    return ret;
}

int main()
{
    long long d;
    scanf("%lld",&d);
    sq = sqrt( d );
    gen_prime();
    fac[0] = 1;
    for( int i = 1 ; i <= 100 ; i++ ) fac[i] = ( fac[i-1] * i ) % mod;
    for( int i = 1 ; i <= 100 ; i++ ) inv[i] = modpower( fac[i], mod-2 );
    scanf("%d",&q);
    while( q-- ) {
        long long u, v;
        vector<long long> one, two;
        scanf("%lld %lld",&u,&v);
        if( u > v ) swap( u, v );
        long long gc = __gcd( u, v );
        long long div = u / gc;
        long long mul = v / gc;
        for( long long i : prime ) {
            int cnt = 0;
            while( div % i == 0 ) {
                div /= i;
                cnt++;
            }
            if( cnt != 0 ) one.emplace_back( cnt );
            cnt = 0;
            while( mul % i == 0 ) {
                mul /= i;
                cnt++;
            }
            if( cnt != 0 ) two.emplace_back( cnt );
        }
        if( div != 1 ) one.emplace_back( div );
        if( mul != 1 ) two.emplace_back( div );
        printf("%lld\n",cal( one ) * cal( two ) % mod);
    }
    return 0;
}