#include<bits/stdc++.h>

using namespace std;
int dp[10][100010], len;
char s[100010], w[10] = {"codecube"};
int ans = 1e9, f = -1, t;
void build( int p, char ch )
{
    int pos = -1;
    for( int i = len - 1 ; i >= 0 ; i-- ){
        if( s[i] == ch ){
            pos = i;
        }
        dp[p][i] = pos;
    }
}
int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%s",s);
    len = strlen( s );
    for( int i = 0 ; i < 8 ; i++ )build( i, w[i] );
    /*for( int i = 0 ; i < 8 ; i++ ){
        printf("%c : ",w[i]);
        for( int j = 0 ; j < len ; j++ ){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    for( int i = 0 ; i < len ; i++ ){
        if( s[i] == 'c' ){
            int pos = i+1;
            for( int j = 1 ; j < 8 ; j++ ){
                if( dp[j][pos] == -1 ){
                    if( f == -1 )printf("-1");
                    else printf("%d %d",f,t);
                    return 0;
                }
                if( j == 7 ){
                    if( ans > dp[j][pos]-i+1 ){
                        ans = dp[j][pos]-i+1,f=i+1,t=dp[j][pos]+1;
                    }
                    break;
                }
                else{
                    pos = dp[j][pos]+1;
                }
            }
        }
    }
    printf("%d %d",f,t);
    return 0;
}
