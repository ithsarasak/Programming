#include<bits/stdc++.h>

using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n / 2 + 1 ; i++ ){
        for( int j = 1 ; j <= ( n - ( i * 2 ) + 1 ) / 2 ; j++ ) printf("-");
        for( int j = 1 ; j <= ( i * 2 ) - 1 ; j++ ) printf("*");
        for( int j = 1 ; j <= ( n - ( i * 2 ) + 1 ) / 2 ; j++ ) printf("-");
        printf("\n");
    }
    for( int i = n / 2 ; i > 0 ; i-- ){
        for( int j = 1 ; j <= ( n - ( i * 2 ) + 1 ) / 2 ; j++ ) printf("-");
        for( int j = 1 ; j <= ( i * 2 ) - 1 ; j++ ) printf("*");
        for( int j = 1 ; j <= ( n - ( i * 2 ) + 1 ) / 2 ; j++ ) printf("-");
        printf("\n");
    }
}
