#include<bits/stdc++.h>

using namespace std;

int fw[2020][2020], n;
void up( int x, int y, int v )
{
    for( int i = x ; i <= n ; i += ( i & -i ) ){
        for( int j = y ; j <= n ; j += ( j & -j ) ){
            fw[i][j] += v;
        }
    }
}
int query( int x, int y )
{
    int sum = 0;
    for( int i = x ; i > 0 ; i -= ( i & -i ) ){
        for( int j = y ; j > 0 ; j -= ( j & -j ) ){
            sum += fw[i][j];
        }
    }
    return sum;
}
int main()
{
    while( 1 ){
        int c;
        scanf("%d",&c);
        if( c == 0 ){
            scanf("%d",&n);
        }
        else if( c == 1 ){
            int x, y, v;
            scanf("%d %d %d",&x,&y,&v);
            x++,y++;
            up( x, y, v );
        }
        else if( c == 2 ){
            int sx, sy, ex, ey;
            scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
            sx++,sy++,ex++,ey++;
            int one = query( ex, ey ), two = query( sx - 1, ey ), three = query( ex, sy - 1 ), four = query( sx - 1, sy - 1 );
            printf("%d\n",one-two-three+four);
        }
        else{
            return 0;
        }
    }
}
