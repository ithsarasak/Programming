#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 2e5 + 100;
int n, va[N], ans, sum[N], dp[N][5], in[N], col[N];
vector<int> g[N], cyc;

void solve() {
    deque<pii> q;
    int sz = cyc.size() - 1;
    for( int i = 1 ; i <= sz ; i++ ) sum[i] = sum[i-1] + dp[cyc[i]][1];
    ans = max( ans, sum[sz] );
    for( int i = 2 ; i <= sz ; i++ ) {
        while( !q.empty() && q.back().x < dp[cyc[i]][2] + sum[i-1] ) q.pop_back();
        q.emplace_back( pii( dp[cyc[i]][2] + sum[i-1], i ) );
    }
    ans = max( ans, dp[cyc[1]][2] - dp[cyc[1]][1] + q.front().x );
    for( int i = 1 ; i < sz ; i++ ) {
        if( q.front().y == i + 1 ) q.pop_front();
        while( !q.empty() && q.back().x < sum[sz] + sum[i-1] + dp[cyc[i]][2] ) q.pop_back(); 
        q.emplace_back( pii( sum[sz] + sum[i-1] + dp[cyc[i]][2], i ) );
        ans = max( ans, dp[cyc[i+1]][2] + q.front().x - sum[i+1] );
    }
    return ;
}

void findcyc(int u, int p) {
    static vector<int> s;
    col[u] = 1;
    s.emplace_back( u );
    for( int v : g[u] ) if( v != p ) {
        if( !col[v] ) findcyc( v, u );
        else if( col[v] == 1 ) for( int i = s.size()-1 ; ~i ; i-- ) {
            cyc.emplace_back( s[i] );
            in[s[i]] = 1;
            if(s[i] == v) break;
        }
    }
    s.pop_back();
    col[u] = 2;
}

int mic(int u, int p) {
    vector<int> ret = { 0, 0, 0 };
    for( int v : g[u] ) if( !in[v] && v != p ) ret.emplace_back( mic( v, u ) );
    sort( ret.begin(), ret.end() , greater<int>() );
    for( int i = 1 ; i <= 3 ; i++ ) dp[u][i] = dp[u][i-1] + ret[i-1];
    ans = max( ans, dp[u][3] );
    return dp[u][2];
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&dp[i][0]);
    for( int i = 1, u, v ; i <= n ; i++ ) {
        scanf("%d %d",&u,&v);
        u++, v++;
        g[u].emplace_back( v ), g[v].emplace_back( u );
    }   
    cyc.emplace_back( 0 );
    findcyc( 1, -1 );
    for( int i : cyc ) mic( i, -1 );
    solve();
    printf("%d",ans);
    return 0;
}