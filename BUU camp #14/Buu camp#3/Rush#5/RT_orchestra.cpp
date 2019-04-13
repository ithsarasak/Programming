#include<bits/stdc++.h>

using namespace std;
long long n, m, k, t;
long long buc[150], sum[150];
vector<int> gg;
int main()
{
    scanf("%lld %lld %lld",&n,&m,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&t);
        buc[t]++;
        sum[t] += buc[t];
    }
    for( int i = 0 ; i < k ; i++ ){
        gg.push_back( n / k );
    }
    for( int i = 0 ; i < n % k ; i++ ){
        gg[i]++;
    }
    long long posi = 0, mx = 0, sumsound = 0;
    for( int i = 1 ; i <= m ; i++ ){
        if( mx < sum[i] ){
            mx = sum[i];
            posi = i;
        }
        sumsound += sum[i];
    }
    printf("%lld",sumsound-buc[posi]+1);
    return 0;
}
