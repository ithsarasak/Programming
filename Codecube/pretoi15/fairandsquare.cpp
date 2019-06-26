#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e3 + 510;

vector<int> coord;

void update2( int x, int int k ) { for( int i = x + 1; i < N; i += i & -i ) fen2[i] += k; }
void update( int x, int k) {  for( int i = x + 1 ; i < N;  i += i & -i ) fen[i] += k; }

int query( int x, int k = 0) {
    for(int i = x + 1 ; i > 0 ; i -= i & -i ) k += fen[i];
    return k;
}

int query2( int x, int k = 0) {
    for( int i = x + 1 ; i > 0 ; i -= i & -i ) k += fen2[i];
    return k;
}

int get( int x ) { return lower_bound( coord.begin(), coord.end(), x ) - coord.begin() + 1; }

int n, k, house[N], dp[N][60], cost[N][N], fen[N], fen2[N];

int main() 
{
    scanf("%d %d", &n, &k);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d", house[i] );
        coord.emplace_back( a[i] );
    }
    sort( coord.begin(), coord.end() ) ;
    coord.resize( unique( coord.begin(), coord.end() ) - coord.begin() );
    for( int l = 1; l <= n; l++) {
        int cnt = 0;
        ordered_set<pii> s; 
        memset( fen, 0, sizeof fen ), memset( fen2, 0, sizeof fen2 );
        for( int i = l ; i <= n ; i++ ) {
            update( get( a[i] ), 1 );
            update2( get( a[i] ), a[i] );
            s.insert( pii( a[i], ++cnt ) );
            int median = s.find_by_order( ( ( int )S.size() - 1 ) / 2 )->x;
            int noi = query(fen, get( median ) - 1 ), mak = query(fen, coord.size()) - query(fen, get(median));
            int suml = query(fen2, get(median)-1), sumr = query(fen2, coord.size()) - query(fen2, get(median));
            cost[l][i] = (median * noi) - suml + sumr - (median * cntr);
        }
    }
    for(int i = 1; i <= n; i++) dp[i][0] = 1e18;
    for(int x = 1; x <= k; x++) for(int i = 1; i <= n; i++) {
        dp[i][x] = 1e18;
        for(int j = 0; j < i; j++) dp[i][x] = min(dp[i][x], dp[j][x-1] + cost[j+1][i]);
    }
    int ans = 1e18;
    for(int i = 1; i <= k; i++) ans = min(ans, dp[n][i]);
    printf("%lld\n", ans);

    return 0;
}