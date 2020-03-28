#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define x first
#define y second 

using namespace std;

const int N = 1e6 + 10;
pii p[N];
double sum, pi = 1, ans = -1;
int main() 
{
    scanf("%d",&n);
    for ( int i = 1 ; i <= n ; i++ ) scanf("%lld %lld",&p[i].x,&p[i].y);
    int l = 1, r = 1;
    while ( l <= n ) {
        while ( r <= n && sum < 10000.00 ) {
            double x = ( double )p[r].y / 10000.00;
            pi *= x;
            sum += ( double )( p[r].x * 10000 ) / ( double )p[r].y;
            r++;
        }
        ans = max( ans, pi * sum );
        double x = ( double )p[l].y / 10000.00;
        pi /= x;
        sum -= ( double )( p[l].x * 10000 ) / ( double )p[l].y;
        l++;
    }
    printf("%.0lf",ans * 10000.00);
    return 0;
}