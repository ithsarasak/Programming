#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, int>
#define x first 
#define y second 

using namespace std;

const int N = 1e5 + 100;
int n, stt, hv[N], st[N], ft[N], ver[N], ti, m, leader[N], mon[N], fw2[N];
long long fw1[N], ans;
vector<pll> coord;
vector<int> g[N];

int get( pll x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + 1; }

void up1( int idx, long long va ) { if(!idx) return; for( int i = idx ; i < N ; i += ( i & -i ) ) fw1[i] += va; }

void up2( int idx, int va ) { if(!idx) return; for( int i = idx ; i < N ; i += ( i & -i ) ) fw2[i] += va; }

long long query1( int idx ) {
    long long sum = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ) sum += fw1[i];
    return sum;
}

long long query2( int idx ) {
    long long sum = 0;
    for( int i =  idx ; i > 0 ; i -= ( i & -i ) ) sum += fw2[i];
    return sum;
}

int pre( int now, int p ) {
    st[now] = ++ti;
    ver[ti] = now;
    int sz = 1; pii ret( 0, -1 );
    for( int i : g[now] ) if( i != p ) {
        int z = pre( i, now );
        sz += z; 
        ret = max( ret, pii( z, i ) );
    }
    ft[now] = ti;
    hv[now] = ret.y;
    return sz;
}

void sack( int now, int p, bool keep ) {
    for( int i : g[now] ) if( i != p && i != hv[now]) sack( i, now, false );
    if( hv[now] != -1 ) sack( hv[now], now, true );
    for( int u : g[now] ) if( u != p && u != hv[now] ) for( int i = st[u] ; i <= ft[u] ; i++ ) {
         // printf("%d iiii\n",i);
         int temp = get( pll( ( long long )mon[ver[i]], ver[i] ) );
         // printf("now : %d temp : %d %lld %d %d\n",now,temp,mon[ver[i]],i,ver[i]);
         up1( temp, mon[ver[i]] ), up2( temp, 1 );
    }
    int temp = get( pll( ( long long )mon[now], now ) );
    up1( temp, mon[now] ), up2( temp, 1 );
    int l = 0;
    long long sum = 0;
    for(int i = 17; ~i; i--) {
        if(l + (1 << i) < N && sum + fw1[l + (1 << i)] <= m) {
            l += (1 << i);
            sum += fw1[l];
        } 
    }
    ans = max( ans, ( long long )query2( l ) * ( long long )leader[now] );
    if( !keep ) {
        for( int i = st[now] ; i <= ft[now] ; i++ ) {
            int temp = get( pll( ( long long )mon[ver[i]], ver[i] ) );
            up1( temp, -1*( long long )mon[ver[i]] ), up2( temp, -1 );    
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1, a ; i <= n ; i++ ) {
        scanf("%d %d %d",&a,&mon[i],&leader[i]);
        if( a ) g[a].emplace_back( i ), g[i].emplace_back( a );
        else stt = i;
        coord.emplace_back( pll( ( long long )mon[i], i ) );
    }
    sort( coord.begin(), coord.end() );
    pre( stt, 0 ), sack( stt, 0, true );
    printf("%lld",ans); 
    return 0;
}