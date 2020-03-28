#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
long long INF = 1e18;
char s[N];
long long k, dp[N][N];

void add( long long &a, long long &b ) {
    a += b;
    if( a > INF ) a = INF;
}

int main()
{
    scanf("%s %lld",&s[1],&k);
    int n = strlen( &s[1] );
    dp[n+1][0] = 1;
    for( int i = n ; i >= 1 ; i-- ) for( int j = 0 ; j <= i ; j++ ) {
        if( s[i] == '.' ) {
            if( j ) add( dp[i][j], dp[i+1][j-1] );
            add( dp[i][j], dp[i+1][j+1] );
        }
        else if( s[i] == '(' ) add( dp[i][j], dp[i+1][j+1] );
        else if( j ) add( dp[i][j], dp[i+1][j-1] );
    }
    int j = 0;
    for( int i = 1 ; i <= n ; i++ ) {
        //printf("%lld %lld ",k,dp[i+1][j+1]);
        if( s[i] == '.' ) {
            if( k <= dp[i+1][j+1] ) {
                printf("(");
                j++;
            }
            else {
                printf(")");
                k -= dp[i+1][j+1], j--;
            }
        }
        else if( s[i] == '(' ) printf("("), j++;
        else printf(")"), j--;
        //printf("%d %lld\n",i,k);
    }
    return 0;
}