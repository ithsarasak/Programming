#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
long long fen[N], va, a[N], s, t, sum;
int n, q, l, r;

long long query( int idx ) {
    long long ret = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ) ret += fen[i];
    return ret;
}

void up( int idx, long long va ) {
    for( int i = idx ; i <= N ; i += ( i & -i ) ) fen[i] += va;
}

long long cal( int l, int r ) {
    long long a = query( l ), b = query( r );
    if( a < b ) return ( a - b ) * s;
    else return ( a - b ) * t;
}

int main()
{
    scanf("%d %d %lld %lld",&n,&q,&s,&t);
    for( int i = 1 ; i <= n + 1 ; i++ ) {
        scanf("%lld",&a[i]);
        up( i, a[i] ), up( i + 1, -a[i] );
    }
    for( int i = 1 ; i <= n ; i++ ) sum += cal( i, i + 1 );
    while( q-- ) {
        scanf("%d %d %lld",&l,&r,&va);
        l++, r++;
        sum -= ( ( l == 1 ? 0 : cal( l - 1, l ) ) + ( r == n + 1 ? 0 : cal( r, r + 1 ) ) );
        up( l, va ), up( r + 1, -va );
        sum += ( ( l == 1 ? 0 : cal( l - 1, l ) ) + ( r == n + 1 ? 0 : cal( r, r + 1 ) ) );
        printf("%lld\n",sum);
    }
    return 0;
}Dd