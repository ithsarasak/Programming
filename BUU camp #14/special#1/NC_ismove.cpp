#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

long long pos[N], sum, d, ans1, ans2, n;

long long chk( long long de ) {
    long long ret = 0;
    for( long long i = 2 ; i <= n ; i++ ) ret += ( ( i - 1 ) * de - pos[i] );
    return abs( ret );
}

int main()
{
    scanf("%lld",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%lld",&pos[i]);
        sum += pos[i];
    }
    d = ( 2 * sum ) / ( n * ( n - 1 ) );
    long long ans1 = chk( d ), ans2 = chk( d + 1 );
    if( ans1 < ans2 ) printf("%lld\n%lld",d,ans1);
    else printf("%lld\n%lld",d+1,ans2);
    return 0;
}