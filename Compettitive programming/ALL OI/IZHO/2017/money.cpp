#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e6 + 10;
int n, a[N], ans, le = 1;
set<int> s;
vector<pii> all;

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
    for( int i = 1 ; i <= n ; i++ ) if( a[i] > a[i+1] ) {
        all.emplace_back( pii( le, i ) );
        le = i + 1;
    }
    s.insert( 1000001 );
    for( int i = all[0].x ; i <= all[0].y ; i++ ) s.insert( a[i] );
    for( int i = 1 ; i < all.size() ; i++ ) {
        pii x = all[i];
        int pt = x.x;
        while( pt <= x.y ) {
            int val = *s.upper_bound( a[pt] );
            while( a[pt] <= val && pt <= x.y ) {
                s.insert( a[pt] );
                pt++;
            }
            ans++;
        }
    }
    printf("%d",ans+1);
    return 0;
}