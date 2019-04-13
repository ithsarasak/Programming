#include<bits/stdc++.h>

using namespace std;
int n, t;
int main()
{
    scanf("%d",&n);
    t = ( 2 * n ) + 1;
    for( int i = 0 ; i < t ; i++ ){
        printf("- ");
    }
    printf("\n");
    for( int i = 2 ; i < n ; i++ ){
        int te = ( 2 * i ) - 1;
        for( int j = 0 ; j < ( t - te ) / 2 ; j++ ){
            printf("- ");
        }
        for( int j = 0 ; j < te ; j++ ){
            printf("# ");
        }
        for( int j = 0 ; j < ( t - te ) / 2 ; j++ ){
            printf("- ");
        }
        printf("\n");
    }
    for( int i = 1 ; i <= n - 2 ; i++ ){
        printf("- ");
        for( int j = 0 ; j < i ; j++ ){
            printf("# ");
        }
        printf("- ");
        for( int j = 0 ; j < t - ( 2 * i ) - 4 ; j++ ){
            printf("# ");
        }
        printf("- ");
        for( int j = 0 ; j < i ; j++ ){
            printf("# ");
        }
        printf("- \n");
    }
    for( int i = 0 ; i < 2 ; i++ ){
        printf("- ");
        for( int j = 0 ; j < n - 1 ; j++ ){
            printf("# ");
        }
        printf("- ");
        for( int j = 0 ; j < n - 1 ; j++ ){
            printf("# ");
        }
        printf("- \n");
    }
    for( int i = n - 2 ; i >= 2 ; i-- ){
        for( int j = 0 ; j < ( t - 2*i - 1 ) / 2 ; j++ ){
            printf("- ");
        }
        for( int j = 0 ; j < i ; j++ ){
            printf("# ");
        }
        printf("- ");
        for( int j = 0 ; j < i ; j++ ){
            printf("# ");
        }
        for( int j = 0 ; j < ( t - 2*i - 1 ) / 2 ; j++ ){
            printf("- ");
        }
        printf("\n");
    }
    for( int i = 0 ; i < t ; i++ ){
        printf("- ");
    }
    return 0;
}
