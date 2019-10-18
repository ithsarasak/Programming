#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, dp[N];
vector<int> g[N];
void dfs( int u, int p ) {
    //printf("%d %d\n",u,p);
    priority_queue<int, vector<int>, greater<int> > q;
    for( int i : g[u] ) if( i != p ) dfs( i, u );
    for( int i : g[u] ) if( i != p ) q.emplace( dp[i] );
    while( q.size() > 2 ) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        q.emplace( max( a, b ) + 1 );
    }
    int a = 0;
    while( !q.empty() ) {
        a = max( a, q.top() );
        q.pop();
    }
    dp[u] = a + 1;
    return ;
}

int main()
{
    scanf("%d",&n);
    for( int i = 2, v ; i <= n ; i++ ) {
        scanf("%d",&v);
        g[v].emplace_back( i ), g[i].emplace_back( v );
    }
    dfs( 1, 0 );
    printf("%d",dp[1] - 1);
    return 0;
}