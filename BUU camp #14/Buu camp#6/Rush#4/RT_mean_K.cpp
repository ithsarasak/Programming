#include<bits/stdc++.h>

using namespace std;
long long n, num[1000100], sum[1000100], sum2[1000100], fw[1000100], pz;
long long ans, k;
long long query( int idx )
{
    long long sum = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ){
        sum += fw[i];
    }
    return sum;
}
void up( int idx )
{
    for( int i = idx ; i <= 1000100 ; i += ( i & -i ) ){
        fw[i] += 1;
    }
}
int main()
{
    scanf("%lld",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%lld",&num[i]);
    }
    scanf("%lld",&k);
    for( int i = 1 ; i <= n ; i++ ){
        num[i] -= k;
        sum[i] = num[i] + sum[i-1];
        sum2[i] = sum[i];
    }
    sort( sum2, sum2 + 1 + n );
    /*for( int i = 1 ; i <= n ; i++ ){
        printf("%lld ",sum[i]);
    }
    printf("\n");*/
    for( int i = 0 ; i <= n ; i++ ){
        sum[i] = lower_bound( sum2, sum2 + 1 + n , sum[i] ) - sum2;
        sum[i] ++;
    }
    /*for( int i = 1 ; i <= n ; i++ ){
        printf("%lld ",sum2[i]);
    }
    printf("\n");
    for( int i = 1 ; i <= n ; i++ ){
        printf("%lld ",sum[i]);
    }
    printf("\n");*/
    up( sum[0] );
    for( int i = 1 ; i <= n ; i++ ){
        ans += query( sum[i] );
        up( sum[i] );
    }
    printf("%lld",ans);
    return 0;
}
