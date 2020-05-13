#include <bits/stdc++.h>

using namespace std;

const int N = 205;
long long dp[N][N][N], mm = 1e18;
int s, m, q, mod[15][N];
int mx = 200;
int main()
{
    scanf("%d %d %d",&s,&m,&q);
    for( int i = 0 ; i <= 9 ; i++ ) mod[i][0] = i % m;
    for( int i = 1 ; i <= 200 ; i++ ) {
        for( int j = 0 ; j <= 9 ; j++ ) {
            mod[j][i] = ( mod[j][i-1] * 10 ) % m;
        }
    }
    dp[mx+1][0][0] = 1;
    for( int i = mx ; i >= 1 ; i-- ) for( int j = 0 ; j < m ; j++ ) for( int k = 0 ; k <= s ; k++ ) 
        for( int l = 0 ; l <= 9 && l <= k ; l++ ) {
            int dif = ( j - mod[l][mx-i] + m ) % m;
            if( dp[i][j][k] + dp[i+1][dif][k-l] >= mm ) dp[i][j][k] = mm;
            else dp[i][j][k] += dp[i+1][dif][k-l];
    }
    while( q-- ) {
        long long pos, already = 0;
        scanf("%lld",&pos);
        int su = s, moo = 0;
        if( dp[1][moo][su] < pos ) {
            printf("NIE\n");
            continue;
        }
        for( int i = 1 ; i <= mx ; i++ ) {
            for( int j = 0 ; j <= 9 && j <= su; j++ ) {
                int nxtmoo = ( moo - mod[j][mx-i] + m ) % m, nxtsu = su-j;
                if( pos <= dp[i+1][nxtmoo][nxtsu] ) {
                    moo = nxtmoo, su = nxtsu;
                    if( already ) printf("%d",j);
                    else if( !already && j != 0 ) {
                        already = 1;
                        printf("%d",j);
                    }
                    break;
                }
                else pos -= dp[i+1][nxtmoo][nxtsu];
            }
        }
        printf("\n");
    }
    return 0;
}