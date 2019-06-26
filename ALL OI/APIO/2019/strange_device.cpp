#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define x first
#define y second

using namespace std;

const long long inf = 1000000000000000000;
int n;
long long a, b, ans, sum;
vector<pll> seg, m;

int chk( long long a, long long b ) {
    long long temp;
    temp = inf / a;
    if( b > temp ) return 1;
    else return 0 ;
}

void process( long long mul ) {
    //cout << mul << endl;
    for( int i = 1 ; i < ( int )seg.size() ; i++ ) {
        if( seg[i].y - seg[i].x + 1 >= mul ) {
            printf("%lld",mul);
            return ;
        }
        long long f = seg[i].x % mul, t = seg[i].y % mul;
        if( t < f ) m.emplace_back( pll( f, mul - 1 ) ), m.emplace_back( pll( 0, t ) );
        else m.emplace_back( pll( f, t ) );
    }
    sort( m.begin(), m.end() );
    long long l = -1, r = -1;
    for( int i = 0 ; i < m.size() ; i++ ) {
        //printf("%lld %lld\n",m[i].x,m[i].y);
        if( m[i].x > r ) {
            ans += m[i].y - m[i].x + 1;
            l = m[i].x, r = m[i].y;
        }
        else {
            ans += ( m[i].y - m[i].x + 1 ) - ( min( r, m[i].y ) - max( l, m[i].x ) + 1 );
            r = max( r, m[i].y );
        }
    }
    printf("%lld",ans);
    return ;
}

int main()
{
    scanf("%d %lld %lld",&n,&a,&b);
    seg.emplace_back( pll( -1LL, -1LL ) );
    for( int i = 1 ; i <= n ; i++ ) {
        long long ff, tt;
        scanf("%lld %lld",&ff,&tt);
        seg.emplace_back( pll( ff, tt ) );
        sum += tt - ff + 1;
    }
    long long g = __gcd( a, b + 1 );
    long long x = a / g;
    int cc = chk( x, b );
    if( cc ) return !printf("%lld",sum);
    process( x*b );
    return 0;
}