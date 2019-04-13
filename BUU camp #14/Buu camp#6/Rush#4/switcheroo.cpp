#include<bits/stdc++.h>

using namespace std;

int q;
int n;
int ma[200][200], maxx ,sum;
int main()
{
    scanf("%d",&q);
    while( q-- ){
        sum = 0;
        scanf("%d",&n);
        for( int i = 1 ; i <= 2 * n ; i++ ){
            for( int j = 1 ; j <= 2 * n ; j++ ){
                scanf("%d",&ma[i][j]);
            }
        }
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                maxx = 0;
                maxx = max( maxx, ma[i][j] );
                maxx = max( maxx, ma[i][2*n-j+1] );
                maxx = max( maxx, ma[2*n-i+1][j] );
                maxx = max( maxx, ma[2*n-i+1][2*n-j+1] );
                sum += maxx;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
