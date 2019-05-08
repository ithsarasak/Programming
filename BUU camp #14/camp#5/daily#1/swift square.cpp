#include<bits/stdc++.h>

using namespace std;
int n, b;
int mic[20][20010], sq[20];
int main()
{
    for( int i = 0 ; i < 20 ; i++ ){
        for( int j = 0 ; j < 15000 ; j++ ){
            mic[i][j] = 1e9;
        }
    }
    scanf("%d %d",&n,&b);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&sq[i]);
    }
    mic[0][0] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = i - 1 ; j <= b ; j++ ){
            for( int k = 1 ; j + k * k <=b ; k++ ){
                mic[i][j+k*k] = min( mic[i][j+k*k], mic[i-1][j] + ( sq[i] - k ) * ( sq[i] - k ) );
            }
        }
    }
    if( mic[n][b] == 1e9 ) printf("-1");
    else printf("%d",mic[n][b]);
    return 0;
}
