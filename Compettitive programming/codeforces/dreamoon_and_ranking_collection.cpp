#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;
int t, chk[N*10], n, x, ans;
int main()
{
    scanf("%d",&t);
    while( t-- ) {
        int cnt = 0;
        memset( chk, 0, sizeof chk );
        scanf("%d %d",&n,&x);
        for( int i = 1, temp ; i <= n ; i++ ) {
            scanf("%d",&temp);
            chk[temp] = 1;
        }
        for( int i = 1 ; i <= 1000; i++ ) {
            if( !chk[i] ) {
                cnt++;
                if( cnt > x ) { ans = i - 1; break; }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}