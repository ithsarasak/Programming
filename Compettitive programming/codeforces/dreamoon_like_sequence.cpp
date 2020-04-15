#include <bits/stdc++.h>

using namespace std;

long long dp[40], mod;
int d, t, mxbit;
long long solve( int bitnow ) {
    //printf("bit now %d %d\n",bitnow,mxbit);
    if( bitnow > mxbit ) return 1;
    if( bitnow == mxbit ) {
        return d - ( 1<<mxbit ) + 1ll;
    }
    long long &ret = dp[bitnow];
    if( ret != -1 ) return dp[bitnow];
    ret = 0;
    int nxt = bitnow + 1;
    int diff = ( 1<<nxt ) - ( 1<<bitnow );
    //printf("Diff : %d %d %d",diff,bitnow,nxt);
    for( int i = bitnow + 1 ; i <= mxbit + 1 ; i++ ) {
        ret = ( ret + ( diff * solve( i ) ) ) % mod;
    }
    return ret;
}
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        long long ans =0;
        memset( dp, -1, sizeof dp );
        scanf("%d %lld",&d,&mod);
        mxbit = log2( d );
       // printf("MX : %d\n",mxbit);
        for( int i = 0 ; i < mxbit ; i++ ) {
            //printf("MUL : %d\n",( ( 1<<(i+1) ) - ( 1<<i )));
            long long x = solve( i );
            //printf("SOLVE %d : %lld\n",i,x);
            //printf("SOLVE %d : %lld\n",i,solve(i));
            ans = ( ans + x ) % mod;
        }
        ans = ( ans + (d - ( 1<<mxbit ) + 1ll)) % mod;
        printf("%lld\n",ans);
    }
    return 0;
}