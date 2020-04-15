#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e3+5;
 
struct item {
    long long cnt, idx; int pos;
    item( long long cnt, long long idx, int pos ) : cnt( cnt ), idx( idx ), pos( pos ) {}
    friend bool operator<( const item &a, const item &b ) {
        return a.cnt < b.cnt;
    }
};
 
priority_queue<item> q;
int n, m, k;
long long a, b, c, t, ans;
long long st[N], dist[N];
 
long long get_cnt( int i, long long l, long long r ) {
    long long ti = ( l - st[i] ) * c + dist[i];
    if( ti > t ) return 0;
    return min( ( t - ti ) / a + 1, r - l + 1 );
}

int main() 
{
    scanf("%d %d %d",&n,&m,&k);
    scanf("%lld %lld %lld %lld",&a,&b,&c,&t);
    for( int i = 1 ; i <= m ; i++ ) {
        scanf("%lld",&st[i]);
        if( i > 1 ) dist[i] = b*( st[i] - st[i-1] ) + dist[i-1];
    }
    for( int i = 1 ; i < m ; i++ ) if( dist[i] <= t ) {
        if( dist[i] + ( st[i+1] - st[i] - 1 ) * a <= t ) {
            ans += st[i+1] - st[i];
            continue ;
        }
        long long add = ( t - dist[i] ) / a + 1;
        ans += add;
        q.emplace( get_cnt( i, st[i] + add, st[i+1] - 1 ), st[i] + add, i );
    }
    k -= m;
    for( int i = 1 ; i <= k ; i++ ) if( !q.empty() ) {
        item now = q.top(); q.pop();
        ans += now.cnt;
        long long pos = now.idx + now.cnt;
        if( pos >= st[now.pos + 1] ) continue;
        q.emplace( get_cnt( now.pos, pos, st[now.pos + 1] - 1), pos, now.pos );   
    }
    if( dist[m] < t ) ans++;
    printf("%lld\n", ans-1);
}
