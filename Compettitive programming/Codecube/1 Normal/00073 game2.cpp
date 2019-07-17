#include<bits/stdc++.h>

using namespace std;
int w, h;
int ma[220][220], mic1[220][220], mic2[220][220], ma2;
int main()
{
    scanf("%d %d",&w,&h);
    for( int i = 1 ; i <= w ; i++ ){
        for( int j = 1 ; j <= h ; j++ ){
            scanf("%d",&ma[i][j]);
        }
    }
    for( int i = w ; i >= 1 ; i-- ){
        for( int j = 1 ; j <= h ; j++ ){
            if( i == w ) mic1[i][j] = mic1[i][j-1] + ma[i][j];
            else if( j == 1 ) mic1[i][j] = mic1[i+1][j] + ma[i][j];
            else mic1[i][j] = max( mic1[i+1][j], mic1[i][j-1] ) + ma[i][j];
        }
    }
    for( int i = w ; i >= 1 ; i-- ){
        for( int j = 1 ; j <= h ; j++ ){
            if( i == w ) mic2[i][j] = mic2[i][j-1] + ma[i][j];
            else if( j == 1 ) mic2[i][j] = mic2[i+1][j] + ma[i][j];
            else mic2[i][j] = min( mic2[i+1][j], mic2[i][j-1] ) + ma[i][j];
        }
    }
    printf("%d",mic1[1][h]-mic2[1][h]);
    return 0;
}
