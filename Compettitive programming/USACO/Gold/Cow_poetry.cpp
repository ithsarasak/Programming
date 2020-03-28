#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
long long mod = 1e9 + 7;
int n, m, k, sy[N], ty[N], cnt[30];
long long sum[N], dp[N], all[N], ans = 1;

long long mul( long long num, int pow ) {
    long long ret = 1;
    for( ; pow ; pow >>= 1 ) {
        if( pow & 1 ) ret = ( ret * num ) % mod;
        num = ( num * num ) % mod;
    }
    return ret;
}  

int main()
{
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d %d",&sy[i],&ty[i]);
    for( int i = 1 ; i <= m ; i++ ) {
        char a;
        scanf(" %c",&a);
        cnt[a-'A']++;
    }
    dp[0] = 1;
    for( int i = 1 ; i <= k ; i++ ) {
        for( int j = 1 ; j <= n ; j++ ) {
            if( i < sy[j] ) continue ;
            dp[i] = ( dp[i] + dp[i-sy[j]] ) % mod;
        }
    }
    for( int i = 1 ; i <= n ; i++ ) sum[ty[i]] = ( sum[ty[i]] + dp[k-sy[i]] ) %  mod; 
    for( int i = 0 ; i < 26 ; i++ ) {
        if( !cnt[i] ) continue ;
        long long all = 0;
        for( int j = 1 ; j <= n ; j++ ) {
            all = ( all + mul( sum[j], cnt[i] ) ) % mod;
        }
        ans = ( ans * all ) % mod;
        //printf("%lld %d\n",all,i);
    }
    printf("%lld",ans);
    return 0;
}