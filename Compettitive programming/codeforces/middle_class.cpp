#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int t, n;
long long a[N];
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        long long x, sum = 0;
        int ans = -1;
        scanf("%d %lld",&n,&x);
        for( int i = 1 ; i <= n ; i++ ) scanf("%lld",&a[i]);
        sort( a + 1, a + 1 + n, greater<int>() );
        for( int i = 1 ; i <= n ; i++ ) {
            sum += a[i];
            //printf("%lld %lld\n",x,sum);
            if( x*i > sum ) { 
                ans = i-1; 
                break ;
            }
        }
        if( ans == -1 ) ans = n;
        printf("%d\n",ans);
    }
    return 0;
}