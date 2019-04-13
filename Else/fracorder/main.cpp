#include<bits/stdc++.h>
using namespace std;
int uclid( int a , int b ){
    if( a % b == 0 ){
        return b;
    }
    else{
        return uclid( b , a % b );
    }
}
struct a{
    int x, y;
    double harn;
    bool operator<( const a &k )const{
        return harn < k.harn;
    }
}ans[100010];
int n, i, j, counts;
int main()
{
    scanf("%d",&n);
    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j < i ; j++ ){
            if( uclid( i , j ) == 1 ){
                ans[counts].x = j;
                ans[counts].y = i;
                ans[counts].harn = ( double )j / i;
                counts++;
            }
        }
    }
    sort( ans , ans + counts );
    printf("0/1\n");
    for( i = 0 ; i < counts ; i++ ){
        printf("%d/%d\n",ans[i].x,ans[i].y);
    }
    printf("1/1\n");
    return 0 ;
}
