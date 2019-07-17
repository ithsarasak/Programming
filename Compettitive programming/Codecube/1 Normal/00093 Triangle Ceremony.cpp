#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
struct po{
    double x, y;
}p[1100];
int n, cnt;
double sl[1100][1100];
double findslope( int idx1, int idx2 )
{
    if( p[idx1].x == p[idx2].x ) return inf;
    else return ( p[idx1].y - p[idx2].y ) / ( p[idx1].x - p[idx2].x );
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }
    for( int i = 0 ; i < n - 1 ; i++ ){
        for( int j = i + 1 ; j < n ; j++ ){
            double s1 = findslope( i, j );
            sl[i][j] = s1;
            sl[j][i] = s1;
        }
    }
    for( int i = 0 ; i < n - 2 ; i++ ){
        for( int j = i + 1 ; j < n - 1 ; j++ ){
            for( int k = j + 1 ; k < n ; k++ ){
                if( sl[i][j] != sl[j][k] || sl[j][k] != sl[i][k] || sl[i][j] != sl[i][k] )cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
