#include<bits/stdc++.h>

using namespace std;
int n;
int num[610], sum[610];
long long dp[1010][1010];
long long mic( int l, int r )
{
    //printf("L :%d R : %d\n",l,r);
    if( dp[l][r] != -1 ){
        return dp[l][r];
    }
    if( l >= r ){
        return 0;
    }
    long long ma = 0;
    for( int i = l ; i < r ; i++ ){
        ma = max( ma, ( long long )( min( sum[i] - sum[l - 1] , sum[r] - sum[i] ) * 2 ) + ( long long )max( sum[i] - sum[l - 1] , sum[r] - sum[i] ) + mic( l , i ) + mic( i + 1, r ) );
        /*printf("L : %d R : %d I : %d ma : %d sum( l, i ) :%d s( i + 1,r ) : %d\n",l,r,i,ma, sum(l,i), sum( i + 1,r ) );
        printf("min : %d ",min( sum( l, i ) , sum( i + 1 , r ) ) * 2 );
        printf("max : %d\n",max( sum( l, i ) , sum( i + 1 , r ) ));
        printf("mic( l ,i ) %d mic( i + 1 ,r ) %d \n",mic( l , i ) ,mic( i + 1, r ));
        printf("%d",( min( sum( l, i ) , sum( i + 1 , r ) ) * 2 ) + max( sum( l, i ) , sum( i, r ) ) + mic( l , i ) + mic( i + 1, r ));*/
    }
   // printf("dp[%d][%d] = %d\n",l,r,ma);
    return dp[l][r] = ma;
}
int main()
{
    memset( dp, -1, sizeof dp );
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
        sum[i] = num[i] + sum[i - 1];
    }
    printf("%d",mic( 1, n ));
}
