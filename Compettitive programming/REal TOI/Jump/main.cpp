#include<stdio.h>
int i, j, run[90001], sum[90001], n, k, dis[30001], max;
int main()
{
    scanf("%d %d",&n,&k);
    int t;
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&dis[i]);

        run[dis[i]]++;
    }
    for( i = 0 ; i < 90001 ; i++ ){
        if( i == 0 ){
            sum[i] = run[i];
        }
        else{
            sum[i] = sum[i-1] + run[i];
        }
    }

    for( i = 0 ; i < n ; i++ ){
        if( max < sum[dis[i]+k] - sum[dis[i]] ){
            //printf("%d %d",sum[dis[i]],sum[i+k]);
            max = sum[dis[i]+k] - sum[dis[i]];
        }
    }
    printf("%d",max);
}
