#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d",&n);
        int mxa = -1, mxb = -1, chk = 0, pva = 0, pvb = 0;
        for( int i = 1, a, b ; i <= n ; i++ ) {
            scanf("%d %d",&a,&b);
            if( a < mxa || b < mxb || a < b || a < mxb  ) chk = 1;
            /*if( b - pvb > a - pva ) chk = 1;
            pva = a, pvb = b;*/
            mxa = max( mxa, a ), mxb = max( mxb, b );
        }
        if( chk ) printf("NO\n");
        else printf("YES\n");
    }
}