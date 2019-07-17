#include<bits/stdc++.h>

using namespace std;
int n;
long long k;
long long pos[1010];
int main()
{
    scanf("%d %lld",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&pos[i]);
    }
    sort( pos, pos + n );
    long long l = 0, r = 320000000;
    while( l < r ){
        long long mid = ( l + r ) / 2;
        long long sum = 0;
        for( int i = 0 ; i < n - 1 ; i++ ){
            long long len = max( (long long )0, (pos[i]+mid)-(pos[i+1]-mid)+1 );
            if( len % 2 == 0 ) sum -= (len/2)*(len/2+1);
            else sum -= ((1+len)/2)*((1+len)/2);
            sum += (mid+1)*(mid+1);
        }
        sum += (mid+1)*(mid+1);
        if( sum >= k )r = mid;
        else l = mid+1;
    }
    printf("%lld",l);
    return 0;
}

