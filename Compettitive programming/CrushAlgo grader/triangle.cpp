#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n, k;
long long mic[110][110];
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= min(k+1,n) ; i++ ){
        mic[1][i] = ((i-1)*(i))/2;
        mic[i][1] = mic[1][i];
    }
    for( int i = k+2 ; i <= n ; i++ ){
        mic[1][i] = mic[1][i-1] + k;
        mic[i][1] = mic[i-1][1] + k;
    }
    for( int i = 2 ; i <= n ; i++ ){
        for( int j = i ; j <= n ; j++ ){
            mic[i][j] = mic[i-1][j]+mic[i][j-1]-mic[i-1][j-1];
            mic[i][j] %= mod;
            for( int l = i - 1 ; l >= max( 1, (i-k) ) ; l-- ){
                mic[i][j] += mic[l-1][j-1] + 1;
                mic[i][j] %= mod;
            }
            for( int l = j - 1 ; l >= max( 1, (j-k) ) ; l-- ){
                mic[i][j] += mic[i-1][l-1] + 1;
                mic[i][j] %= mod;
            }
            mic[j][i] = mic[i][j];
            //printf("%lld ",mic[i][j]);
        }
        //printf("\n");
    }
    printf("%lld",mic[n][n]);
    return 0;
}
