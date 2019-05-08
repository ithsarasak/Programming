#include<bits/stdc++.h>

using namespace std;
int rmq[20][3100], n, q, lg, rmq2[20][3100];
long long ans;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&rmq[0][i]);
        rmq2[0][i] = rmq[0][i];
    }
    lg = log2( n );
    for( int i = 1 ; i <= lg ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( j + ( 1 << ( i - 1 ) ) < n ){
                rmq[i][j] = min( rmq[i - 1][j], rmq[i - 1][j + ( 1 << ( i - 1 ) )] );
            }
            else{
                rmq[i][j] = rmq[i - 1][j];
            }
        }
    }
    for( int i = 1 ; i <= lg ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( j + ( 1 << ( i - 1 ) ) < n ){
                rmq2[i][j] = max( rmq2[i - 1][j], rmq2[i - 1][j + ( 1 << ( i - 1 ) )] );
            }
            else{
                rmq2[i][j] = rmq2[i - 1][j];
            }
        }
    }
    int f, t;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j < n - i + 1 ; j++ ){
            f = j;
            t = j + i - 1;
            int lg = log2( t - f + 1 );
            int mi = min( rmq[lg][f] , rmq[lg][t - ( 1 << lg ) + 1]);
            int ma = max( rmq2[lg][f] , rmq2[lg][t - ( 1 << lg ) + 1]);
            //printf("%d %d\n",ma,mi);
            if( ma - mi == t - f ){
                ans++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}

