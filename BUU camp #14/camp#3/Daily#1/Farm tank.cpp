#include<bits/stdc++.h>

using namespace std;
long long n, m, t[100010];
int check( long long tt )
{
    long long ans = 0;
    for( int i = 0 ; i < n ; i++ ){
        ans += tt / t[i];
    }
    if( ans >= m ) return 1;
    else return 0;
}
int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&t[i]);
    }
    long long l = 1, r = 1e18;
    while( l < r ){
        long long mid = ( l + r ) / 2;
        if( check( mid ) ) r = mid;
        else l = mid + 1;
    }
    printf("%lld",l);
    return 0;
}
