#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, k;
int x, y;
int row[2*N], col[2*N], down[2*N], up[2*N], ans = -1;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d %d",&x,&y);
        int sum = x + y, sum2 = x + n - y + 1;
        up[sum-1]++, down[sum2-1]++;
        row[x]++, col[y]++;
        if( ans == -1 ) {
            if( row[x] == k ) ans = i;
            else if( col[y] == k ) ans = i;
            else if( up[sum-1] == k ) ans = i;
            else if( down[sum2-1] == k ) ans = i;
        }
    }
    printf("%d",ans);
    return 0;
}