#include<stdio.h>
int road, sumr[110], suml[110], sum1[110], sum2[110], maxsum, num;
int i, j;
int sum, m, n;
int main()
{
    scanf("%d %d",&m,&n);
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            scanf("%d",&road);
            sumr[i] += road;
            suml[j] += road;
            sum += road;
        }
    }
    for( i = 1 ; i <= m ; i++ ){
        for( j = 1 ; j <= n ; j++ ){
            scanf("%d",&road);
            sum1[i] += road;
            sum2[j] += road;
        }
    }
    for( i = 1 ; i <= m ; i++ ){
        num = sum;
        num += sum1[i + 1] - sumr[i] + sum1[i - 1];
        if( num > maxsum ){
            maxsum = num;
        }
    }
    for( i = 1 ; i <= n ; i++ ){
        num = sum;
        num += sum2[i + 1] - suml[i] + sum2[i - 1];
        if( num > maxsum ){
            maxsum = num;
        }
    }
    printf("%d",maxsum);
    return 0;
}
