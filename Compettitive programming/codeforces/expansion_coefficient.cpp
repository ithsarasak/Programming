#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 3e5 + 10;
int n, ans = 1e9 + 10;
int mi[N], mx[N];
pii num[N];
int main()
{
    scanf("%d",&n);
    for( int i = 1, a ; i <= n ; i++ ) {
        scanf("%d",&a);
        num[i] = pii( a, i );
    }
    sort( num + 1, num + 1 + n );
    mi[n+1] = 1e9 + 1;
    for( int i = n ; i >= 1 ; i-- ) {
        mi[i] = min( num[i].y, mi[i+1] );
        mx[i] = max( num[i].y, mx[i+1] );
    }
    for( int i = 1 ; i < n ; i++ ) {
        ans = min( ans, min( num[i].x / abs( num[i].y - mx[i+1] ), num[i].x / abs( num[i].y - mi[i+1] ) ) );
        //cout << ans << " ";
    }
    printf("%d",ans);
    return 0;
}