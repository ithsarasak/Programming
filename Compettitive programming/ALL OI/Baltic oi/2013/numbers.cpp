#include <bits/stdc++.h>

using namespace std;

long long a, b, dp[20][15][15][2][2], ans;
char A[20];

long long solve( int pos = 0, int di1 = 10, int di2 = 10, bool m = false, bool s = false ) {
    if( !A[pos] ) return 1LL;
    long long &ret = dp[pos][di1][di2][m][s];
    if( ~ret ) return ret;
    ret = 0;
    int mx;
    if( m ) mx = 9;
    else mx = A[pos] - '0';
    for( int i = 0 ; i <= mx ; i++ ) {
        if( i == di1 || i == di2 ) continue;
        if( !i && !s ) ret += solve( pos + 1, 10, 10, true, false );
        else ret += solve( pos + 1, di2, i, m|( i < mx ), true );
    }
    return ret;
}

int main() 
{
	scanf("%lld %lld", &a, &b);
	memset( dp, -1LL, sizeof dp );
	sprintf( A, "%lld", b );
	ans = solve();
	if( a ) {
		memset( dp, -1LL, sizeof dp );
		sprintf( A, "%lld", a-1 );
		ans -= solve();
	}
	printf("%lld\n", ans);
	return 0;
}