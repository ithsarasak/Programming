#include <bits/stdc++.h>

using namespace std;

int t;
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        int n, m;
        scanf("%d %d",&n,&m);
        if( n == 1 && m % 2 == 0 ) {
            for( int i = 1 ; i <= m - 2 ; i++ ) {
                if( i % 2 )printf("B");
                else printf("W");
            }
            printf("BB");
            printf("\n");
        }
        else if(  m == 1 && n % 2 == 0 ) {
            for( int i = 1 ; i <= n - 2 ; i++ ) {
                if( i % 2 )printf("B\n");
                else printf("W\n");
            }
            printf("B\nB");
            printf("\n");
        }
        else if( n*m % 2 ) {
            for( int i = 1 ; i < n ; i++ ) {
                for( int j = 1 ; j <= m ; j++ ) {
                    if( i % 2 ) printf("B");
                    else printf("W");
                }
                printf("\n");
            }
            for( int j = 1 ; j <= m ; j++ ) {
                if( j % 2 )printf("B");
                else printf("W");
            }
            printf("\n");
        }
        else {
            if( n % 2  == 0 ) {
                for( int j = 1 ; j <= m ; j++ ) printf("B");
                printf("\n");
                for( int j = 1 ; j < m ; j++ ) printf("W");
                printf("B");
                printf("\n");
                for( int i = 3 ; i <= n ; i++ ) {
                    for( int j = 1 ; j <= m ; j++ ) {
                        if( i % 2 ) printf("B");
                        else printf("W");
                    }
                    printf("\n");
                }
            }
            else {
                for( int i = 1 ; i < n ; i++ ) {
                    for( int j = 1 ; j <= m ; j++ ) {
                        if( j % 2 ) printf("B");
                        else printf("W");
                    }
                    printf("\n");
                }
                printf("BB");
                for( int i = 3 ; i <= m ; i++ ) {
                    if( i % 2 ) printf("B");
                    else printf("W");
                }
                printf("\n");
            }
        }
    }
}