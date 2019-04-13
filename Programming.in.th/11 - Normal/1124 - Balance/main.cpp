#include<stdio.h>

long long want, i, sum[20], multi[20], t = 1, amount, sumweight;
int main()
{
    scanf("%lld",&want);
    sumweight = want;
    for( i = 0 ; i <= 19 ; i++ ){
        multi[i] = t;
        if( i == 0 ){
            sum[i] = t;
        }
        else{
            sum[i] = sum[i - 1] + t;
        }
        t *= 3;
    }
    for( i = 19 ; i >= 0 ; i-- ){
        if( i == 0 ){
            //printf("%lld ",i);
            if( want - multi[i] == 0 ){
                want -= multi[i];
                sumweight += multi[i];
                amount++;
            }
            else if( want + multi[i] == 0 ){
                want += multi[i];
                sumweight += multi[i];
                amount++;
            }
        }
        if( want - multi[i] <= sum[i - 1] && want - multi[i] >= -1 * sum[i - 1] ){
            //printf("%lld ",i);
            want -= multi[i];
            sumweight += multi[i];
            amount++;
        }
        else if( want + multi[i] <= sum[i - 1] and want + multi[i] >= -1 * sum[i - 1] ){
            want += multi[i];
            sumweight += multi[i];
            amount++;
        }
    }
    //printf("%lld",want);
    if( want == 0 ){
        printf("%lld %lld",amount,sumweight / 2);
    }
    return 0;
}
