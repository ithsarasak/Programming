#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n, k[5];
long long mic[5][1010][3];
long long mic2[5][1010][3];
long long mic3[5][1010][3];
int main()
{
    scanf("%d %d %d %d",&n,&k[1],&k[2],&k[3]);
    if( n == 1 && k[1] == 1 && k[2] == 1 && k[3] == 1 ){
        printf("1");
        return 0;
    }
    mic[1][1][0] = 1;
    mic2[1][1][0] = 1;
    mic3[1][1][0] = 1;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= 3 ; j++ ){
            if( j == 1 ){
                mic[j][i][0] += mic[3][i-1][0] + mic[3][i-1][1];
                mic[j][i][0] %= mod;
                for( int l = 1 ; l < k[j] ; l++ ){
                    mic[j][i][1] += mic[j][i - l][0];
                    mic[j][i][1] %= mod;
                }
            }
            else if( j == 2 ){
                mic[j][i][0] += mic[1][i-1][0] + mic[1][i-1][1];
                mic[j][i][0] %= mod;
                for( int l = 1 ; l < k[j] ; l++ ){
                    mic[j][i][1] += mic[j][i - l][0];
                    mic[j][i][1] %= mod;
                }
            }
            else{
                mic[j][i][0] += mic[2][i-1][0] + mic[2][i-1][1] + mic[1][i-1][0] + mic[1][i-1][1];
                mic[j][i][0] %= mod;
                for( int l = 1 ; l < k[j] ; l++ ){
                    mic[j][i][1] += mic[j][i - l][0];
                    mic[j][i][1] %= mod;
                }
            }
        }
    }
    long long sum = 0;
    for( int i = 1 ; i <= 3 ; i++ ){
        sum += mic[i][n][0];
        sum %= mod;
        sum += mic[i][n][1];
        sum %= mod;
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= 2 ; j++ ){
            if( j == 1 ){
                mic2[j][i][0] += mic2[2][i-1][0] + mic2[2][i-1][1];
                mic2[j][i][0] %= mod;
                for( int l = 1 ; l < k[1] ; l++ ){
                    mic2[j][i][1] += mic2[j][i - l][0];
                    mic2[j][i][1] %= mod;
                }
            }
            else if( j == 2 ){
                mic2[j][i][0] += mic2[1][i-1][0] + mic2[1][i-1][1];
                mic2[j][i][0] %= mod;
                for( int l = 1 ; l < k[3] ; l++ ){
                    mic2[j][i][1] += mic2[j][i - l][0];
                    mic2[j][i][1] %= mod;
                }
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= 2 ; j++ ){
            if( j == 1 ){
                for( int l = 1 ; l < k[1] ; l++ ){
                    mic3[j][i][1] += mic3[j][i - l][0];
                    mic3[j][i][1] %= mod;
                }
            }
            else if( j == 2 ){
                mic3[j][i][0] += mic3[1][i-1][0] + mic3[1][i-1][1];
                mic3[j][i][0] %= mod;
                for( int l = 1 ; l < k[2] ; l++ ){
                    mic3[j][i][1] += mic3[j][i - l][0];
                    mic3[j][i][1] %= mod;
                }
            }
        }
    }
    long long sum2 = 0;
    for( int j = 1 ; j <= 2 ; j++ ){
        sum2 += mic2[j][n][0];
        sum2 %= mod;
        sum2 += mic2[j][n][1];
        sum2 %= mod;
        sum2 += mic3[j][n][0];
        sum2 %= mod;
        sum2 += mic3[j][n][1];
        sum2 %= mod;
    }
    sum -= sum2;
    sum += mod;
    if( k[1] >= n )sum++;
    printf("%lld",sum%mod);
    return 0;
}
