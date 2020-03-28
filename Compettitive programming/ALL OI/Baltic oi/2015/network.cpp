#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n;
vector<int> g[N], lf;

void dfs( int u, int p ) { if( g[u].size() == 1 ) lf.emplace_back( u ); for( int v : g[u] ) if( v != p ) dfs( v, u ); }

int main()
{
    scanf("%d",&n);
    for( int i = 1, a, b ; i < n ; i++ ) {
        scanf("%d %d",&a,&b);
        g[a].emplace_back( b ), g[b].emplace_back( a );
    }
    dfs( 1, 0 );
    printf("%d\n",lf.size()/2 + ( lf.size() % 2 ) );
    for( int i = 0 ; i < lf.size()/2 ; i++ ) printf("%d %d\n",lf[i],lf[i+(lf.size()/2)]);
    if( lf.size() % 2 ) printf("%d %d\n",lf[0],lf[lf.size()-1]);
    return 0;
}