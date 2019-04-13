#include<bits/stdc++.h>

using namespace std;
int rmq[20][100010], n, q, lg;
int pow2( int k )
{
    int t = 1;
    for( int i = 0 ; i < k ; i++ ){
        t *= 2;
    }
    return t;
}
int main()
{
    scanf("%d %d",&n,&q);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&rmq[0][i]);
    }
    lg = log2( n );
    //printf("%d\n",lg);
    for( int i = 1 ; i <= lg ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( j + pow2( i - 1 ) < n ){
                rmq[i][j] = min( rmq[i - 1][j], rmq[i - 1][j + pow2( i - 1 )] );
            }
            else{
                rmq[i][j] = rmq[i - 1][j];
            }
        }
    }
    /*for( int i = 0 ; i <= lg ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            printf("%d ",rmq[i][j]);
        }
        printf("\n");
    }*/
    for( int i = 0 ; i < q ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        int lg = log2( t - f + 1 );
        printf("%d\n",min( rmq[lg][f] , rmq[lg][t - pow2( lg ) + 1]));
    }
    return 0;
}
