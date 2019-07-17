#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char word[10010], word2[10010];
int dp[10010][10010], max;
int i, j, k;
int main()
{
    scanf("%s",word);
    scanf("%s",word2);

    int len = strlen( word );
    int len2 = strlen( word2 );

    for( i = 1 ; i <= len ; i++ ){
        for( j = 1 ; j <= len2 ; j++ ){
            if( word[i - 1] == word2[j - 1] ){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if( max < dp[i][j] ){
                max = dp[i][j];
            }
        }
    }
    for( i = 1 ; i <= len ; i++ ){
        for( j = 1 ; j <= len2 ; j++ ){
            if( dp[i][j] == max ){
                for( k = i - max ; k < i ; k++ ){
                    printf("%c",word[k]);
                }
                exit( 0 );
            }
        }
    }
    return 0;
}
