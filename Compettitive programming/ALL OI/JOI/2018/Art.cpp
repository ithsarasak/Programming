#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define x first
#define y second

using namespace std;

vector<pll> v;
int n;
long long ans, pref, mx;

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        long long a, b;
        scanf("%lld %lld",&a,&b);
        v.emplace_back( pll( a, b ) );
    }
    sort( v.begin(), v.end() );
    for( int i = 0 ; i < n ; i++ ) {
        long long a, b; 
        tie( a, b ) = v[i];
        mx = max( mx, a - pref );
        pref += b;
        ans = max( ans, pref - a + mx );
    }
    printf("%lld",ans);
    return 0;
}