#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 5e5 + 10;
int n, q;
long d[N], t[N];

long chk( long x, long ti ) { return ( ti/t[x] ) * t[x] - x; }
int main()
{
    scanf("%d %d",&n,&q);
    d[0] = 1, t[0] = 1;
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&d[i]);
    //printf("\n");
    for( int i = 1 ; i <= n ; i++ ) {
        long a = d[i] / t[i-1];
        if( a*t[i-1] != d[i] ) a++;
        t[i] = t[i-1] * a;
        //printf("%lld\n",t[i]);
    }
    while( q-- ) {
        long ti, le, ri, lb, rb;
        scanf("%lld %lld %lld",&ti,&le,&ri);
        int l = 0, r = n;
        if( chk( 0, ti  ) < le ) {
            printf("0\n");
            continue ;
        }
        else if( chk( n, ti ) > ri ) {
            printf("0\n");
            continue ;
        }
        while( l < r ) {
            long mid = ( long )( l + r >> 1 );
            if( chk( mid, ti ) <= ri ) r = mid;
            else l = mid + 1;
        }
        rb = ( long )l, l = 0, r = n;
        while( l < r ) {
            long mid = ( long )( l + r + 1 >> 1 );
            if( chk( mid, ti ) >= le ) l = mid;
            else r = mid - 1;
        }
        lb = ( long )l;
        //printf("%lld %lld\n",lb,rb);
        printf("%lld\n",lb-rb+1);
    }
    return 0;
}