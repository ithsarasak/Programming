#include<stdio.h>

long long sum, allsum[1000002], ans[1000002];
int i, j, amount, cipher[1000002];
int main()
{
    for( i = 1 ; i <= 1000000 ; i++ ){
        sum += i;
        allsum[i] = sum;
    }
    /*for( i = 1 ; i <= 20 ; i++ ){
        printf("%lld ",allsum[i]);
    }
    printf("\n");*/
    scanf("%d",&amount);

    for( i = 1 ; i <= amount ; i++ ){
        scanf("%d",&cipher[i]);
    }
    for( i = 1 ; i <= amount ; i++ ){
        ans[i] = cipher[i] * allsum[amount - i + 1];
        ans[i] %= 2553;
    }
    sum = 0;
    for( i = 1 ; i <= amount ; i++ ){
        sum += ans[i];
    }
    printf("%d",sum % 2553);
    return 0;
}
