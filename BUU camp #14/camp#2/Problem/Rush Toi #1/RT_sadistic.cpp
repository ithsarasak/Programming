#include<bits/stdc++.h>

using namespace std;
int dpl[1010][1010], dpr[1010][1010], cl[1010][1010] , cr[1010][1010],rl[1010][1010], rr[1010][1010], ro, co, sum[1010][1010];
char m[1010][1010];
long long think( char c )
{
    memset( sum, 0, sizeof sum );
    memset( dpl, 0, sizeof dpl );
    memset( dpr, 0, sizeof dpr );
    memset( rr, 0, sizeof rr );
    memset( cr, 0, sizeof cr );
    memset( rl, 0, sizeof rl );
    memset( cl, 0, sizeof cl );
     for( int i = 1 ; i <= ro ; i++ ){
        for( int j = 1; j <= co ; j++ ){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if( m[i][j] == c ){
                 sum[i][j] += 1;
            }
        }
     }
     for( int i = 1 ; i <= ro ; i++ ){
        for( int j = 1 ; j <= co ; j++ ){
            dpl[i][j] = dpl[i - 1][j - 1] + rl[i - 1][j -1] + cl[i - 1][j - 1] + sum[i - 1][j - 1];
            rl[i][j] = rl[i][j - 1] + sum[i][j - 1] - sum[i - 1][j - 1];
            cl[i][j] = cl[i - 1][j] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
     }
     for( int i = 1 ; i <= ro ; i++ ){
        for( int j = co ; j >= 1 ; j-- ){
            dpr[i][j] = dpr[i - 1][j + 1] + rr[i - 1][j + 1] + cr[i - 1][j + 1] + sum[i - 1][co] - sum[i - 1][j];
            rr[i][j] = rr[i][j + 1] + ( sum[i][co] - sum[i][j] ) - ( sum[i - 1][co] - sum[i - 1][j] );
            cr[i][j] = cr[i - 1][j] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
     }
    /*for( int i = 1 ; i <= ro ; i++ ){
        for( int j = 1 ; j <= co ; j++ ){
            printf("%d ",dpl[i][j]);
        }
        printf("\n");
     }
     for( int i = 1 ; i <= ro ; i++ ){
        for( int j = 1 ; j <= co ; j++ ){
            printf("%d ",dpr[i][j]);
        }
        printf("\n");
     }*/
     long long ans = 0;
     for( int i = 1 ; i <= ro ; i++ ){
        for( int j = 1 ; j <= co ; j++ ){
            if( m[i][j] == c ){
                ans += ( long long )( dpr[i][j] + dpl[i][j] + cl[i][j] + rl[i][j] );
            }
        }
     }
     return ans;
}
int main()
{
    scanf("%d %d",&ro,&co);
    for( int i = 1 ; i <= ro ; i++ ){
        scanf("%s",m[i] + 1 );
    }
    printf("%lld\n",think('M'));
    printf("%lld\n",think('S'));
    return 0;
}
