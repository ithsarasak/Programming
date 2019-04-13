#include<bits/stdc++.h>
#define mod 100000
#define mod2 1000000000
using namespace std;

long long dp[250][250];
int n;
char s[250];
int check( char l, char r )
{
	if( l == '(' ){
        if( r == ')' || r == '?' )return 1;
        else return 0;
	}
	if( l == '[' ){
        if( r == ']' || r == '?' )return 1;
        else return 0;
	}
	if( l == '{' ){
        if( r == '}' || r == '?' )return 1;
        else return 0;
	}
	if( l == ')' || l == '}' || l == ']' ) return 0;
	if( r == '(' || r == '{' || r == '[' ) return 0;
	if( r != '?' ) return 1;
	return 3;
}
long long play( int l, int r ) {
	if( ( r - l ) % 2 == 0 ) return 0;
	if( l > r ){
        if( l == r + 1 )return 1;
        else return 0;
	}
	if ( dp[l][r] != -1 ) return dp[l][r];
	dp[l][r] = 0;
	for( int i = l + 1 ; i <= r ; i += 2 ){
		long long left = ( check( s[l], s[i] ) * play( l + 1, i - 1 ) ) % mod2;
		long long right;
        if( i < r )right = play( i + 1, r );
        else right = 1;
		dp[l][r] = ( dp[l][r] + left * right ) % mod2;
	}
	return dp[l][r] % mod2;
}
int main()
{
    for( int i = 0 ; i <= 200 ; i++ ){
        for( int j = 0 ; j < 200 ; j++ ){
            dp[i][j] = -1;
        }
    }
	scanf("%d %s",&n,&s);
    long long ans = play( 0, n-1 );
    if( ans < 1e5 ){
        printf("%lld",ans);
        return 0;
    }
    long long temp = ans % mod;
    int cnt = 0;
    while( temp > 0 ){
        temp /= 10;
        cnt++;
    }
    for( int i = 0 ; i < 5 - cnt ; i++ ){
        printf("0");
    }
    printf("%lld",ans%mod);
	return 0;
}
