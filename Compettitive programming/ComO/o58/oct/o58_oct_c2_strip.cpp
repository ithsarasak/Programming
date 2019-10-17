#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define iii tuple<int, int, int>

using namespace std;

const int N = 1e5 + 10;
int n, m, k, ans[10100], fen[N];
vector<iii> sw[N];
vector<pii> que[N];

void update( int idx, int va ) { for( int i = idx ; i < N ; i += ( i & -i ) ) fen[i] += va; }

int query( int idx ) {
    int ret = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ) ret += fen[i];
    return ret;
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1, x1, y1, x2, y2 ; i <= n ; i++ ) {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if( x1 > x2 ) swap( x1, x2 );
        if( y1 > y2 ) swap( y1, y2 );
        x1++, x2++, y1++, y2++;
        sw[x1].emplace_back( iii( y1, y2, 1 ) ), sw[x2+1].emplace_back( iii( y1, y2, -1 ) );
    }
    for( int i = 1, x, y ; i <= m ; i++ ) {
        scanf("%d %d",&x,&y);
        x++, y++;
        que[x].emplace_back( pii( y, i ) );
    }
    for( int i = 1 ; i < N ; i++ ) {
        for( iii j : sw[i] ) {
            int a, b, c;
            tie( a, b, c ) = j;
            update( a, c ), update( b + 1, -1*c );
        }
        for( pii j : que[i] ) {
            int a, b;
            tie( a, b ) = j;
            ans[b] = query( a );
        }
    }
    for( int i = 1 ; i <= m ; i++ ) printf("%d\n",ans[i]);
    return 0;
}