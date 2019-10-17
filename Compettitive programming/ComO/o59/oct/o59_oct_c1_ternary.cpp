#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 150;
int n, pre[N], in[N];
long long dp[N][N];

long long solve( int l, int r, int lp, int rp ) {
    //printf("%d %d\n",l,r);
    if( dp[l][r] != -1 ) return dp[l][r];
    if( l == r ) {
        if( pre[lp] != in[l] ) return dp[l][r] = 0LL;
        else return dp[l][r] = 1LL;
    }
    int pos = -1;
    long long left = 0, right = 0;
    for( int i = l ; i <= r ; i++ ) if( in[i] == pre[lp] ) {
        pos = i;
        break;
    }
    if( pos == -1 ) return dp[l][r] = 0;
    if( pos == l ) left = 1LL;
    else left = solve( l, pos - 1, lp + 1, lp + pos - l );
    if( pos == r ) right = 1LL;
    else {
        long long sol = solve( pos + 1, r, lp + pos - l + 1, rp );
        right = ( right +  2LL * sol ) % mod ;
        for( int i = r - 1 ; i > pos ; i-- ) right = ( right + solve( pos + 1, i, lp + pos - l + 1, lp - l + i ) * solve( i + 1, r, lp - l + i + 1, rp ) ) % mod;
    //printf("r : %lld %lld\n",right,sol);
    }
    //printf("L : %d R : %d pos : %d %lld %lld\n",l,r,pos,left,right);
    return dp[l][r] = ( left * right ) % mod;
}
int main()
{
    scanf("%d",&n);
    memset( dp, -1, sizeof dp );
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&pre[i]);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&in[i]);
    solve( 1, n, 1, n );
    printf("%lld",dp[1][n]);
    return 0;
}