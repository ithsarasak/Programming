#include<bits/stdc++.h>

using namespace std;
int rmq[20][100100];
int n, q;
int main()
{
    scanf("%d %d",&n,&q);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&rmq[0][i]);
    }
    for( int i = 1 ; i <= log2( n ) ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( j + ( 1 << ( i - 1 ) ) < n )rmq[i][j] = max( rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
            else rmq[i][j] = rmq[i-1][j];
        }
    }
    while( q-- ){
        int a, b;
        scanf("%d %d",&a,&b);
        int lg = log2( b - a + 1 );
        printf("%d\n",max( rmq[lg][a], rmq[lg][b-(1<<lg)+1]));
    }
    return 0;
}
