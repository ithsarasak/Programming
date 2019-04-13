#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6 + 100;
long long pe[sz+5], cpy[sz+5];
int main()
{
    int n,k,p;
    scanf("%d %d %d",&n,&k,&p);
    for( int i = 1; i <= n ; i++ ) {
        scanf("%d",&pe[i]);
        cpy[i] = pe[i];
    }
    sort( cpy + 1, cpy + n + 1 );
    int l = 1, r = n, ans = n;
    while( l <= r )
    {
        int m = ( l + r ) / 2 , cnt=0;
        long long chk = cpy[m];
        for( int i = 1 ; i <= n ; ) {
           if( pe[i] > chk ) {
               cnt++;
               int j = 0;
               while( j < p && i + j <= n ) j++;
               i += j;
           }
           else i++;
        }
        if( cnt <= k ) {
            ans = min( ans, m );
            r = m - 1;
        }
        else l = m + 1;
    }
    printf("%lld",cpy[ans]);
    return 0;
}

