#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+5;

int n, ans;
int A[N], pre[N], suf[N];
bitset<2*N> chk;
set<int> S;

int main() {
    freopen( "cardgame.in", "r", stdin );
    freopen( "cardgame.out", "w", stdout );

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&A[i]);
        chk[A[i]] = true;
    }

    for( int i = 1 ; i <= 2*n ; i++ ) if( !chk[i] ) S.emplace( i );
    for( int i = 1 ; i <= n ; i++ ) {
        auto it = S.lower_bound(A[i]);
        pre[i] = pre[i-1];
        if( it != S.end() ) ++pre[i], S.erase( it );
    }
    S.clear();
    for( int i = 1 ; i <= 2*n ; i++ ) if( !chk[i] ) S.emplace( i );
    for( int i = n ; i ; i-- ) {
        auto it = S.lower_bound( A[i] );
        suf[i] = suf[i+1];
        if( it != S.begin() ) ++suf[i], S.erase( --it );
    }
    for( int i = 0 ; i <= n ; i++ ) ans = max( ans, pre[i] + suf[i+1] );
    printf("%d\n", ans);

    return 0;
}