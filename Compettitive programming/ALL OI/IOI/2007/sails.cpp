#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int fen[N], n, mh;
long long ans;
vector<pii> v;

void up( int l, int r ) {
    if( l > r ) return ;
    for( int i = l ; i < N ; i += ( i & -i ) ) fen[i] += 1;
    for( int i = r + 1 ; i < N ; i += ( i & -i ) ) fen[i] += -1;
}

int query( int x ) {
    int ret = 0;
    for( int i = x ; i > 0 ; i -= ( i & -i ) ) ret += fen[i];
    return ret;
}

int main()
{
    scanf("%d",&n);
    for( int i = 1, h, k ; i <= n ; i++ ) {
        scanf("%d %d",&h,&k);
        mh = max( mh, h );
        v.emplace_back( pii( h, k ) );
    }
    sort( v.begin(), v.end() );
   // printf("\n");
    for( int i = 0 ; i < ( int )v.size() ; i++ ) {
        int x = v[i].x - v[i].y + 1;
        int t = query( x ), l = 1, r = v[i].x, lb, rb;
        while( l < r ) {
            int mid = ( l + r + 1 ) >> 1;
            if( query( mid ) >= t ) l = mid;
            else r = mid - 1;
        }
        rb = l;
        l = 1, r = v[i].x;
        while( l < r ) {
            int mid = ( l + r ) >> 1;
            if( query( mid ) <= t ) r = mid;
            else l = mid + 1;
        }
        lb = l;
        int temp = min( v[i].x, rb ) - max( x, lb ) + 1;
        up( rb + 1, rb + v[i].y - temp ), up( lb, lb + temp - 1 );
        //printf("%d %d %d %d %d %d %d\n",lb,rb,temp,v[i].x,v[i].y,x,t);
    }
    for( int i = 1 ; i <= mh ; i++ ) {
        long long x = ( long long )query( i );
        //printf("%lld ",x);
        ans += ( x - 1 ) * x / 2;
    }
    printf("%lld",ans);
    return 0;
}