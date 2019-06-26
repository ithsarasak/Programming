#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 5e3 + 10;

int n, ans = INT_MAX;
vector<int> g[N];
int dep[N];
queue<int> q;

int bfs( int root ) {
    int ret = 0;
    for( int i = 1 ; i <= n ; i++ ) dep[i] = INT_MAX;
    dep[root] = 1;
    q.emplace( root );
    while( !q.empty() ) {
        int now = q.front(); q.pop();
        for( int i : g[now] ) if( dep[now] + 1 < dep[i] ) {
            dep[i] = dep[now] + 1;
            q.emplace( i );
        }
    }
    for( int i = 1 ; i <= n ; i++ ) {
        if( dep[i] == INT_MAX ) return INT_MAX;
        ret += dep[i];
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for( int i = 1, k ; i <= n ; i++ ) {
        scanf("%d",&k);
        for( int j = 1, t ; j <= k ; j++ ) {
            scanf("%d",&t);
            g[t].emplace_back( i );
        }
    }
    for( int i = 1 ; i <= n ; i++ ) ans = min( ans, bfs( i ) );
    printf("%d",ans);
    return 0;
}