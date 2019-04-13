#include<stdio.h>
int book[2010], i, j, books;
long long dp[2010];
int more( int a , int b ){
    if( a >= b ){
        return a;
    }
    else{
        return b;
    }
}
int main()
{
    scanf("%d",&books);
    for( i = 0 ; i < books ; i++ ){
        scanf("%d",&book[i]);
    }
    dp[2] = book[0] + book[1] - book[2];
    for( i = 3 ; i < books ; i++ ){
        dp[i] = more( book[i - 1] + book[i - 2] - book[i] + dp[i - 3] , dp[i - 1] );
    }
    printf("%d",dp[books - 1]);
    return 0;
}
