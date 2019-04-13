#include<bits/stdc++.h>

using namespace std;
int qs[1010][1010], ma[1010][1010];
int r, c, q;
int main()
{
    scanf("%d %d",&r,&c);
    for( int i = 1 ; i <= r ; i++ ){
        for( int j = 1 ; j <= c ; j++ ){
            scanf("%d",&ma[i][j]);
            qs[i][j] = ma[i][j] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }
    scanf("%d",&q);
    while( q-- ){
        int x1, x2, y1, y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",qs[x2+1][y2+1]-qs[x1][y2+1]-qs[x2+1][y1]+qs[x1][y1]);
    }
    return 0;
}
