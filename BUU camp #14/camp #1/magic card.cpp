#include<bits/stdc++.h>

using namespace std;

long long magic[3][5010], card1[5010], card2[5010],n, m;
int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&card1[i]);
    }
    for( int i = 1 ; i <= m ; i++ ){
        scanf("%lld",&card2[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            magic[i%2][j] = max( magic[( i - 1 ) % 2][j] , magic[i%2][j] );
            magic[i%2][j] = max( magic[i%2][j-1] , magic[i%2][j] );
            magic[i%2][j] = max( magic[(i-1)%2][j - 1] + abs( card1[i] - card2[j] ) , magic[i%2][j] );
        }
    }
    printf("%lld",magic[n%2][m]);
    return 0;
}
