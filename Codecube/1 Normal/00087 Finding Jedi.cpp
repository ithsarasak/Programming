#include<bits/stdc++.h>

using namespace std;
long long n, m, power[1000010];
long long ans;
int main()
{
    scanf("%lld %lld",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        int t;
        scanf("%d",&t);
        power[t]++;
    }
    for( int i = 0 ; i <= m / 2 ; i++ ){
        if( i == m - i ) ans += ((power[i]*(power[i]-1))/2);
        else ans += ( power[i]*power[m-i] );
    }
    printf("%lld",ans);
    return 0;
}
