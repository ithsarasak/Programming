#include<bits/stdc++.h>

using namespace std;
int sum[110][110], m, n, w, l, temp, ans = 99999;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < m ; i++ ){
        int x, y;
        scanf("%d %d",&x,&y);
        sum[x][y] = 1;
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
        }
    }
    for( int i = 1 ; i <= m ; i++ ){
        if( m % i == 0 ){
            w = i, l = m / i;
            for( int j = 1 ; j <= n - w + 1 ; j++ ){
                for( int k = 1 ; k <= n - l + 1 ; k++ ){
                    temp = sum[j + w - 1][k + l - 1] - sum[j - 1][k + l - 1] - sum[j + w - 1][k - 1] + sum[j - 1][k - 1];
                    if( ans > m - temp ){
                        ans = m - temp;
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
