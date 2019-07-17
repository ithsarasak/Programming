#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second 
using namespace std;

const int N = 1e5 + 100;
int n, stt, hv[N], st[N], ft[N], ver[N], ti, m, leader[N], mon[N], sum;
long long ans;
priority_queue<int> q;
vector<int> g[N];

int pre( int now, int p ) {
    st[now] = ++ti, ver[ti] = now;
    int sz = 1; pii ret( 0, -1 );
    for( int i : g[now] ) if( i != p ) {
        int z = pre( i, now );
        sz += z; 
        ret = max( ret, pii( z, i ) );
    }
    ft[now] = ti, hv[now] = ret.y;
    return sz;
}

void sack( int now, int p, bool keep ) {
    for( int i : g[now] ) if( i != p && i != hv[now]) sack( i, now, false );
    if( hv[now] != -1 ) sack( hv[now], now, true );
    for( int u : g[now] ) if( u != p && u != hv[now] ) for( int i = st[u] ; i <= ft[u] ; i++ ) {
        sum += mon[ver[i]], q.emplace( mon[ver[i]] );
        while( sum > m ) {
            sum -= q.top();
            q.pop();
        }
    }
    sum += mon[now], q.emplace( mon[now] );
    while( sum > m ) {
        sum -= q.top();
        q.pop();
    }
    ans = max( ans, ( long long )( q.size() ) * ( long long )leader[now] );
    if( !keep ) { 
        sum = 0;
        q = priority_queue<int>();
    }
    return ;
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1, a ; i <= n ; i++ ) {
        scanf("%d %d %d",&a,&mon[i],&leader[i]);
        if( a ) g[a].emplace_back( i ), g[i].emplace_back( a );
        else stt = i;
    }
    pre( stt, 0 ), sack( stt, 0, true );
    printf("%lld",ans); 
    return 0;
