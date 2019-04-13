#include<bits/stdc++.h>

using namespace std;
int n, ans = 1e9;
int mic[1010][3010], choc[1010];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&choc[i]);
    }
    for( int i = 1 ; i <= 3000 ; i++ ){
        if( i != choc[1] )mic[1][i] = 1;
        else mic[1][i] = 0;
    }
    for( int i = 2 ; i <= n ; i++ ){
        int mi = 1e9;
        for( int j = 1 ; j <= 3000 ; j++ ){
            if( j < i && j >= i - 1 ){
                mi = min( mi, mic[i-1][j] );
            }
            else if( j >= i ){
                if( j == choc[i] ){
                    mic[i][j] = mi;
                }
                else{
                    mic[i][j] = mi + 1;
                }
                mi = min( mi, mic[i-1][j] );
            }
        }
    }
    /*for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= 20 ; j++ ){
            printf("%d ",mic[i][j]);
        }
        printf("\n");
    }*/
    for( int i = n ; i <= 3000 ; i++ ){
        ans = min( ans, mic[n][i] );
    }
    printf("%d",ans);
    return 0;
}
