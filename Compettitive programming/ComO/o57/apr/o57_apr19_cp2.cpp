#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m, t[N*4], suf[N], pos[N], tmp[N], lcp[N];
set<int> se;
char s[N];

void computeSuffix() {
    tmp[1] = 1;
    for( int i = n ; i >= 1 ; i-- ) suf[i] = i, pos[i] = s[i];
    for( int k = 1 ; k <= n ; k *= 2 ) {
        auto cmp = [&]( int a, int b ) {
            if( pos[a] != pos[b] ) return pos[a] < pos[b];
            a += k, b += k;
            return ( a <= n && b <= n ) ? pos[a] < pos[b] : a > b;
        };
        sort( suf + 1, suf + 1 + n, cmp );
        for( int i = 2 ; i <= n ; i++ ) tmp[i] = tmp[i-1] + cmp( suf[i-1], suf[i] );
        for( int i = 1 ; i <= n ; i++ ) pos[suf[i]] = tmp[i];
    }
 }

void computeLCP() {
    int k = 0;
    for( int i = 1 ; i <= n ; i++ ) {
        if( pos[i] == n ) {
            lcp[pos[i]] = k = 0;
            continue ;
        }
        int j = suf[pos[i]+1];
        while( i + k <= n && j + k <= n && s[i+k] == s[j+k] ) k++;
        lcp[pos[i]] = k;
        if( k ) k--;
    }
}

void build( int l = 1, int r = n, int idx = 1 ) {
    if( l == r ) return void( t[idx] = lcp[l] );
    int mid = l + r >> 1;
    build( l, mid, idx<<1 ), build( mid+1, r, idx<<1|1 );
    t[idx] = min( t[idx<<1], t[idx<<1|1] );
    return ;
}

int query( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    if( ll > rr ) swap( ll, rr );
    if( l > rr || r < ll ) return 1e9;
    if( l >= ll && r <= rr ) return t[idx];
    int mid = l + r >> 1;
    return min( query( ll, rr, l, mid, idx<<1 ), query( ll, rr, mid+1, r, idx<<1|1 ) );
}

int main()
{
    scanf("%d %d",&n,&m);
    scanf("%s",s+1);
    computeSuffix(), computeLCP(), build();
    se.insert( pos[1] );
    while( m-- ) {
        int a, b;
        scanf("%d %d",&a,&b);
        if( a == 1 ) se.insert( pos[b] );
        else {
            int mx = 0;
            if( se.find( pos[b] ) != se.end() ) {
                printf("%d\n",n-b+1);
                continue ;
            }
            auto it = se.upper_bound( pos[b] );
            if( it != se.end() ) mx = max( mx, query( pos[b], (*it) - 1 ) );
            if( it != se.begin() ) {
                it--;
                mx = max( mx, query( (*it), pos[b] - 1 ) );
            }
            printf("%d\n",mx);
        }
    }
    return 0;
}