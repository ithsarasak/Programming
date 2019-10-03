#include <bits/stdc++.h>

using namespace std;
const int N = 5e2 + 50;

int arr[N][N], arr2[N][N], n, m;

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) scanf("%d",&arr[i][j]);
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) scanf("%d",&arr2[i][j]);
    for( int i = 1 ; i < n ; i++ ) for( int j = 1 ; j < m ; j++ ) if( arr[i][j] != arr2[i][j] ) {
        arr[i][j] ^= 1, arr[i][j+1] ^= 1;
        arr[i+1][j] ^= 1, arr[i+1][j+1] ^= 1;
    }
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) if( arr[i][j] != arr2[i][j] ) {
        printf("No");
        return 0;
    }
    printf("Yes");
    return 0;
}