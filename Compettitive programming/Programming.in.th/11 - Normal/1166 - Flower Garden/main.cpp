#include<stdio.h>

char garden[32][32];
int count = 0, max, n, m;
int flower( int x, int y )
{
    if( x < 1 || x > n || y < 1 || y > m ){
        return 0;
    }
    if( garden[x][y] == '#' || garden[x][y] == 'A' || garden[x-1][y] == '#' || garden[x+1][y] == '#' || garden[x][y-1] == '#' || garden[x][y+1] == '#' ){
        return 0;
    }
    count++;
    garden[x][y] = 'A';
    //printf("%d\n",count);
    flower( x - 1 , y );
    flower( x + 1 , y );
    flower( x , y + 1 );
    flower( x , y - 1 );
}
int main()
{
    int i, j;
    scanf("%d %d",&n,&m);

    for( i = 0 ; i < 32 ; i++ ){
        for( j = 0 ; j < 32 ; j++ ){
            garden[i][j] = '.';
        }
    }
    for( i = 1 ; i <= n ; i++ ){
        scanf("%s",&garden[i][1]);
    }

    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= m ; j++ ){
                count = 0;
            if( garden[i][j] == '.' && garden[i+1][j] != '#' && garden[i][j-1] != '#' && garden[i][j+1] != '#' ){
                flower( i,  j );
                if( max < count ){
                    max = count;
                }
            }
        }
    }
    /*for( i = 1 ; i <= n ; i++ ){
        printf("%s",&garden[i][1]);
        printf("\n");
    }*/
    printf("%d",max);
    return 0;
}
