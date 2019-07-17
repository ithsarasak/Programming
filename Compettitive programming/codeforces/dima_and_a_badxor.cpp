#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10;
int n, m, mat[N][N], dp[N][1024], path[N][1024];
vector<int> ans;

int main()
{
    dp[0][0] = 1;
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) scanf("%d",&mat[i][j]);
    for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) for( int k = 0 ; k < 1024 ; k++ ) if( dp[i-1][k] ) {
        dp[i][mat[i][j]^k] = 1;
        path[i][mat[i][j]^k] = j;
    }
    for( int i = 1 ; i <= 1023 ; i++ ) if( dp[n][i] ) {
        printf("TAK\n");
        while( n != 0 ) {
            ans.emplace_back( path[n][i] );
            i ^= mat[n][path[n][i]];
            n--;
        }
        for( int j = ans.size() - 1 ; j >= 0 ; j-- ) printf("%d ",ans[j]);
        return 0;
    }
    printf("NIE");
    return 0;
}