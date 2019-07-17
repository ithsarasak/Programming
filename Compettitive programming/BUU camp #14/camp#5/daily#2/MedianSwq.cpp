#include<bits/stdc++.h>

using namespace std;
int n, z,te, dp[100010], pe1[200010], pe2[200010], pos, ans;
int main()
{
    scanf("%d %d",&n,&z);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&te);
        if( te > z ) dp[i] = dp[i-1] + 1;
        else if( te < z )dp[i] = dp[i-1] - 1;
        else{
            dp[i] = dp[i-1];
            pos = i;
        }
    }
    for( int i = 0 ; i < pos ; i++ ){
        pe1[dp[i] + 100000]++;
    }
    for( int i = pos ; i <= n ; i++ ){
        pe2[dp[i] + 100000]++;
    }
    for( int i = 0 ; i <= 200000 ; i++ ){
        ans += pe1[i] * pe2[i];
    }
    printf("%d",ans);
    return 0;
}
