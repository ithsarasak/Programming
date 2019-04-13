#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>

using namespace std;

stack<char> ans;
char temp;
char word[10010], word2[10010];
int dp[10010][10010];
int i, j, k;
int more( int a , int b ){
    if( a > b ){
        return a;
    }
    else{
        return b;
    }
}
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
            else{
                dp[i][j] = more( dp[i - 1][j] , dp[i][j - 1] );
            }
        }
    }
    printf("%d\n",dp[len][len2]);
    if( dp[len][len2] == 0 ){
        printf("No Roma word");
        return 0;
    }
    while( dp[len][len2] != 0 ){
        if( word[len - 1] == word2[len2 - 1] ){
            ans.push( word[len - 1] );
            len -= 1;
            len2 -= 1;
        }
        else if( dp[len - 1][len2] >= dp[len][len2 - 1] ){
            len -= 1;
        }
        else{
            len2 -= 1;
        }
        //printf("%d %d\n",len,len2);
    }
    int sizes = ans.size();
    for( i = 0  ; i < sizes ; i++ ){
        temp = ans.top();
        printf("%c",temp);
        ans.pop();
    }
    return 0;
}
