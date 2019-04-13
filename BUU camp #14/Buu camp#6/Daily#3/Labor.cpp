#include<bits/stdc++.h>

using namespace std;
long long n, m;
long long pw[1000100];
int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 0 ; i < n  ; i++ ){
        scanf("%lld",&pw[i]);
    }
    long long l = 1, r = 1e18;
    while( l < r ){
        long long mid = ( l + r ) / 2;
        long long all = 0;
        for( int i = 0 ; i < n ; i++ ){
            all += mid / pw[i];
        }
        if( all >= m ) r = mid;
        else l = mid + 1;
    }
    printf("%lld",l);
    return 0;
}
