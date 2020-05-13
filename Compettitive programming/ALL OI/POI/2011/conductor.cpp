#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, mx = -1, h[N], mxl[N], mxr[N];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&h[i]);
    for( int i = 1 ; i <= n ; i++ ) {
        mxl[i] = max( mxl[i], h[i] );
        if( h[i] <= mx ) continue ;
        mx = max( mx, h[i] );
        for( int d = 0 ; i + d*d + 1 <= n ; d++ ) {
            int pos = i + d*d + 1;
            mxl[pos] = max( mxl[pos], h[i] + d + 1 );
        }
    }
    mx = -1;
    for( int i = n ; i >= 1 ; i-- ) {
        mxr[i] = max( mxr[i], h[i] );
        if( h[i] <= mx ) continue ;
        mx = max( mx, h[i] );
        for( int d = 0; i - d*d - 1 > 0 ; d++ ) {
            int pos = i - d*d - 1;
            mxr[pos] = max( mxr[pos], h[i] + d + 1 );
        }
    }
    for( int i = 1 ; i <= n ; i++ ) mxl[i] = max( mxl[i], mxl[i-1] );
    for( int i = n ; i >= 1 ; i-- ) mxr[i] = max( mxr[i], mxr[i+1] );
    for( int i = 1 ; i <= n ; i++ ) printf("%d\n",max( mxl[i], mxr[i] ) - h[i] );
    return 0;
}