#include<bits/stdc++.h>

using namespace std;
long long n, m, p, croc[100010], ans = 0;
int main()
{
    scanf("%lld %lld %lld",&n,&m,&p);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%lld",&croc[i]);
    }
    if( n < 2 * p ){
        printf("%lld",n*n);
    }
    sort( croc, croc + n );
    for(int i=0;i<2*p;i++){
        long long last = 0;
        for( int j=i;j<n;j+= 2 *p){
            ans = max( ans, croc[j] - last );
            last = croc[j];
        }
        ans = max( ans, m - last );
    }
    printf("%lld",ans*ans);
    return 0;
}
