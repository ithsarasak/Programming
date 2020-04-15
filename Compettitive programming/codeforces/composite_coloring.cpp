#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int t, a[N], n;
int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        int ans = 0;
        int mark[N];
        memset( mark, 0, sizeof mark );
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
        for( int i = 0 ; i < 25 ; i++ ) {
            int cnt = 0;
            for( int j = 1 ; j <= n ; j++ ) if( !mark[j] && a[j] % prime[i] == 0 ) {
                //printf("%d %d\n",prime[i],a[j]);
                mark[j] = ans+1;
                cnt++;
            }
            if( cnt ) ans++;
        }
        printf("%d\n",ans);
        for( int i = 1 ; i <= n ; i++ ) printf("%d ",mark[i]);
        printf("\n");
    }
    return 0;
}