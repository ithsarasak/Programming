#include<bits/stdc++.h>

using namespace std;
int mark[1010][1010];
int n, x, y, c;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&x,&y);
        mark[x][y] = 1;
    }
    for( int i = 0 ; i <= 1000 ; i++ ){
        for( int j = 0 ; j <= 1000 ; j++ ){
            if( mark[i][j] ){
                c++;
            }
        }
    }
    printf("%d",c);
    return 0;
}
