#include<bits/stdc++.h>
int n, k, house[1000010], i, sum[1000010], maxs = -2000000001;
int main()
{
    scanf("%d %d",&n,&k);
    for( i = 1 ; i <= n ; i++ ){
        scanf("%d",&house[i]);
        if( i > k ){
            sum[i] = sum[i - 1] + house[i] - house[i - k];
        }
        else{
            sum[i] = sum[i - 1] + house[i];
        }
        if( sum[i] > maxs && i > k ){
            maxs = sum[i];
        }
        else if( i <= k ){
            maxs = sum[i];
        }
    }
    printf("%d",maxs);
    return 0;
}
