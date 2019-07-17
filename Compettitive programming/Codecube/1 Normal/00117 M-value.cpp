#include<bits/stdc++.h>

using namespace std;
int t, n, k;
int dp[2][100100], va[1010];
int main()
{
    scanf("%d",&t);
    for( int z = 1 ; z <= t ; z++ ){
        int mx = 0;
        scanf("%d %d",&n,&k);
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&va[i]);
        }
        for( int i = 0 ; i <= k ; i++ ){
            dp[0][i] = 0;
            dp[1][i] = 0;
        }
        dp[0][0] = 1;
        dp[1][0] = 1;
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 0 ; j < k ; j++ ){
                dp[i%2][j] = dp[(i+1)%2][j];
                int x = j - va[i];
                while( x < 0 )x += k;
                if( dp[(i+1)%2][x%k] ){
                    dp[i%2][j] = 1;
                }
            }
        }
        for( int i = k-1 ; i >= 0 ; i-- ){
            if( dp[n%2][i] ){
                mx = i;
                break;
            }
        }
        printf("Case #%d: %d\n",z,mx);
    }
    return 0;
}
