#include<bits/stdc++.h>

using namespace std;
int n;
long long p, ti[100100];
int main()
{
    scanf("%d %d",&n,&p);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&ti[i]);
    }
    long long l = 1, r = 2000000000;
    while( l < r ){
        long long mid = ( l + r ) / 2;
        long long sum = 0;
        for( int i = 0 ; i < n ; i++ ){
            sum += ( mid / ti[i] ) + 1;
        }
        if( sum >= p )r= mid;
        else l = mid + 1;
    }
    printf("%lld",l);
    return 0;
}
