#include <bits/stdc++.h>
#define iii tuple<long long, long long, long long>
#define pii pair<long long, long long>
#define x first
#define y second

using namespace std;

const int N = 3e5 + 10;
long long n, d;
long long t[4*N], inf = 1e17, lz[4*N];
long long sum[N];
vector<pii> sta, sta2;
vector<long long> coord;
vector<iii> que;

void push( int l, int r, int idx ) {
    if( !lz[idx] ) return;
    t[idx] += lz[idx];
    if( l != r ) lz[idx<<1] += lz[idx], lz[idx<<1|1] += lz[idx];
    lz[idx] = 0;
}

void update( int ll, int rr, long long va, int l = 1, int r = n-1, int idx = 1 ) {
    push( l, r, idx );
    //printf("%d %d %d %d\n",l,r,ll,rr);
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) {
        lz[idx] += va;
        push( l, r, idx );
        return ;
    }
    int mid = l + r >> 1;
    update( ll, rr, va, l, mid, idx<<1 ), update( ll, rr, va, mid+1, r, idx<<1|1 );
    t[idx] = min( t[idx<<1], t[idx<<1|1] );
}

int get( int x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin(); }

int main()
{
    scanf("%lld %lld",&n,&d);
    coord.emplace_back( 0 ), coord.emplace_back( 1ll*d );
    for( int i = 1  ; i <= n ; i++ ) {
        long long x, a, b;
        scanf("%lld %lld %lld",&x,&a,&b);
        sta2.emplace_back( x, a );
        que.emplace_back( b, x, a );
        coord.emplace_back( x );
    }
    sort( coord.begin(), coord.end() ), sort( que.begin(), que.end() );
    coord.resize( unique( coord.begin(), coord.end() ) - coord.begin() );
    for( int i = 0 ; i < sta2.size() ; i++ ) {
        int x = get( sta2[i].x );
        sum[x] += sta2[i].y;
    }
    for( int i = 0 ; i < coord.size() ; i++ ) sta.emplace_back( coord[i], sum[i] );
    n = sta.size();
    for( int i = 1 ; i < coord.size() ; i++ ) update( i, i, -1LL*coord[i] );
    for( int i = 1 ; i < sta.size() - 1 ; i++ ) update( i+1, n-1, sta[i].y ); 
    for( int i = 0 ; i < que.size() ; ) {
        long long b, x, a;
        int p;
        tie( b, x, a ) = que[i];
        if( -1ll*t[1] <= b ) {
            printf("%lld\n",max( 0LL, -1LL*t[1] ) );
            return 0;
        }
        p = get( x );
        update( p+1, n-1, -1ll*a );
        i++;
        while( i < que.size() ) {
            long long b2, x2, a2;
            int p2;
            tie( b2, x2, a2 ) = que[i];
            if( b2 != b ) break;
            p2 = get( x2 );
            update( p2+1, n-1, -1ll*a2 );
            b = b2, x = x2, a = a2;
            i++;
        }
    }
    printf("%d",d);
    return 0;
}