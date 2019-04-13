#include<bits/stdc++.h>

using namespace std;
char w1[2010], w2[2010], ans[2010];
int lcs[2010][2010], s, path[2010][2010];
int main()
{
    scanf("%s",&w1[1]);
    scanf("%s",&w2[1]);
    int len1 = strlen( &w1[1] );
    int len2 = strlen( &w2[1] );
    for( int i = 1 ; i <= len1 ; i++ ){
        for( int j = 1 ; j <= len2 ; j++ ){
            if( w1[i] == w2[j] ){
                lcs[i][j] = lcs[i-1][j-1] + 1;
                path[i][j] = 1;
            }
            else if( lcs[i-1][j] >= lcs[i][j-1] ){
                lcs[i][j] = lcs[i-1][j];
                path[i][j] = 2;
            }
            else{
                lcs[i][j] = lcs[i][j-1];
                path[i][j] = 3;
            }
        }
    }
    printf("%d\n",lcs[len1][len2]);
    if( lcs[len1][len2] == 0 ){
        printf("No Roma word");
        return 0;
    }
    int x = len1, y = len2;
    while( x > 0 && y > 0 ){
        if( path[x][y] == 1 ){
            ans[s] = w1[x];
            s++;
            x--, y--;
        }
        else if( path[x][y] == 2 ){
            x--;
        }
        else{
            y--;
        }
    }
    for( int i = s - 1 ; i >= 0 ; i-- ){
        printf("%c",ans[i]);
    }
    return 0;
}
