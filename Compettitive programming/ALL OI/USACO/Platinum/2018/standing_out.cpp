#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

char s1[N], s[N];
int x, n, id[N], sz[N], lcp[N], suf[N], pos[N], t[N*4], tmp[N], L[N], R[N];
long long ans[N];

void build( int l = 1, int r = n, int idx = 1 ) {
    if( l == r ) return void( t[idx] = lcp[l] );
    int mid = l + r >> 1;
    build( l, mid, idx<<1 ), build( mid+1, r, idx<<1|1 );
    t[idx] = min( t[idx<<1], t[idx<<1|1] );
    return ;
}

int query( int ll, int rr, int l = 1, int r = n, int idx = 1 ) {
    if( l > rr || r < ll ) return 1e9;
    if( l >= ll && r <= rr ) return t[idx];
    int mid = l + r >> 1;
    return min( query( ll, rr, l, mid, idx<<1 ), query( ll, rr, mid+1, r, idx<<1|1 ) );
}

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
        while( s[i+k] != '#' && s[j+k] != '#' && s[i+k] == s[j+k] ) k++;
        lcp[pos[i]] = k;
        if( k ) k--;
    }
}

int main() 
{
    freopen( "standingout.in", "r", stdin );
    freopen( "standingout.out", "w", stdout );
    s[0] = '#'; 
    scanf("%d",&x);
    for( int i = 1 ; i <= x ; i++ ) {
        scanf("%s",s1);
        int len = strlen( s1 );
        for( int j = 0, k = n+1 ; j < len ; j++, k++ ) s[k] = s1[j];
        n += len + 1;
        s[n] = '#';
        for( int j = n-1 ; s[j] != '#' ; j-- ) sz[j] = n - j, id[j] = i;
        id[n] = -1;
    }
    n--;
    computeSuffix(), computeLCP(), build();
    L[1] = -1;
    for( int i = 2, j = 1 ; i <= n ; i++ ) {
        if( s[suf[i]] == '#' ) { L[i] = -1; continue ;}
        while( j + 1 < i && id[suf[j+1]] != id[suf[i]] ) j++;
        if( id[suf[j]] != -1 && id[suf[j]] != id[suf[i]] ) L[i] = j;
        else L[i] = -1;
    }
    R[n] = -1;
    for( int i = n-1, j = n ; i >= 1 ; i-- ) {
        if( s[suf[i]] == '#' ) { R[i] = -1; continue ;}
        while( j - 1 > i && id[suf[j-1]] != id[suf[i]] ) j--;
        if( id[suf[j]] != -1 && id[suf[j]] != id[suf[i]] ) R[i] = j;
        else R[i] = -1;
    }
    for( int i = 1 ; i <= n ; i++ ) if( id[suf[i]] != -1 ) {
        int mx = 0;
        if( L[i] != -1 ) mx = max( mx, query( L[i], i-1 ) );
        if( R[i] != -1 ) mx = max( mx, query( i, R[i]-1 ) );
        if( i != n && id[suf[i+1]] == id[suf[i]] ) mx = max( mx, lcp[i] );
        //printf("L : %d i : %d R: %d\nID : %d\n%d %d %d\n",L[i],i,R[i],id[suf[i]],suf[i],sz[suf[i]],mx);
        ans[id[suf[i]]] += sz[suf[i]] - mx;
    }
    for( int i = 1 ; i <= x ; i++ ) printf("%lld\n",ans[i]);
    return 0;
}