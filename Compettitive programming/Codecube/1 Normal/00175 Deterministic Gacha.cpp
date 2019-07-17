#include<bits/stdc++.h>
using namespace std;
int sum[100010], ans, n, k, mark[100010];
string rate;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        cin >> rate;
        if( rate == "UR" )mark[i] ++;
    }
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + mark[i];
    }
    for(int i=k;i<=n;i++){
        if( ans < sum[i]-sum[i-k] ) ans = sum[i]-sum[i-k];
    }
    printf("%d",ans);
    return 0;
}
