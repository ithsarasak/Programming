#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define a first
#define b second

using namespace std;

const int N = 1e5 + 10;
int n, t, m1, m2;
long long seg[4*N], lz[4*N];
vector<long long> coord;
vector<pll> query;
unordered_map<int,int> mp;

int get( long long x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + ( ++mp[x] ); }

void push( int now, int l, int r ) {
    if( !lz[now] ) return ;
    seg[now] += lz[now];
    if( l != r ) lz[now<<1] += lz[now], lz[now<<1|1] += lz[now];
    lz[now] = 0;
    return ;
}
void up( int ll, int rr, int va, int l = 1, int r = n, int now = 1 ) {
    push( now, l, r );
    if( l > rr || r < ll || l > r ) return ;
    if( l >= ll && r <= rr ) {
        seg[now] += va;
        if( l != r ) lz[now<<1] += va, lz[now<<1|1] += va;
        return ;
    }
    int mid = ( l + r ) >> 1;
    up( ll, rr, va, l, mid, now << 1 ), up( ll, rr, va, mid + 1, r, now << 1 | 1 );
    seg[now] = max( seg[now<<1], seg[now<<1|1] ); 
} 

int main()
{
    scanf("%d %d %d %d",&n,&t,&m1,&m2);
    if( t == 2 ) return !printf("vbvb");
    for( int i = 1 ; i <= n ; i++ ) {
        long long a, b;
        scanf("%lld %lld",&a,&b);
        coord.emplace_back( b ), query.emplace_back( pll( a, b ));
    }
    sort( coord.begin(), coord.end() );
    for( pll i : query ) {
        int idx = get( i.b );
        up( 1, idx, i.a ), up( idx, idx, i.b );
        printf("%lld\n",seg[1]);
    }
    return 0;
}