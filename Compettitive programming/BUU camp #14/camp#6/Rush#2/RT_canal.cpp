#include<bits/stdc++.h>

using namespace std;
int n, k, nowpos, stone[300100], ma;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&stone[i]);
        ma = max( ma, stone[i] );
    }
    int l = 1, r = ma;
    while( l < r ){
        int ch = 0;
        nowpos = 0;
        int mid = ( l + r + 1 ) / 2;
        for( int i = 1 ; i <= n ; i++ ){
            if( stone[i] >= mid ){
                if( i - nowpos <= k )nowpos = i;
                else{
                    ch = 1;
                    break;
                }
            }
        }
        if( nowpos < n + 1 - k || ch == 1 ){
            r = mid - 1;
        }
        else l = mid;
    }
    printf("%d",l);
    return 0;
}
