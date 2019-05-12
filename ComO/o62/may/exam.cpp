#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, k, visit[N], bit[N];
vector<int> ans, g[N];
char temp[35];
queue<int> q;

void bfs( int x ) {
    fill( visit, visit + n + 1, 0 );
    q.emplace( x );
    while( !q.empty() ) {
        int t = q.front(); q.pop();
        visit[t] = 1;
        for( int i : g[t] ) if( !visit[i] ) {
            visit[i] = 1;
            q.emplace( i );
        }
    }
    return ;
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%s",temp);
        int len = strlen( temp );
        for( int j = 0 ; j < len ; j++ ) if( temp[j] == '1' ) bit[i] += ( 1 << ( j ) );
        //cout << bit[i] << " " << i << endl;
    } 
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = i + 1 ; j <= n ; j++ ) {
            if( i == j ) continue ;
            int x = bit[i] ^ bit[j];
            //cout << x << " " << bit[i] << " " << bit[j] << endl;
            if( x & bit[i] ) g[i].emplace_back( j );
            if( x & bit[j] ) g[j].emplace_back( i );
        }
    }
    for( int i = 1 ; i <= n ; i++ ) {
        bfs( i );
        int cc = 0;
        for( int j = 1 ; j <= n ; j++ ) if( !visit[j] ) cc = 1;
        if( !cc ) ans.emplace_back( i );
    }
    if( ans.empty() ) printf("-1");
    else for( int i : ans ) printf("%d ",i);
    return 0;
}