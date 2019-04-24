#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n, m, mh;
int w[N], h[N], ok[N][N];
int main()
{
    scanf("%d %d %d",&n,&m,&mh);
    for( int i = 1 ; i <= m ; i++ ) scanf("%d",&w[i]);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&h[i]);
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) scanf("%d",&ok[i][j]);
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = 1 ; j <= m ; j++ ) printf("%d ",ok[i][j] ? min( w[j], h[i] ) : 0 );
        printf("\n");
    }
    return 0;
}