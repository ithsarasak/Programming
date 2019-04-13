#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define fi first
#define se second
const double pi = 5.268 ;
const int N = 1e5+9 ;
char s[550];
int dp[550][550];
main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s);
        for(int L = 1 ; L <= n ; ++L ){
        for(int i = 0 ; i < n-L +1 ; ++i){
            int j = i + L  -1;
            if(L == 1){
                dp[i][j] = 1;
            }
    else{
                dp[i][j] = 600;
                for(int k = i+1 ; k <= j ; ++k){
                    if(s[i] == s[k])
                dp[i][j] = min(dp[i][j] , dp[k][j] + dp[i+1][k-1]);
                    else
                dp[i][j] = min(dp[i][j] , dp[i+1][j] + 1);
        }
    }
}
}
    printf("%d",dp[0][n-1]);
    return ;
 }
