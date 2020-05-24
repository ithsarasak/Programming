#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second
using namespace std;

long long ll, rr;
int t;

long long sum( long long x, long long y ) {
    if( x > y ) return 0;
    return y * ( y + 1 ) / 2 - x * ( x - 1 ) / 2;
}

long long solve1( long long L, long long R ) {
    if( L < R ) swap( L, R );
    long long l = 0, r = 1e9;
    while( l < r ) {
        long long mid = ( l + r ) >> 1;
        if( L - sum( 1, mid ) <= R ) r = mid;
        else l = mid + 1;
    }
    return l;
}

long long solve2( long long L, long long R ) {
    if( L < R ) swap( L, R );
    long long l = 0, r = 1e9;
    while( l < r ) {
        long long mid = ( l + r + 1 ) >> 1;
        if( L - sum( 1, mid ) >= 0 ) l = mid;
        else r = mid - 1;
    }
    return l;
}

pii CAL( long long x1, long long y1, long long x2, long long y2 ) {
    long long one, two, cal = y1;
    int chk = 0;
    if( x1 > y1 ) one = 0, chk = 1;
    if(( x1 % 2 ) != ( y1 % 2 )) cal--;
    if( !chk ) one = ( ( x1 + cal ) * ( ( cal - x1 ) / 2 + 1 ) / 2 );
    chk = 0, cal = y2;
    if( x2 > y2 ) two = 0, chk = 1;
    if(( x2 % 2 ) != ( y2 % 2 ) ) cal--;
    if( !chk ) two = ( ( x2 + cal ) * ( ( cal - x2 ) / 2 + 1 ) / 2 );
    return pii( one, two );
}

pii check( long long x1, long long y1, long long x2, long long y2 ) {
    long long one, two;
    tie( one, two ) = CAL( x1, y1, x2, y2 );
    //printf("%lld %lld\n",one,two);
    if( ll >= rr ) return pii( ll - one, rr - two );
    else return pii( ll - two, rr - one );
}

int main() 
{
    scanf("%d",&t);
    for( int i = 1 ; i <= t ; i++ ) {
        scanf("%lld %lld",&ll,&rr);
        //printf("%lld %lld\n",solve1(ll,rr),solve2(ll,rr));
        long long ans = min( solve1( ll, rr ), solve2( ll, rr ) );
        //printf("ANS : %lld\n",ans);
        if( ll >= rr ) ll -= sum( 1, ans );
        else rr -= sum( 1, ans );
        long long l = ans, r = 1e9, L, R;
        while( l < r ) {
            long long mid = ( l + r + 1 ) >> 1;
            tie( L, R ) = check( ans + 1, mid, ans + 2, mid );
            if( L < 0 || R < 0 ) r = mid - 1;
            else l = mid;
        }
        tie( L, R ) = check( ans + 1, l, ans + 2, l );
        printf("Case #%d: ",i);
        printf("%lld %lld %lld\n",l,L,R);
    }
    return 0;
}