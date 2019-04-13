#include<stdio.h>
int max( int a , int b )
{
    return ( a > b ? a : b );
}
int n, sum[100], num[100], i, j;
int main()
{
    scanf("%d",&n);

    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
        if( i == 0 ){
            sum[i] = max( num[i] , 0 );
        }
        else if( i == 1 ){
            sum[i] = max( sum[i - 1] , num[i] );
        }
        else{
            sum[i] = max( num[i] + sum[i - 2] , sum[i - 1] );
        }
    }
    printf("%d",sum[n-1]);
}
