#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
long long a[N], sum[N], ans;
set<long long> s;
int n;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&a[i]);
    for( int i = 1 ; i <= n ; i++ ) sum[i] = sum[i-1] + a[i];
    int r = 1;
    s.insert( 0 );
    for( int i = 1 ; i <= n ; i++ ) {
        while( r <= n ) {
            if( !s.count( sum[r] ) ) s.insert( sum[r] ),r++;
            else break;
        }
        ans += ( long long )( r-1-i+1 );
        s.erase( s.find( sum[i-1] ) );
    }
    printf("%lld",ans);
}