#include<bits/stdc++.h>

using namespace std;
int n, k, ans;
int mic[5010][2];
int main()
{
    scanf("%d %d",&n,&k);
    for( int j = 1 ; j <= n ; j++ ){
        if( j <= k )mic[j][0] = 1;
        else mic[j][0] = 0;
        mic[j][0] += mic[j-1][0];
    }
    for( int i = 1 ; i < n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            mic[j][i%2] = ( 2553 + mic[j-1][(i+1)%2] - mic[max( 0,j-1-k )][(i+1)%2] ) % 2553;
            if( j == n ){
                ans += (( mic[j][i%2]*mic[j][i%2] ) % 2553 )*mic[j][i%2];
                ans %= 2553;
            }
            mic[j][i%2] += mic[j-1][i%2];
            mic[j][i%2] %= 2553;
        }
    }
    printf("%d",ans);
    return 0;
}
