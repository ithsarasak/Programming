#include<bits/stdc++.h>
int i, num, n;
int main()
{
    printf("Enter flag size : ");
    scanf("%d",&num);
    printf("Flag1: \n");
    do{
        for( i = 0 ; i <= n ; i++ ){
            printf("%d",i);
        }
        printf("\n");
        n++;
    }while( n < num );

    n = 0;
    printf("Flag2 :\n");
    while( n < num ){
        for( i = 0 ; i < num - n - 1 ; i++ ){
            printf(" ");
        }
        for( i = 0 ; i <= n ; i++ ){
            printf("%d",i);
        }
        printf("\n");
        n++;
    }
    printf("Flag3 :\n");
    for( n = 0 ; n < num ; n++ ){
        for( i = 0 ; i < num - n - 1 ; i++ ){
            printf(" ");
        }
        for( i = n ; i >=0 ; i-- ){
            printf("%d",i);
        }
        for( i = 1 ; i <= n ; i++ ){
            printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
