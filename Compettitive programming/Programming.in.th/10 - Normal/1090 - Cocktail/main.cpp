#include<stdio.h>
long long num[200001], i, j, sum, kai, count;
int main()
{
    scanf("%lld",&kai);
    long long t;
    for( i = 0 ; i < kai ; i++ )
    {
        scanf("%lld",&t);

        num[t]++;
    }
    /*for( i = 0 ; i < 2 ; i++ )
    {
        printf("%d ",i);
        printf("%d ",num[i]);
    }*/
    scanf("%lld",&sum);
    for( i = 0 ; i <= sum / 2 ; i++ )
    {
        /*printf("i : %d\n",i);
        printf("num : %d\n",num[i]);
        printf("count : %d\n",count);*/
        if( i == sum - i )
        {
            count += ( num[i] * ( num[i] - 1 ) ) / 2;
        }
        else if( num[i] && num[sum-i] )
        {
            count += num[i] * num[sum-i];
        }
    }
    printf("%lld",count);
    return 0;
}
