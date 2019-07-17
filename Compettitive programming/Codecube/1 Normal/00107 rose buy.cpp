#include<bits/stdc++.h>

using namespace std;
long long sum[1000001], now, mx, pre;
int n, k, rose[1000001];
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&rose[i]);
        sum[i] = sum[i - 1] + ( long long )rose[i];
    }
    pre = sum[k];
    mx = pre;
    for( int i = k + 1 ; i <= n ; i++ ){
        now = pre + ( long long )rose[i];
        now = max( now , sum[i] - sum[i - k] );
        if( mx < now ){
            mx = now;
        }
        pre = now;
    }
    printf("%lld",mx);
    return 0;
}
