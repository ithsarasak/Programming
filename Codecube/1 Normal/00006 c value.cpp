#include<bits/stdc++.h>

using namespace std;
long long n, maxs, man;
long long num[1000010];
long long c;
int main()
{
    scanf("%lld",&n);
    for( int i = 1 ; i <= n ; i++ ){
        long long t;
        scanf("%lld",&t);
        if( i % 2 ){
            c -= t;
            num[i] = -1 * t;
        }
        else{
            c += t;
            num[i] = t;
        }
    }
    man = 0;
    maxs = 0;
    //printf("%lld\n",c);
    for( int i = 1 ; i <= n ; i++ ){
        man += num[i];
        maxs = max( maxs, man );
        if( man < 0 ){
            man = 0;
        }
        //printf("%lld %lld %lld\n",num[i],man,maxs);
    }
    maxs *= 2;
    //printf("%lld\n",maxs);
    printf("%lld",c-maxs );
    return 0;
}
