#include<bits/stdc++.h>

using namespace std;

struct abi{
    int xl, xr, yl, yr, dis;
}fren[200010];
int main()
{
    int n, x1, x2, y1, y2;
    long long sum = 0;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d %d %d",&fren[i].xl,&fren[i].yl,&fren[i].dis);
        fren[i].xr = fren[i].xl + fren[i].dis;
        fren[i].xl = fren[i].xl - fren[i].dis;
        fren[i].yr = fren[i].yl + fren[i].dis;
        fren[i].yl = fren[i].yl - fren[i].dis;
    }
    x1 = fren[0].xl;
    x2 = fren[0].xr;
    y1 = fren[0].yl;
    y2 = fren[0].yr;
    for( int i = 1 ; i < n ; i++ ){
        int x3 = fren[i].xl;
        int x4 = fren[i].xr;
        int y3 = fren[i].yl;
        int y4 = fren[i].yr;
        int ma = max( x3 - x2 , x1 - x4 );
        ma = max( ma , y1 - y4 );
        ma = max( ma , y3 - y2 );
        ma = max( ma , 0 );
        x1 -= ma;
        x2 += ma;
        y1 -= ma;
        y2 += ma;
        x1 = max( x1 , x3 );
        x2 = min( x2 , x4 );
        y1 = max( y1 , y3 );
        y2 = min( y2 , y4 );
        sum += ma;
    }
    printf("%lld",sum);
    return 0;
}
