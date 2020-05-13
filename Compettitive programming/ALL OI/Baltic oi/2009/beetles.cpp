#include <bits/stdc++.h>

using namespace std;

const int N = 310;
int n, m, pos[N];
long long l[N][N], ans, r[N][N];

long long d( int x, int y ) { return abs( pos[x] - pos[y] ); }

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&pos[i]);
    sort( pos + 1, pos + n + 1 );
    for( int k = 1 ; k <= n ; k++ ) {
        for( int i = n ; i >= 1 ; i-- ) for( int j = i ; j <= n ; j++ ) {
            int sz = j - i + 1;
            if( sz > k ) continue ;
            if( i == j ) l[i][j] = r[i][j] = 1LL * k * abs( pos[i] );
            else {
                l[i][j] = min( l[i+1][j] + d( i, i+1 ) * ( k - sz + 1 ), r[i+1][j] + d( i, j ) * ( k - sz + 1 ) );
                r[i][j] = min( l[i][j-1] + d( i, j ) * ( k - sz + 1 ), r[i][j-1] + d( j-1, j ) * ( k - sz + 1 ) );
            } 
        }
        for( int i = 1, j = k ; j <= n ; i++, j++ ) ans = max( ans, 1ll * k * m - min( l[i][j], r[i][j] ) );
    }
    printf("%lld\n",ans);
    return 0;
}