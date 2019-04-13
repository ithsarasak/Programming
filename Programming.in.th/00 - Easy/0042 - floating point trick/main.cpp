#include<stdio.h>
long double n = 1;
long long num, i, j;
int q;
int main()
{
    scanf("%d",&q);
    for( i = 0 ; i < q ; i++ ){
        scanf("%lld",&num);
        for( j = 0 ; j < num ; j++ ){
            n *= 2;
        }
        printf("%.0llf\n",n);
        n = 1;
    }
    return 0;
}
