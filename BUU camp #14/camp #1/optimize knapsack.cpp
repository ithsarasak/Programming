#include<bits/stdc++.h>

using namespace std;

struct item{
    int weight, value;
}allitem[2000001];
int knap[3][2000001];
int i, n, k;
int main()
{
    scanf("%d %d",&k,&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&allitem[i].value,&allitem[i].weight);
    }
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 1 ; j <= k ; j++ ){
            if( j >= allitem[i].weight ){
                if( i % 2 == 0 ){
                    knap[1][j] = max( knap[2][j] , knap[2][j - allitem[i].weight] + allitem[i].value );
                }
                else{
                    knap[2][j] = max( knap[1][j] , knap[1][j - allitem[i].weight] + allitem[i].value );
                }
            }
            else{
                if( i % 2 == 0 ){
                    knap[1][j] = knap[2][j];
                }
                else{
                    knap[2][j] = knap[1][j];
                }
            }
        }
    }
    if( n % 2 ){
        printf("%d",knap[1][k] );
    }
    else{
        printf("%d",knap[2][k] );
    }
    return 0;
}
