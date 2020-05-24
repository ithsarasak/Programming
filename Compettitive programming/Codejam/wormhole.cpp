#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e2 + 10;

int n, x[N], y[N], tt;
vector<int> vec;

pii CAL( int a, int b ) {
    pii diff( y[a] - y[b], x[a] - x[b] );
    int g = __gcd( diff.x, diff.y );
    return pii( diff.x/g, diff.y/g );
}

long long finddist( int a, int b ) { 
    long long rawdist = ( long long )( ( x[b] - x[a] ) * ( x[b] - x[a] ) ) + ( long long )( ( y[b] - y[a] ) * ( y[b] - y[a] ) );
    return rawdist;
}

int main() 
{
    scanf("%d",&tt);
    for( int z = 1 ; z <= tt ; z++ ) {
        vec.clear();
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ) {
            scanf("%d %d",&x[i],&y[i]);
            vec.emplace_back( i );
        }
        int ans = 1;
        for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= n ; j++ ) {
            if( i == j ) continue;
            vector<int> arr = vec;
            //printf("%d %d\n",i,j);
            pii s = CAL( i, j ); 
            int ret = 1;
            do {
                int bef = 1;
                for( int ii = 2 ; ii <= n ; ii++ ) {
                    printf("II : %d\n",ii);
                    if( ii % 2 ) {
                        if( s != CAL( arr[bef-1], arr[ii-1] ) ) break;
                        bef = ii;
                    } 
                    else {
                        int chk = 0;
                        for( int jj = 1 ; jj < ii ; jj++ ) if( s == CAL( arr[ii - 1], arr[jj - 1] ) ) {
                                if( ii < n && finddist( arr[jj - 1], arr[ii - 1] ) > finddist( arr[ii - 1], arr[ii] ) ) continue;
                                chk = 1;
                                if( jj % 2 ) bef = jj - 1;
                                else bef = jj + 1;
                                if( !bef ) chk = 0;
                            }
                        if( !chk ) bef = ii;
                    }
                    ret = max( ret, ii );
                }
            } while( next_permutation( arr.begin(), arr.end() ) );
            ans = max( ans, ret );
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}