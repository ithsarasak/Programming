#include<bits/stdc++.h>

using namespace std;
int m, n, k, ans = -2000000001;
int ma1[2010][2010], ma2[2010][2010];
int qs1[2010][2010], qs2[2010][2010];
void con()
{
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            ma2[i][n-j+1] = ma1[i][j];
        }
    }
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            ma1[i][j] = ma2[i][j];
        }
    }
}
int cal()
{
    memset( qs1, 0, sizeof qs1 );
    memset( qs2, 0, sizeof qs2 );
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            qs1[i][j] = ma1[i][j] + qs1[i-1][j];
            qs2[i][j] = ma1[i][j] + qs2[i-1][j-1];
        }
    }

    int sum = 0;
    for( int i = k ; i <= m ; i++ ){
        sum = 0;
        for( int j = 1 ; j <= k ; j++ ){
            sum += qs2[i][j];
        }
        //printf("sum : %d\n",sum);
        ans = max( ans, sum );
        for( int j = k + 1 ; j <= n ; j++ ){
            //printf("%d %d %d %d\n",qs2[i][j],qs2[i-k][j-k],qs1[i][j-k],qs1[i-k][j-k]);
            sum += qs2[i][j] - qs2[i-k][j-k];
            sum -= ( qs1[i][j-k] - qs1[i-k][j-k] );
            //printf("sum : %d\n",sum);
            ans = max( ans, sum );
        }
    }
}
int main()
{
    scanf("%d %d %d",&m,&n,&k);
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            scanf("%d",&ma1[i][j]);
        }
    }
    cal();
    con();
    cal();
    printf("%d",ans);
    return 0;
}
