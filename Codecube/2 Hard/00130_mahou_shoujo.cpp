#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int dp[N], n, k, blood[N], idx[1020];
int main()
{
    memset( dp, 127, sizeof dp );
    fill( idx, idx + 1010, 1 );
    dp[0] = 0;
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&blood[i]);
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = 0 ; j <= 1000 ; j++ ) {
            if( blood[i] > j ) {
                idx[j] = i + 1;
                continue ;
            }
            while( i - idx[j] + 1 > k ) idx[j]++;
            dp[i] = min( dp[i], dp[idx[j]-1] + j );
        }
    }
    printf("%d",dp[n]);
    return 0;
}