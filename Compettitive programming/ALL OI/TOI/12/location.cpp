#include <bits/stdc++.h>

using namespace std;

int m, n, k, sum[1010][1010], ans;

int main()
{
    scanf("%d %d %d",&m,&n,&k);
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            scanf("%d",&sum[i][j]);
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    for( int i = k ; i <= m ; i++ ){
        for( int j = k ; j <= n ; j++ ){
            ans = max( ans, sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k] );
        }
    }
    printf("%d",ans);
}

