#include <bits/stdc++.h>
#define pii pair<int, int> 
#define t first
#define d second

using namespace std;

const int N = 2e5 + 10;

pii seg1[4*N], seg2[4*N];
int n, m, a, b, from[N], mark[N], dp[N], key[N], sum[N], rev[N];
vector<pii> g[N];
vector<int> path, dis;
queue<int> q;

void dfs( int now, int p ) {
    //printf("now p : %d %d\n",now,p);
    for( pii i : g[now] ) if( i.t != p ) {
        if( mark[i.t] ) dis.emplace_back( i.d );
        dfs( i.t, now );
        if( !mark[i.t] ) dp[now] = max( dp[now], dp[i.t] + i.d );
    }
}

void build( int l = 1, int r = n, int now = 1 ) {
    if( l == r ) {
        seg1[now].t = dp[key[l]] + sum[l];
        seg2[now].t = dp[key[l]] - sum[l];
        seg1[now].d = seg2[now].d = l;
        return ;
    }
    int mid = ( l + r ) >> 1;
    build( l, mid, now << 1 ), build( mid + 1, r, now << 1 | 1 );
    seg1[now] = max( seg1[now<<1], seg1[now<<1|1] );
    if( seg2[now<<1].t == seg2[now<<1|1].t ) seg2[now] = min( seg2[now<<1], seg2[now<<1|1] );
    else seg2[now] = max( seg2[now<<1], seg2[now<<1|1] );
    return ;
}

pii query( int ll, int rr, int ty, int l = 1, int r = n, int now = 1 ) {
    if( l > rr || r < ll ) return pii( -1e9, -1e9 );
    if( l >= ll && r <= rr ) {
        if( ty == 1 ) return seg1[now];
        else return seg2[now];
    }
    int mid = ( l + r ) >> 1;
    pii x = query( ll, rr, ty, l, mid, now << 1 ), y = query( ll, rr, ty, mid + 1, r, now << 1 | 1 );
    if( ty == 1 ) return max( x, y );
    else {
        if( x.t == y.t ) return min( x, y );
        else return max( x, y );
    }
}

int main()
{
    scanf("%d %d %d %d",&n,&m,&a,&b);
    for( int i = 1, f, t, d ; i <= n - 1 ; i++ ) {
        scanf("%d %d %d",&f,&t,&d);
        g[f].emplace_back( pii( t, d ) ), g[t].emplace_back( pii( f, d ) );
    }
    from[a] = -1;
    q.emplace( a );
    while( !q.empty() ) {
        int t = q.front(); q.pop();
        for( pii i : g[t] ) if( !from[i.t] ) {
            from[i.t] = t, q.emplace( i.t );
        }
    }
    int now = b;
    while( from[now] != -1 ) path.emplace_back( now ), mark[now] = 1, now = from[now];
    path.emplace_back( a );
    reverse( path.begin(), path.end() );
    dfs( a, 0 );
   // for( int i : dis ) printf("%d ",i);
    //printf("\n");
    for( int i = 0 ; i < path.size() ; i++ ) {
        key[i+1] = path[i], rev[path[i]] = i+1;
        if( i >= 1 ) sum[i+1] = sum[i] + dis[i-1];
        //printf("dp %d\n",dp[path[i]]);
    }
    // for( int i : path ) printf("%d ",i);
    // printf("\n");
    // for( int i = 1 ; i <= path.size() ; i++ ) printf("%d ",sum[i]);
    // printf("\n");
    build();
    // for( int i = 1 ; i <= path.size() ; i++ ) printf("%d ",query( i, i, 1 ) );
    // printf("\n");
    // for( int i = 1 ; i <= path.size() ; i++ ) printf("%d ",query( i, i, 2 ) );
    // printf("\n");
    while( m-- ) {
        int f, t;
        scanf("%d %d",&f,&t);
        if( rev[f] > rev[t] ) swap( f, t );
        //printf("%d %d\n",rev[f],rev[t]);
        pii ma = query( rev[f], rev[t] - 1, 2 ), ma2 = query( rev[f] + 1, rev[t], 1 );
        //printf("%d %d %d %d\n",ma.t,ma.d,ma2.t,ma2.d);
        int ans = ( ma.t + query( ma.d + 1, rev[t], 1 ).t );
        int ans2 = ( ma2.t + query( rev[f], ma.d - 1, 2 ).t );
        //printf("%d %d\n",ans,ans2);
        printf("%d\n",max( ans, ans2 ));
    }
    return 0;
}

