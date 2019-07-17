#include <bits/stdc++.h>/
#include "gondola.h"
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

long long mod = 1e9 + 9;

int valid( int n, int num[] ) {
    unordered_map<int,int> m;
    int st = 0;
    for( int i = 0 ; i < n ; i++ ) {
        if( m[num[i]] > 0 ) return 0;
        if( num[i] <= n && st == 0 ) st = num[i];
        else if( num[i] <= n && st > 0 && st != num[i] ) return 0; 
        if( st != 0 ) st = ( st % n ) + 1; 
        m[num[i]]++;
    }
    return 1;
}

int replacement( int n, int num[], int se[] ) {
    vector<pii> all;
    int ori[250100];
    memset( ori, -1, sizeof ori );
    for( int i = 0 ; i < n ; i++ ) if( num[i] <= n ) {
        ori[i] = num[i] - 1;
        for( int j = i + 1 ; j < n ; j++ ) ori[j] = ( num[i] - 1 + j - i ) % n;
        for( int j = i - 1 ; j >= 0 ; j-- ) ori[j] = ( num[i] - 1 + n + j - i ) % n;
        break;
    }
    if( ori[0] == -1 ) for( int i = 0 ; i < n ; i++ ) ori[i] = i;
    for( int i = 0 ; i < n ; i++ ) ori[i]++;
    for( int i = 0 ; i < n ; i++ ) if( num[i] > n ) all.emplace_back( pii( num[i], ori[i] ) );
    sort( all.begin(), all.end() );
    int cnt = 0, fix = n + 1;
    for( int i = 0 ; i < all.size() ; i++ ) {
        int a, b;
        tie( a, b ) = all[i];
        while( b != a ) {
            se[cnt] = b;
            b = fix;
            cnt++, fix++;
        }
    }
    return cnt;
}

long long modpow( long long base, long long power ) {
    long long ret = 1;
    for( ; power ; power >>= 1) {
        if( power & 1 ) ret = ( ret * base ) % mod;
        base = ( base * base ) % mod;
    }
    return ret;
}
int countReplacement( int n, int num[] ) {
    vector<int> all;
    if( !valid( n, num ) ) return 0;
    for( int i = 0 ; i < n ; i++ ) if( num[i] > n ) all.emplace_back( num[i] );
    sort( all.begin(), all.end() );
    int now = n + 1;
    long long ret = 1;
    for( int i = 0 ; i < ( int )all.size() ; i++ ) {
        ret = ( ret * modpow( ( int )all.size() - i, all[i] - now ) ) % mod;
        now = all[i] + 1;
    }
    if( ( int )all.size() == n ) ret = ( ret * n ) % mod;
    return ( int )ret;
}

// int main() {
//     int n, se[100], num[100];
//     scanf("%d",&n);
//     for( int i = 0 ; i < n ; i++ ) scanf("%d",&num[i]);
//     int x = countReplacement( n, num );
//     printf("%d\n",x);
// }

