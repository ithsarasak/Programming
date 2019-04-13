#include<bits/stdc++.h>

using namespace std;
int q = 10, mic[1010][1010];
int ans[15];
int main()
{
    for( int z = 0 ; z < q ; z++ ){
        memset( mic, 0, sizeof mic );
        char fuck[1010], fuck2[1010];
        scanf(" %s",fuck);
        int len = strlen( fuck );
        for( int i = 0 ; i < len ; i++ ){
            fuck[len - i - 1] = tolower( fuck[len - i - 1] );
            fuck2[i] = fuck[len - i - 1];
        }
    //printf("%s\n",fuck2);
        for( int i = 0 ; i < len ; i++ ){
            for( int j = 0 ; j < len ; j++ ){
                if( fuck[i] == fuck2[j] ){
                    mic[i + 1][j + 1] = mic[i][j] + 1;
                }
                else{
                    mic[i + 1][j + 1] = max( mic[i][j + 1], mic[i + 1][j] );
                }
            }
        }
        ans[z] = mic[len][len] % 10;
        /*for( int i = 1 ; i <= len ; i++ ){
            for( int j = 1; j <= len ; j++ ){
                printf("%d ",mic[i][j]);
            }
            printf("\n");
        }*/
    }

    for( int i = 0 ; i < q ; i++ ){
        printf("%d",ans[i]);
    }
    return 0;
}
