#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, p1, p2;
double a[N], b[N], ans, sum1, sum2;

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%lf %lf",&a[i],&b[i]);
        a[i] = a[i] - 1, b[i] = b[i] - 1;
    }
    sort( a + 1, a + 1 + n, greater<double>() ), sort( b + 1, b + 1 + n, greater<double>() );
    p1 = p2 = 1;
    while( p1 <= n && p2 <= n ) {
        //cout << sum1 << " " << sum2 << endl;
        if( sum1 <= sum2 ) {
            sum1 += a[p1], sum2 -= 1.0;
            p1++;
        }   
        else {
            sum2 += b[p2], sum1 -= 1.0;
            p2++;
        }
        ans = max( ans, min( sum1, sum2 ) );
    }
    while( p1 <= n ) {
        sum1 += a[p1], sum2 -= 1.0;
        p1++;
        ans = max( ans, min( sum1, sum2 ) );
    }
    while( p2 <= n ) {
        sum2 += b[p2], sum1 -= 1.0;
        p2++;
        ans = max( ans, min( sum1, sum2 ) );
    }
    printf("%.4f",ans);
    return 0;
}