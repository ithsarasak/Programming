#include<bits/stdc++.h>

using namespace std;
int n, m, ka, kb;
int mod = 1000000007;
int dp[110][110][110][110];
int topdown( int na, int nb, int ta, int tb )
{
    if( na == n && nb == m ){
        return dp[na][nb][ta][tb] = 1;
    }
    if( dp[na][nb][ta][tb] != - 1 ){
        return dp[na][nb][ta][tb];
    }
    int sum = 0;
    if( na < n & ta < ka ){
        sum += topdown( na + 1, nb, ta + 1, 0 );
    }
    if( nb < m && tb < kb ){
        sum += topdown( na, nb + 1, 0, tb + 1 );
    }
    return dp[na][nb][ta][tb] = sum % mod;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d %d %d %d",&n,&m,&ka,&kb);
    printf("%d",topdown( 0, 0, 0, 0 ));
    return 0;
}
