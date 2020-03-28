#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

const int N = 2e5 + 10;
int n, k, que[N];
long long ans;
int seg[4*N], fen[N];
vector<int> coord;
vector<pii> quer, card;

void update( int pos, int val, int l = 1, int r = k, int idx = 1 ) {
    //printf("l %d r %d\n",l,r);
    if( l == r ) return void( seg[idx] = val );
    int mid = l + r >> 1;
    if( pos <= mid ) update( pos, val, l, mid, idx<<1 );
    else update( pos, val, mid+1, r, idx<<1|1 );
    seg[idx] = max( seg[idx<<1], seg[idx<<1|1] );
}

int query( int ll, int rr, int l = 1, int r = k, int idx = 1 ) {
    if( ll > rr ) return 0;
    if( l > rr || r < ll ) return 0;
    if( l >= ll && r <= rr ) return seg[idx];
    int mid = l + r >> 1;
    return max( query( ll, rr, l, mid, idx<<1 ), query( ll, rr, mid+1, r, idx<<1|1 ) );
}

void fup( int idx ) { for( int i = idx ; i < N ; i+= i & -i ) fen[i] += 1; }
int fque( int idx ) {
    int ret = 0;
    for( int i = idx ; i > 0 ; i -= i & -i ) ret += fen[i];
    return ret;
}

int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1, a, b ; i <= n ; i++ ) {
        scanf("%d %d",&a,&b);
        card.emplace_back( a, b );
    }
    for( int i = 1, a ; i <= k ; i++ ) {
        scanf("%d",&que[i]);
        coord.emplace_back( que[i] );
    }
    sort( coord.begin(), coord.end() );
    for( int i = 1 ; i <= k ; i++ ) {
        que[i] = lower_bound( coord.begin(), coord.end(), que[i] ) - coord.begin() + 1;
        //printf("%d %d\n",i,que[i]);
        update( que[i], i );
    }
    //printf("%d\n",query( 1, k ) );
    for( int i = 0 ; i < card.size() ; i++ ) {
        int a = min( card[i].x, card[i].y ), b = max( card[i].x, card[i].y );
        a = lower_bound( coord.begin(), coord.end(), a ) - coord.begin() + 1;
        b = upper_bound( coord.begin(), coord.end(), b-1 ) - coord.begin();
        int qq = query( a, b );
        //printf("%d %d %d %d\n",i,a,b,qq);
        if( qq ) 
            if( card[i].x < card[i].y ) swap( card[i].x, card[i].y );
        quer.emplace_back( qq, i );
    }
    sort( quer.begin(), quer.end(), greater<pii>() );
    int ptr = k;
    for( pii i : quer ) {
        //printf("%d %d\n",i.x,i.y);
        while( ptr > 0 && ptr > i.x ) {
            //printf("idx ptr%d %d\n",que[ptr],ptr);
            fup( que[ptr] );
            ptr--;
        }
        int b = max( card[i.y].x, card[i.y].y );
        int idx = lower_bound( coord.begin(), coord.end(), b ) - coord.begin();
        int cnt = fque( N-1 ) - fque( idx );
        //printf("%d\n",fque(N-1));
        //printf("idx%d cnt%d\n",idx,cnt);
        if( cnt % 2 ) swap( card[i.y].x, card[i.y].y );
        ans += ( long long )card[i.y].x;
        //printf("%d %d\n",i.y,card[i.y].x);
    }
    printf("%lld",ans);
    return 0;
}