#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m, col[N], ans[N];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= m ; i++ ) scanf("%d",&col[i]);
    for( int i = 1 ; i <= m ; i++ ) {
        int x = n - col[i] + 1;
        if( x < i ) return !printf("-1\n");
        else ans[i] = i;
    }
    int rb = n;
    for( int i = m ; i >= 1 ; i-- ) {
        int r = ans[i] + col[i] - 1;
        if( r < rb ) {
            ans[i] += rb - r;
            rb = ans[i] - 1;
        }
        else break;
    }
    if( ans[1] > 1 ) return !printf("-1\n"); 
    for( int i = 1 ; i <= m ; i++ ) printf("%d ",ans[i]);
    return 0;
}