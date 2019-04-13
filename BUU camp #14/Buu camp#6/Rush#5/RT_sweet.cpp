#include<bits/stdc++.h>

using namespace std;
long long n, m, ma;
long long sum, mi;
long long sw[100100];
int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&sw[i]);
        ma = max( ma, sw[i] );
        sum += sw[i];
    }
    mi = sum / n;
    if( mi * n < sum )mi++;
    long long l = mi, r = ma;
    while( l < r ){
        long long mid = ( l + r ) / 2;
        long long ti = 0;
        long long zero = 0;
        for( int i = 0 ; i < n ; i++ ){
            ti += max( sw[i] - mid, zero );
        }
        if( ti <= m )r = mid;
        else l = mid + 1;
    }
    printf("%lld",l);
    return 0;
}
