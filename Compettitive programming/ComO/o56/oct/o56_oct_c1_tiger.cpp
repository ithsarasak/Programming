#include<bits/stdc++.h>

using namespace std;
struct cc{
    int x, y;
}tiger[1100], fire[1100];
int n, m, ma;
int mi[1100];
int mark[2000100];
int main()
{
    memset( mi, 127, sizeof mi );
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&fire[i].x,&fire[i].y);
    }
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d %d",&tiger[i].x,&tiger[i].y);
    }
    for( int i = 0 ; i < m ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            mi[i] = min( mi[i], abs(tiger[i].x-fire[j].x)+abs(tiger[i].y-fire[j].y) );
        }
    }
    for( int i = 0 ; i < m ; i++ ){
        mark[mi[i]]++;
        ma = max( ma, mark[mi[i]] );
    }
    printf("%d",ma);
    return 0;
}

