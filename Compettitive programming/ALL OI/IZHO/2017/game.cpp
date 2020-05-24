#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n, m, t[N], a[N];

void up( int idx, int va ) { for( int i = idx ; i < N ; i += i & -i ) t[i] += va; }
int query( int idx ) {
    int ret = 0;
    for( int i = idx ; i > 0 ; i -= i & -i ) ret += t[i];
    return ret;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
    for( int i = 1 ; i <= n ; i++ ) if( i < n ) up( min( a[i], a[i+1] ), 1 ), up( max( a[i], a[i+1] ), -1 );
    while( m-- ) {
        int t, i, h;
        scanf("%d %d",&t,&i);
        if( t == 1 ) {
            scanf("%d",&h);
            if( i > 1 ) up( min( a[i-1], a[i] ), -1 ), up( max( a[i-1], a[i] ), 1 );
            if( i < n ) up( min( a[i], a[i+1] ), -1 ), up( max( a[i], a[i+1] ), 1 );
            a[i] = h;
            if( i > 1 ) up( min( a[i-1], a[i] ), 1 ), up( max( a[i-1], a[i] ), -1 );
            if( i < n ) up( min( a[i], a[i+1] ), 1 ), up( max( a[i], a[i+1] ), -1 );
        }
        else printf("%d\n",query(i));
    }
    return 0;
}