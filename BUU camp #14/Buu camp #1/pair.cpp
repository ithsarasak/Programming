#include<bits/stdc++.h>

using namespace std;
int k, dp[1010][1010];
char cards[1010];
int mic( int l, int r )
{
    int mx = -1;
    if( l >= r ) return 0;
    if( dp[l][r] != -1 ) return dp[l][r];
    for( int i = l ; i < r ; i++ ){
        mx = max( mx, mic( l, i )+ mic( i + 1, r ) );
    }
    if( cards[l] == cards[r] ) mx = max( mx, mic( l + 1, r - 1 ) + 1 );
    return dp[l][r] = mx;
}
int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%d",&k);
    for( int i = 1 ; i <= k ; i++ ){
        scanf(" %c",&cards[i]);
    }
    printf("%d",mic( 1, k ));
    return 0;
}
