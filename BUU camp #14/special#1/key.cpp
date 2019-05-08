#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

char s1[N], s2[N], wq[2*N];
int len1, len2, dp[N][N], q;

int main()
{
    scanf("%s %s %d",&s1[1],&s2[1],&q);
    len1 = strlen( &s1[1] ), len2 = strlen( &s2[1] );
    while( q-- ){
        scanf("%s",&wq[1]);
        memset( dp, 0, sizeof dp );
        for( int i = 0 ; i <= len1 ; i++ ){
            for( int j = 0 ; j <= len2 ; j++ ){
                if( i == 0 && j == 0 ) dp[i][j] = 1;
                else if( ( i != 0 && ( s1[i] == wq[i+j] && dp[i-1][j] == 1 ) ) || ( j != 0 && ( s2[j] == wq[i+j] && dp[i][j-1] == 1 ) ) ) dp[i][j] = 1;
            }
        }
        if( dp[len1][len2] )printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
