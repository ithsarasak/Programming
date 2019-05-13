#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
long long g[N], b[N], n, m, sumg, sumb, mig = 1e9, mab;
int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%lld",&b[i]);
        sumb += b[i];
        mab = max( mab, b[i] );
    }
    for( int i = 1 ; i <= m ; i++ ) {
        scanf("%lld",&g[i]);
        sumg += g[i];
        mig = min( mig, g[i] );
    }
    sort( b + 1, b + n + 1 ), sort( g + 1, g + m + 1 );
    if( mig < mab ) return !printf("-1\n");
    if( mig == mab ) printf("%lld\n", sumg + ( sumb - mab ) * m);
    else printf("%lld",( sumg - g[m] ) + mab + ( g[m] + ( m - 1 ) * b[n-1] ) + ( sumb - b[n] - b[n-1] ) * m );
    return 0;
} 