#include<bits/stdc++.h>

using namespace std;
int n, k, p;
int sum[100100], mic[2][100100];
int main()
{
    scanf("%d %d %d",&n,&k,&p);
    for( int i = 1 ; i <= n ; i++ ){
        int hotel;
        scanf("%d",&hotel);
        sum[i] = sum[i-1] + hotel;
    }
    for( int i = 1 ; i <= k ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( j <= p*i )mic[i%2][j] = sum[j];
            else mic[i%2][j] = max( mic[i%2][j-1], mic[(i+1)%2][j-p] + sum[j] - sum[j-p] );
        }
    }
    printf("%d",mic[k%2][n]);
    return 0;
}
