#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int mod = 1e9 + 7;
const int L = 1e3 + 10;

int n, l, a[N];
long long dp[N][N][L][3];

long long solve( int pos, int cc, int diff, int ends ) {
    if( pos == n+1 ) return ( cc == 1 && diff <= l && ends == 2 );
    if( cc == 0 || diff > l || ends == 3 ) return 0;
    long long &now = dp[pos][cc][diff][ends];
    if( now != -1 ) return now;
    int nxt = diff + ( a[pos] - a[pos-1] ) * ( 2 * cc - ends );
    now = 0;
    now = ( now + ( cc + 1 - ends ) * solve( pos+1, cc+1, nxt, ends ) % mod ) % mod;
    now = ( now + ( cc - 1 ) * solve( pos+1, cc-1, nxt, ends ) % mod ) % mod;
    now = ( now + ( 2*cc - ends ) * solve( pos+1, cc, nxt, ends ) % mod ) % mod;
    now = ( now + ( 2 - ends ) * solve( pos+1, cc, nxt, ends + 1 ) % mod ) % mod;
    now = ( now + ( 2 - ends ) * solve( pos+1, cc + 1, nxt, ends + 1 ) % mod ) % mod;
    return now;
}

int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%d %d",&n,&l);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
    sort( a+1, a+1+n );
    if( n == 1 ) return !printf("1\n");
    printf("%lld\n",( solve( 2, 1, 0, 0 ) + 2*solve( 2, 1, 0, 1 ) ) % mod);
    return 0;
}