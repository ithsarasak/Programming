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
int i, j, counts, n, z;
int main()
{
    for( i = 1 ; i <= 99 ; i++ ){
        for( j = 1 ; j < i ; j++ ){
            if( uclid( i , j ) == 1 ){
                ans[counts].x = j;
                ans[counts].y = i;
                ans[counts].harn = ( double )j / i;
                counts++;
            }
        }
    }
    ans[counts].x = 0;
    ans[counts].y = 1;
    ans[counts].harn = 0;
    counts++;
    ans[counts].x = 1;
    ans[counts].y = 1;
    ans[counts].harn = 1;
    counts++;
    sort( ans , ans + counts );
    scanf("%d",&n);
    for( z = 0 ; z < n ; z++ ){
        int up, down;
        scanf("%d %d",&up,&down);
        double polharn = ( double )up / down;
        int first = 0 ;
        int last = counts - 1;
        int mid;
        while( 1 ){
            mid = ( first + last ) / 2;
            if( first + 1 == last ){
                printf("%d %d %d %d\n",ans[first].x,ans[first].y,ans[last].x,ans[last].y);
                break;
            }
            else if( ans[mid].harn > polharn ){
                last = mid;
            }
            else if( ans[mid].harn < polharn ){
                first = mid;
            }
        }
    }
    return 0 ;
}
