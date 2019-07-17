#include<bits/stdc++.h>

using namespace std;

struct prop{
    int val, wt;
    bool operator<( const prop &k )const{
        if( k.val != val ){
            return wt < k.wt;
        }
        else{
            return val > k.val;
        }
    }
}data[1000];
int knapsack[1000][1000], n, maxwt;
int maxs( int a , int b )
{
    if( a > b ){
        return a;
    }
    else{
        return b;
    }
}
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d",&data[i].wt,&data[i].val);
    }
    scanf("%d",&maxwt);
    sort( data , data + n );
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j <= maxwt ; j++ ){
            if( j >= data[i - 1].wt ){
                knapsack[i][j] = maxs( knapsack[i - 1][j - data[i - 1].wt] + data[i - 1].val , knapsack[i - 1][j] );
            }
            else{
                knapsack[i][j] = knapsack[i - 1][j];
            }
        }
    }
    printf("%d",knapsack[n][maxwt]);
    return 0;
}
