#include<bits/stdc++.h>

using namespace std;
int n, m, k;
int obj[200100];
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&obj[i]);
    }
    m--;
    int l = 0, r = n - 1;
    while( l < r ){
        int mid = ( l + r ) / 2;
        int nowsize = k, cnt = m, ch = 0;
        for( int i = mid + 1 ; i <= n ; i++ ){
            if( nowsize >= obj[i] ){
                nowsize -= obj[i];
            }
            else{
                if( cnt == 0 ){
                    ch = 1;
                    break;
                }
                else nowsize = k, cnt--;
                i--;
            }
        }
        if( ch )l = mid + 1;
        else r = mid;
    }
    printf("%d",n-l);
    return 0;
}
