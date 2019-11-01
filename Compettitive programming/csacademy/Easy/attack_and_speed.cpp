#include <bits/stdc++.h>

using namespace std;

long long a, s, k, x, y;
int main()
{
    scanf("%lld %lld %lld %lld %lld",&a,&s,&k,&x,&y);
    if( ( s - a + k*y ) % ( x + y ) != 0 ) return !printf("-1");
    printf("%lld",( s - a + k*y ) / ( x + y ));
    return 0;
}