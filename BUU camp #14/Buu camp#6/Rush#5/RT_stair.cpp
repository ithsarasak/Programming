#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long mic[4][2000100];
long long q, n;
int main()
{
    mic[1][1] = 1;
    mic[2][1] = 3;
    mic[1][2] = 2;
    mic[2][2] = 9;
    for( int i = 3 ; i <= 2000000 ; i++ ){
        mic[1][i] = mic[1][i-1] + mic[1][i-2];
        mic[1][i] %= mod;
    }
    for( int i = 3 ; i <= 1000000 ; i++ ){
        long long t = mic[2][i-2] - mic[1][i-2] + mod;
        long long t2 = mic[2][i-1] - mic[1][i-1] + mod;
        t %= mod;
        t2 %= mod;
        mic[2][i] = mic[1][i] + t;
        mic[2][i] %= mod;
        mic[2][i] += t2;
        mic[2][i] %= mod;
        mic[2][i] += mic[1][i*2];
        mic[2][i] %= mod;
    }
    scanf("%lld",&q);
    while( q-- ){
        scanf("%lld",&n);
        printf("%lld\n",mic[2][n]);
    }
    return 0;
}
