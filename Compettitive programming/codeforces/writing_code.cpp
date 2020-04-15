#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10;

int n, m, b, a[N];
long long dp[N][N][N], mod;

long long solve( int pos, int line, int bug ) {
    if( line < 0 || bug > 500 ) return 0;
    long long &ret = dp[pos][line][bug];
    if( ret != -1 ) return ret;
    if( bug > b ) return ret = 0;
    if( pos == n + 1 && bug <= b && line == 0 ) return ret = 1; 
    if( pos >= n + 1 && line != 0 ) return ret = 0;
    ret = 0;
    for( int i = 0 ; i <= line ; i++ ) ret = ( ret + solve( pos + 1, line - i, bug + a[pos] * i ) ) % mod;
    //printf("%d %d %d %lld\n",pos,line,bug,ret);
    return ret;
}

int main()
{
    scanf("%d %d %d %lld",&n,&m,&b,&mod);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
    memset( dp, -1, sizeof dp );
    printf("%lld",solve(1,m,0));
    return 0;
}