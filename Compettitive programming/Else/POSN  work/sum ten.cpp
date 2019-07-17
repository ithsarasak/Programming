#include<bits/stdc++.h>

int sum1[101][101], sum2[101][101], data[101][101];
int cases, n, counts;
int main()
{
    scanf("%d",&cases);
    for( int z = 0 ; z < cases ; z++ ){
        scanf("%d",&n);
        counts = 0;
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                scanf("%d",&data[i][j]);
                sum1[i][j] = sum1[i][j - 1] + data[i][j];
                sum2[i][j] = sum2[i - 1][j] + data[i][j];
            }
        }
        for( int i = 1 ; i <= n ; i++ ){
            if( sum1[i][n] == 10 ){
                counts++;
            }
            else if( sum1[i][n] > 10 ){
                for( int l = n - 1 ; l >= 0 ; l-- ){
                    for( int j = n ; j - l >= 0 ; j-- ){
                        if( sum1[i][j] - sum1[i][j - l] == 10 ){
                            counts++;
                        }
                    }
                }
            }
            if( sum2[n][i] == 10 ){
                counts++;
            }
            else if( sum2[n][i] > 10 ){
                for( int l = n - 1 ; l >= 0 ; l-- ){
                    for( int j = n ; j - l >= 0 ; j-- ){
                        if( sum2[j][i] - sum2[j - l][i] == 10 ){
                            counts++;
                        }
                    }
                }
            }
        }
        printf("%d\n",counts);
    }
    return  0;
}
