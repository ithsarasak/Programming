#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50;
int n, k, co, col[N], visit[N], ind[N], posi[N];
vector<int> g[N], g2[N], all[N], ans;
stack<int> st;
char s[N][35];

void dfs( int now, int p ) {
    visit[now] = 1;
    for( int i : g[now] ) if( i != p && !visit[i] ) dfs( i, now );
    st.push( now );
}

void dfs2( int now, int p ) {
    col[now] = co;
    for( int i : g2[now] ) if( i != p && !col[i] ) dfs2( i, now );
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%s",&s[i][1]);
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= k ; j++ )
        if( s[i][j] == '1' ) g[i].emplace_back( n + j ), g2[n+j].emplace_back( i ), posi[n+j]++;
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= k ; j++ )
        if( s[i][j] == '0' && posi[n+j] ) g[n+j].emplace_back( i ), g2[i].emplace_back( n+j );
    for( int i = 1 ; i <= n ; i++ ) if( !visit[i] ) dfs( i, 0 );
    while( !st.empty() ) {
        int t = st.top(); st.pop();
        if( col[t] ) continue ;
        ++co;
        dfs2( t, 0 );
    }
    for( int i = 1 ; i <= n + k ; i++ ) {
        all[col[i]].emplace_back( i );
        for( int j : g[i] ) if( col[j] != col[i] ) ind[col[j]]++;
    }
    int cnt = 0;
    for( int i = 1 ; i <= co ; i++ ) {
        if( ind[i] == 0 && cnt == 1 ) return !printf("-1");
        else if( ind[i] == 0 ) {
            for( int j : all[i] ) if( j <= n ) ans.emplace_back( j );
            cnt++;
        }
    }
    sort( ans.begin(), ans.end() );
    for( int i : ans ) printf("%d ",i);
    return 0;
}