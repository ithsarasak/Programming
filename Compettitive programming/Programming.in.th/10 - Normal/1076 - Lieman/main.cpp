#include<stdio.h>

int m, n, i, j, track[22], man[22][22], minlie = 20;
int checklie( int d , int k )
{
    //printf("%d\n",minlie);
    if( d != 0 ){
        track[d] = k;
    }
    if( d > m ){
        return 0;
    }
    if( d == m ){
        int lieman = 0;
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= m ; j++ ){
                if( man[i][j] != track[j] && man[i][j] != 0 ){
                    lieman++;
                    break;
                }
            }
        }
        if( minlie > lieman ){
            minlie = lieman;
        }
    }
    checklie( d + 1 , 1 );
    checklie( d + 1 , -1 );
    return 0;
}
int main()
{
    scanf("%d %d",&n,&m);

    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= m ; j++ ){
            scanf("%d",&man[i][j]);
        }
    }

    checklie( 0 , 1 );
    printf("%d",minlie);
}
