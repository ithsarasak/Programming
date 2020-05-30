#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, k, h[N], ans;
vector<int> g[N];

int dfs( int u, int p ) {
    vector<int> v;
    for( int vv : g[u] ) if( vv != p ) v.emplace_back( dfs( vv, u ) );
    sort( v.begin(), v.end() );
    int sum = h[u];
    for( int i : v ) {
        if( sum + i > k ) ans++;
        else sum += i;
    }
    return sum;
} 

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&h[i]);
    for( int i = 1, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    dfs( 1, 0 );
    printf("%d",ans);
    return 0;
}