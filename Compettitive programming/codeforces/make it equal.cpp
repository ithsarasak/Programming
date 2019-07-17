#include<bits/stdc++.h>

using namespace std;
long long tow[200100], sum[200100], mh, mih = 1e9, cnt;
long long n, k;
int main()
{
    scanf("%lld %lld",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        long long h;
        scanf("%lld",&h);
        tow[h]++;
        mh = max( mh, h );
        mih = min( mih, h );
    }
    for( int i = mh ; i >= 0 ; i-- ){
        tow[i] += tow[i+1];
        sum[i] = sum[i+1] + tow[i];
    }
    while( mh > mih ){
        long long l = 1, r = mh;
        while( l < r ){
            long long mid = ( l + r ) / 2;
            if( sum[mid] - sum[mh+1] <= k )r = mid;
            else l = mid + 1;
        }
        l--;
        mh = l;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
