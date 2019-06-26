#include <bits/stdc++.h>

using namespace std;

int n, m;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d %d",&k[i],&a[i]);
        coord.emplace_back( a[i] );
    }
    sort( coord.begin(), coord.end() );
    for( int i = 1 ; i <= n ; i++ ) {
        s.insert( pii( a[i], k[i] ) );
        int x = get( a[i] );
        if( ans[i] == -1 ) ans[i] = 1e9;
        else {
            int it = find( pii( a[i], k[i] ) );
            if( it != s.begin() ) {
                
            }
        }
    }
    return 0;
}