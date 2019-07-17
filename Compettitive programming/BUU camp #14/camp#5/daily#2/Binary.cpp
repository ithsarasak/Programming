#include<bits/stdc++.h>

using namespace std;
int n, mark[25][2097155], dp[100010];
char w[25], fi[100010];
int main()
{
   scanf("%d",&n);
   for( int i = 0 ; i < n ; i++ ){
        scanf("%s",w);
        int len = strlen( w ), nu = 0;
        for( int j = 0 ; j < len ; j++ ){
            nu += ( w[j] - '0' ) * ( 1 << ( len - 1 - j ) );
        }
        mark[len][nu] = 1;
   }
   scanf("%s",&fi[1]);
   int le = strlen( &fi[1] );
   dp[0] = 1;
   for( int i = 1 ; i <= le ; i++ ){
        int su = 0, co = 0;
        for( int j = i - 1 ; j >= 0 && co < 20 ; j--, co++ ){
            su += ( fi[j+1] - '0' ) * ( 1 << ( i - 1 - j ) );
            if( mark[i-j][su] ){
                dp[i] += dp[j];
                dp[i] %= 1000000007;
            }
        }
   }
   printf("%d",dp[le]);
   return 0;
}
