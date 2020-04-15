#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int t;
long long n, l, r, sum[N];

void solve( int i ) {
    for( long long idx = i ; idx <= n-1 ; idx++ ) { 
        long long now = l - sum[idx-1];
        //printf("IDX %lld NOW %lld sum[idx] %lld\n",idx,now,sum[idx]);
        while( l <= r && l <= sum[idx] ) {
            if( now % 2 ) printf("%lld ",idx);
            else printf("%lld ",idx+now/2);
            l++, now++;
        } 
        //printf("L : %lld\n",l);
        if( l > r ) break;
    }
}
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        int chk = 0;
        scanf("%lld %lld %lld",&n,&l,&r);
        if( l == n*(n-1) + 1 ) {
            printf("1\n");
            continue ;
        }
        if( r == n*(n-1) + 1 ) {
            chk = 1;
            r--;
        }
        for( int i = 1 ; i <= n-1 ; i++ ) sum[i] = sum[i-1] + 2LL*( n-i );
        for( int i = 1 ; i <= n-1 ; i++ ) {
            if( sum[i-1] < l && l <= sum[i] ) {
                solve( i );
                break;
            }
        }
        if( chk ) printf("1");
        printf("\n");
    }
    return 0;
}