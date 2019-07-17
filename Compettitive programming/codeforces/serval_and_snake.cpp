#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int n, sumrow, sumcol;
vector<int> r, c;
vector<pii> ans;

int ask(int a, int b, int c, int d) {
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush( stdout );
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i < n ; i++ ) {
        int a = ask( 1, i, n, i ), b = ask( i, 1, i, n );
        sumcol += a, sumrow += b;
        if( a & 1 ) c.emplace_back( i );
        if( b & 1 ) r.emplace_back( i );
    }
    if( sumcol & 1 ) c.emplace_back( n );
    if( sumrow & 1 ) r.emplace_back( n );
    if( !r.empty() ) for( int i : r ) {
        int l = 1, r = n;
        while( l < r ) {
            int mid = ( l + r ) >> 1;
            if( ask( i, 1, i, mid ) & 1 ) r = mid;
            else l = mid + 1;
        }
        ans.emplace_back( pii( i, r ) ) ;
    }
    else for( int i : c ) {
        int l = 1, r = n;
        while( l < r ) {
            int mid = ( l + r ) >> 1;
            if( ask( 1, i, mid, i ) & 1 ) r = mid;
            else l = mid + 1;
        }
        ans.emplace_back( pii( r, i ) );
    } 
    printf("! ");
    for( pii p : ans ) printf("%d %d ",p.x,p.y);
    printf("\n");
    fflush( stdout );
    return 0;
}