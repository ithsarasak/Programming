#include <bits/stdc++.h>
#define pii pair<int, int>
#define pdd pair<double, double>
#define x first
#define y second

using namespace std;

const int N = 1e3 + 10;

int n;
vector<pii> p;
set<pdd> s;
map<double, int> mp;

int main() 
{
    scanf("%d", &n);
    for( int i = 1, a, b ; i <= n ; i++ ) {
        scanf("%d %d",&a,&b);
        p.emplace_back( pii( a, b ) );
    }
    for( int i = 0 ; i < n ; i++ ) for( int j = i + 1 ; j < n ; j++ ) {
        double m, c;
        pii x = p[i], y = p[j];
        if( x.x == y.x ) m = 1e9;
        else m = ( double )( x.y - y.y ) / ( double )( x.x - y.x );
        if( m == 1e9 ) c = x.x;
        else c = ( double )x.y - m * x.x;
        s.emplace( pdd( m, c ) );
    }
    long long  ans = ( long long ) ( ( long long )s.size() * ( ( long long )s.size() - 1LL ) / 2LL );
    for( auto i : s ) ++mp[i.x];
    for( auto i : mp ) ans -= ( long long ) ( ( long long )i.y * ( ( long long ) i.y - 1LL ) / 2LL );
    printf("%lld\n", ans);
    return 0;
}