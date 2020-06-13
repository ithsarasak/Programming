#include <bits/stdc++.h>

using namespace std;

void computeSuffix() {
    for( int i = 1 ; i <= n ; i++ ) suf[i] = i, pos[i] = s[i];
    for( int k = 1 ; k <= n ; k *= 2 ) {
        auto cmp = [&]( int a, int b ) {
            if( pos[a] != pos[b] ) return pos[a] < pos[b];
            a += k, b += k;
            return a <= n && b <= n ? pos[a] < pos[b] : a > b;
        }
        sort( suf + 1, suf + 1 + n, cmp );
        for( int i = 2 ; i <= n ; i++ ) tmp[i] = tmp[i-1] + cmp( suf[i], suf[i-1] );
        for( int i = 1 ; i <= n ; i++ ) pos[suf[i]] = tmp[i];
    }
}

void computeLCP() {
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

int main()
{
    scanf("%d %d",&n,&q);
    scanf("%s",s+1);
    computeSuffix(), computeLCP();
    while( q-- ) {
        scanf("%d %d",&t1,&t2);
        for( int i = 1 ; i <= t1 ; i++ ) {
            scanf("%d",&a);
            v.emplace_back( pii( a, 0 ) );
        }
        for( int i = 1 ; i <= t2 ; i++ ) {
            scanf("%d",&b);
            v.emplace_back( pii( b, 0 ) );
        }
        
    }
    return 0;
}