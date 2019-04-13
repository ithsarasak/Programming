#include<stdio.h>
#include<vector>

using namespace std;

int n, i, x, m, k, p, q, dp[10010], ans = 0;

int max( int a , int b )
{
    return ( a > b ? a : b );
}

vector<int> a[10010];

int main()
{
    for(i = 0; i <= 10000; i++){
        dp[i] = -1;
    }
    scanf("%d %d %d",&k,&m,&n);
    dp[1] = k;
    for(i = 0; i < n; i++){
        scanf("%d %d",&p,&q);
        if(p > q){
            int t;
            t = p;
            p = q;
            q = t;
        }
        a[p].push_back( q );
    }
    for( i = 1 ; i <= m ; i++ ){
        if( dp[i] >= 0 ){
            ans = i;
        }
        for( x = 0 ; x < a[i].size() ; x++ ){
            dp[a[i][x]] = max( dp[i] - 1 , dp[a[i][x]] );
        }
    }
 printf("%d\n",ans);
}
