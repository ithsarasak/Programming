#include<bits/stdc++.h>

using namespace std;
int n, lcs[5010][5010];
char word[5010];
int main()
{
    scanf("%d",&n);
    scanf("%s",word + 1);
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( word[i] == word[n-j+ 1] ){
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else{
                lcs[i][j] = max( lcs[i - 1][j], lcs[i][j - 1] );
            }
        }
    }
    /*for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            printf("%d ",lcs[i][j]);
        }
        printf("\n");
    }*/
    printf("%d",n - lcs[n][n]);
    return 0;
}
