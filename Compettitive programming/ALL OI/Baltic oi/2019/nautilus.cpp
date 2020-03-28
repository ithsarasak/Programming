#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10;
int r, c, k, ans;
bitset<N> dp[N], a[N];
char s[N*10];
int main()
{
    scanf("%d %d %d",&r,&c,&k);
    for( int i = 0 ; i < r ; i++ ) {
        char t[N];
        scanf("%s",t);
        for( int j = 0 ; j < c ; j++ ) {
            dp[i][j] = a[i][j] = ( t[j] == '.' );
        }
    }
    scanf("%s",s);
    for( int i = 0 ; i < k ; i++ ) {
        bitset<N> tmp[N];
        for( int j = 0 ; j < r ; j++ ) tmp[j].reset();
        if( s[i] == 'S' || s[i] == '?' ) for( int j = 1 ; j < r ; j++ ) tmp[j] |= dp[j-1];
        if( s[i] == 'N' || s[i] == '?' ) for( int j = 0 ; j < r - 1 ; j++ ) tmp[j] |= dp[j+1];
        if( s[i] == 'W' || s[i] == '?' ) for( int j = 0 ; j < r ; j++ ) tmp[j] |= dp[j] >> 1;
        if( s[i] == 'E' || s[i] == '?' ) for( int j = 0 ; j < r ; j++ ) tmp[j] |= dp[j] << 1;

        for( int j = 0 ; j < r ; j++ ) dp[j] = tmp[j] & a[j];
    }
    for( int i = 0 ; i < r ; i++ ) ans += dp[i].count();
    printf("%d",ans);
    return 0;
}