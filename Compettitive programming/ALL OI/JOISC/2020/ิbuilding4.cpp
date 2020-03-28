#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

char ans[N];
int n, a[N], b[N], cnt, mx[N][2], mn[N][2], st;
int main()
{
    scanf("%d",&n);
    cnt = n;
    for( int i = 1 ; i <= 2*n ; i++ ) scanf("%d",&a[i]);
    for( int i = 1 ; i <= 2*n ; i++ ) scanf("%d",&b[i]);
    mx[1][0] = mn[1][0] = 1;
    mx[1][1] = mn[1][1] = 0;
    for( int i = 2 ; i <= 2*n ; i++ ) {
        mx[i][0] = mx[i][1] = -1e9;
        mn[i][0] = mn[i][1] = 1e9;
        if( a[i] >= a[i-1] ) {
            mx[i][0] = max( mx[i][0], mx[i-1][0] + 1 );
            mn[i][0] = min( mn[i][0], mn[i-1][0] + 1 );
        }
        if( a[i] >= b[i-1] ) {
            mx[i][0] = max( mx[i][0], mx[i-1][1] + 1 );
            mn[i][0] = min( mn[i][0], mn[i-1][1] + 1 );
        }
        if( b[i] >= a[i-1] ) {
            mx[i][1] = max( mx[i][1], mx[i-1][0] );
            mn[i][1] = min( mn[i][1], mn[i-1][0] );
        }
        if( b[i] >= b[i-1] ) {
            mx[i][1] = max( mx[i][1], mx[i-1][1] );
            mn[i][1] = min( mn[i][1], mn[i-1][1] );
        }
    }
    //printf("%d %d %d %d\n",mn[2*n][0],mx[2*n][0],mn[2*n][1],mx[2*n][1]);
    if( mn[2*n][0] <= n && mx[2*n][0] >= n ) st = 0, cnt--;
    else if( mn[2*n][1] <= n && mx[2*n][1] >= n ) st = 1;
    else return !printf("-1");
    ans[2*n] = st ? 'B' : 'A';
    for( int i = 2*n-1 ; i >= 1 ; i-- ) {
        if( st == 0 ) {
            if( a[i] <= a[i+1] && mn[i][0] <= cnt && mx[i][0] >= cnt ) ans[i] = 'A', cnt--, st = 0;
            else if( b[i] <= a[i+1] && mn[i][1] <= cnt && mx[i][1] >= cnt ) ans[i] = 'B', st = 1;
        }
        else {
            if( a[i] <= b[i+1] && mn[i][0] <= cnt && mx[i][0] >= cnt ) ans[i] = 'A', cnt--, st = 0;
            else if( b[i] <= b[i+1] && mn[i][1] <= cnt && mx[i][1] >= cnt ) ans[i] = 'B', st = 1;
        }
    }
    for( int i = 1 ; i <= 2*n ; i++ ) printf("%c",ans[i]);
    return 0;
}