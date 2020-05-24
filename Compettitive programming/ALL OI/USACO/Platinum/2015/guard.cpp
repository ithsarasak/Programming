#include <bits/stdc++.h>

using namespace std;

int n, hi, a[30], ans = -1, h[30], w[30], s[30];
int main()
{
    freopen( "guard.in", "r", stdin );
    freopen( "guard.out", "w", stdout );
    iota( a, a + 25, 0 );
    scanf("%d %d",&n,&hi);
    for( int i = 0 ; i < n ; i++ ) scanf("%d %d %d",&h[i],&w[i],&s[i]);
    sort( a, a+n, [&]( const int &a, const int & b ){
        return w[a] + s[a] < w[b] + s[b];
    });
    for( int i = 1 ; i < ( 1<<n ) ; i++ ) {
        int sum = 0, sumh = 0, safe = 1e9, chk = 0;
        for( int j = 0 ; j < n ; j++ ) if( i & ( 1<<j ) ) {
            if( sum > s[a[j]] ) {
                chk = 1;
                break;
            }
            safe = min( safe, s[a[j]] - sum );
            sum += w[a[j]];
            sumh += h[a[j]];
        }
        if( !chk && sumh >= hi ) ans = max( ans, safe );
    }
    if( ans == -1 ) return !printf("Mark is too tall");
    printf("%d",ans);
    return 0;
}