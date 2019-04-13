#include<bits/stdc++.h>

using namespace std;
long long q, n, ans;
long long l[100100], r[100100], num[100100];
int main()
{
    scanf("%lld",&q);
    while( q-- ){
        memset( l, 0, sizeof l );
        memset( r, 0, sizeof r );
        ans = 0;
        scanf("%lld",&n);
        for( int i = 1 ; i <= n ; i ++ ){
            scanf("%lld",&num[i]);
        }
        l[1] = 0;
        r[n] = n+1;
        for( int i = 2 ; i <= n ; i++ ){
            l[i]= i - 1;
            while( l[i] > 0 && num[i] <= num[l[i]] ){
                l[i] = l[l[i]];
            }
        }
        for( int i = n - 1 ; i >= 1 ; i-- ){
            r[i] = i + 1;
            while( r[i] <= n && num[i] <= num[r[i]] ){
                r[i] = r[r[i]];
            }
        }
        for( int i = 1 ; i <= n ; i++ ){
            ans = max( ans, ( r[i] - l[i] - 1 ) * num[i] );
        }
        printf("%lld\n",ans);
    }
    return 0;
}
