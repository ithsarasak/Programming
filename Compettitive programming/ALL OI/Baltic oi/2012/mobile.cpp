#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n;
double L, x[N], y[N];

bool check( double mid ) {
    double mx = 0;
    for( int i = 1 ; i <= n ; i++ ) {
        double len = sqrt( mid*mid - y[i]*y[i] );
        double le = x[i] - len, ri = x[i] + len;
        if( le <= mx ) mx = max( mx, ri );
    }
    return ( mx >= L );
}
int main()
{
    scanf("%d %lf",&n,&L);
    for( int i = 1 ; i <= n ; i++ ) scanf("%lf %lf",&x[i],&y[i]);
    double l = 1, r = 5e8;
    while( r - l > 0.001 ) {
        double mid = ( l + r ) / 2.0;
        if( check( mid ) ) r = mid;
        else l = mid;
    }
    printf("%.4lf",l);
    return 0;
}