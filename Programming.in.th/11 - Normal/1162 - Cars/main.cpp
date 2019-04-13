#include<stdio.h>

int lane[102][42], t, m ,n, i, j, go[101];
int race( int x, int y, int time )
{
    //printf("x : %d y : %d time : %d\n",x,y,time);
    if( time == t ){
        for( i = 0 ; i < t ; i++ ){
            printf("%d\n",go[i]);
        }
        return 0;
    }
    if( lane[x+1][y-1] == 0 ){
        go[time] = 1;
        race( x + 1, y - 1, time + 1);
    }
    if( lane[x+1][y] == 0 ){
        go[time] = 3;
        race( x + 1, y, time + 1);
    }
    if( lane[x+1][y+1] == 0 ){
        go[time] = 2;
        race( x + 1, y + 1, time + 1 );
    }
    return 0;
}
int main()
{
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&t);

    for( i = 0 ; i < 102 ; i++ ){
        for( j = 0 ; j < 42 ; j++ ){
            lane[i][j] = 1;
        }
    }
    for( i = 1 ; i <= t ; i++ ){
        for( j = 1 ; j <= m ; j++ ){
                scanf("%d",&lane[i][j]);
        }
    }
    //printf(" %d\n",lane[2][1]);
    race( 0 , n , 0 );
    return 0;
}
