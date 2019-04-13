#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long mic[2000100];
int n, k, q;
int main()
{
    mic[0] = 0;
    mic[1] = 1;
    for( int i = 2 ; i <= 2000000 ; i++ ){
        mic[i] = mic[i-1] + mic[i-2];
        mic[i] %= mod;
    }
    scanf("%d",&q);
    while( q-- ){
        scanf("%d %d",&n,&k);
        if( k == 0 ){
            printf("%lld\n",mic[n]);
            continue ;
        }
        long long plu = 0;
        for( int i = 0 ; i < k ; i++ ){
            int nu;
            long long b;
            scanf("%d %lld",&nu,&b);
            plu += mic[n-nu+1] * b;
            plu += mod;
            plu %= mod;
        }
        printf("%lld\n",(mic[n]+plu)%mod);
    }
    return 0;
}
