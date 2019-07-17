#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int mod = 1e9 + 7;

long long dp[N][N];
int s, e;
char st[N];

long long solve( int i, int j ) {
    long long &now = dp[i][j];
    if( now != -1 ) return now;
    now = 0;
    if( j != 0 ) {
        if( i == 1 ) {
            if( j == 1 && ( st[i] != 'L' || i == e ) ) now = 1;
        }
        else if( i == s ) {
            if( st[i] != 'L' ) now = ( now + solve( i-1, j-1 ) ) % mod;
            if( st[i] != 'R' ) now = ( now + solve( i-1, j ) ) % mod;
        } 
        else if( i == e ) {
            now = ( now + solve( i-1, j-1 ) + solve( i-1, j ) ) % mod;
        }
        else {
            if( st[i] != 'L' ) now = ( now + solve( i-1, j-1 ) * ( j - ( i > s ? 1 : 0 ) - ( i > e ? 1 : 0 ) ) ) % mod;
            if( st[i] != 'L' ) now = ( now + solve( i-1, j ) * ( j - ( i > e ? 1 : 0 ) ) ) % mod;
            if( st[i] != 'R' ) now = ( now + solve( i-1, j ) * ( j - ( i > s ? 1 : 0 ) ) ) % mod;
            if( st[i] != 'R' ) now = ( now + solve( i-1, j+1 ) * j ) % mod;
        }
    }
    return now;
}

int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%s %d %d",&st[1],&s,&e);
    printf("%lld",solve( strlen( &st[1] ), 1 ));
    return 0;
}