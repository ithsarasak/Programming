#include<bits/stdc++.h>

using namespace std;
int r, c, n, m;
int sum[100010][20];
int main()
{
    scanf("%d %d %d %d",&r,&c,&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        int a, b, c, d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        sum[a][b] += 1;
        sum[a][d + 1] -= 1;
        sum[c + 1][b] -= 1;
        sum[c + 1][d + 1] += 1;
    }
    for( int i = 1; i <= r ; i++ ){
        for( int j = 1 ; j <= c ; j++ ){
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for( int i = 0 ; i < m ; i++ ){
        int a, b, c, d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int ma = -1;
        for( int j = a ; j <= c ; j++ ){
            for( int k = b ; k <= d ; k++ ){
                if( ma < sum[j][k] ){
                    ma = sum[j][k];
                }
            }
        }
        printf("%d\n",ma);
    }
    return 0;
}
