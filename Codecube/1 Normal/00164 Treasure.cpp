#include<bits/stdc++.h>

using namespace std;

long long rai[123459], n, sum, currentsum, group = 3, group2 = 3, tempp, mx=-1e9, mi=1e9, sum2;
long long mx2 = -1e9, mi2=1e9;
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i ++ ){
        scanf("%lld",&rai[i]);
        sum += rai[i];
        sum2+= rai[i];
    }
    tempp = sum / group;
    for( int i = 0 ; i < n; i++ ){
        //printf("%d ",i);
        if( group == 1 ) break;
        if( group != 1 ){
            currentsum += rai[i];
            long long temp = abs(tempp-currentsum);
            long long temp2 = abs(currentsum + rai[i + 1] - tempp);
            if( temp <= temp2 || n-i <= group ){
                mx = max( mx ,currentsum );
                mi = min( mi, currentsum );
                sum -= currentsum;
                currentsum = 0;
                group--;
                tempp = sum / group;
            }
        }
    }
    mx = max( mx, sum );
    mi = min( mi, sum );
    tempp = sum2 / group2;
    currentsum = 0;
    for( int i = n - 1 ; i >= 0 ; i-- ){
        //printf("%d ",i);
        if( group2 == 1 ) break;
        if( group2 != 1 ){
            currentsum += rai[i];
            long long temp = abs(tempp-currentsum);
            long long temp2 = abs(currentsum + rai[i - 1] - tempp);
            if( temp <= temp2 || i + 1 <= group2){
                mx2 = max( mx2 ,currentsum );
                mi2 = min( mi2, currentsum );
                sum2 -= currentsum;
                currentsum = 0;
                group2--;
                tempp = sum2 / group2;
            }
        }
    }
    mx2 = max( mx2, sum2 );
    mi2 = min( mi2, sum2 );
    //printf("%lld %lld %lld %lld\n",mx,mi,mx2,mi2);
    printf("%lld",min( mx2-mi2, mx-mi ) );
    return 0;
}

