#include<bits/stdc++.h>

using namespace std;
long long n, cats[2000010];
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&cats[i]);
    }
    long long l = 0, r = 2500000000;
    while( l < r ){
        //printf("%lld %lld\n",l,r);
        long long mid = ( l + r ) / 2;
        int st = 0, ss, ch = 0;
        for( int i = 0 ; i < n ; i++ ){
            if( cats[i] > mid && st ){
                if( cats[i] == ss ){
                    st = 0;
                }
                else{
                    ch = 1;
                    break;
                }
            }
            else if( cats[i] > mid && st == 0 ){
                st = 1;
                ss = cats[i];
            }
        }
        if( ch ){
            l = mid + 1;
        }
        else r = mid;
    }
    printf("%lld",l);
    return 0;
}
