#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], cnt[5];
int t, n;
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        memset( cnt, 0, sizeof cnt );
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ) {
            scanf("%d",&a[i]);
            cnt[a[i]+1]++;
        }
        int chk = 0;
        for( int i = 1 ; i <= n ; i++ ) scanf("%d",&b[i]);
        for( int i = n ; i >= 1 ; i-- ) {
            cnt[a[i]+1]--;
            int d = b[i] - a[i];
            if( d < 0 && cnt[0] == 0 ) {
                printf("NO\n");
                chk = 1;
                break;
            } 
            if( d > 0 && cnt[2] == 0 ) {
                printf("NO\n");
                chk = 1;
                break;
            }
        }
        if( chk ) continue;
        printf("YES\n");
    }
    return 0;
}