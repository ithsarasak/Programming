#include<stdio.h>
int amount, num[2500], i, j, sum[2500], max = -1000000000, posbe, posend;
int main()
{
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ ){
        scanf("%d",&num[i]);
        if( i == 0 ){
            sum[0] = num[0];
        }
        else{
            sum[i] = num[i] + sum[ i - 1 ];
        }
        if( max < sum[i] ){
            max = sum[i];
            posbe = 0;
            posend = i;
        }
    }
    for( i = 1 ; i < amount ; i++ ){
        for( j = 0 ; j < i ; j++ ){
            if( max < sum[i] - sum[j] ){
                max = sum[i] - sum[j];
                posbe = j + 1;
                posend = i;
            }
        }
    }
    if( max <= 0 )
    {
        printf("Empty sequence");
    }
    else
    {
        for( i = posbe ; i <= posend ; i++ ){
            printf("%d ",num[i]);
        }
        printf("\n");
        printf("%d",max);
    }
}
