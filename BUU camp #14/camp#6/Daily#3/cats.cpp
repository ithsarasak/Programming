#include<bits/stdc++.h>

using namespace std;
long long n, ma, cat[2000100];
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&cat[i]);
        ma = max( ma, cat[i] );
    }
    long long l = 0, r = ma;
    while( l < r ){
        long long mid = ( l + r ) / 2;
        int st = 0, ch = 0;
        long long pro = 0;
        for( int i = 0 ; i < n ; i++ ){
            if( cat[i] > mid ){
                if( st == 1 ){
                    if( cat[i] == pro ){
                        st = 0;
                    }
                    else{
                        ch = 1;
                        break;
                    }
                }
                else{
                    pro = cat[i];
                    st = 1;
                }

            }
        }
        if( !ch )r = mid;
        else l = mid + 1;
    }
    printf("%d",l);
    return 0;
}
