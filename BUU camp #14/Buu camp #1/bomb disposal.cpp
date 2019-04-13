#include<bits/stdc++.h>

using namespace std;

long long s, m, l, r;
int main()
{
    scanf("%lld %lld",&s,&m);
    r = s;
    while( l <= r ){
        long long mid = ( l + r ) / 2;
        long long b = s - mid;
        if( b * mid > m || mid * b / b != mid ){
            r = mid - 1;
        }
        else if( b * mid < m ){
            l = mid + 1;
        }
        else{
            printf("%lld %lld",mid,b);
            return 0;
        }
    }
    printf("Goodbye T-T");
    return 0;
}
