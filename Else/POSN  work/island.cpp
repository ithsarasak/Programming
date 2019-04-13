#include<bits/stdc++.h>

char maps[160][160];
int sum[160][160];
int n, t, k, maxs, posx, posy;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%s",maps[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( maps[i][j] - '0' != 0 ){
                t = 1;
            }
            else{
                t = 0;
            }
            sum[i][j + 1] = sum[i - 1][j + 1] + sum[i][j] - sum[i - 1][j] + t;
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            for( int k = maxs + 1 ; i + k <= n && j + k <= n ; k++ ){
                if( sum[i + k][j + k] - sum[i + k][j - 1] - sum[i - 1][j + k] + sum[i - 1][j - 1] == ( k + 1 ) * ( k + 1 ) ){
                    maxs = k;
                    posx = i;
                    posy = j;
                }
            }
        }
    }
    printf("%d %d\n%d",posx,posy,( maxs + 1 ) * ( maxs + 1 ));
    return 0;
}
