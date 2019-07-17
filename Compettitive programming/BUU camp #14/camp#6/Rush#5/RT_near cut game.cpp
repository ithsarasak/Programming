#include<bits/stdc++.h>

using namespace std;
long long num[100100], n, q, ma, mic[100100], buc[100100];
int main()
{
    scanf("%lld",&q);
    while( q-- ){
        memset( buc, 0, sizeof buc );
        memset( mic, 0, sizeof mic );
        scanf("%lld",&n);
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%lld",&num[i]);
            buc[num[i]]++;
            ma = max( ma, num[i]);
        }
        int pos = ma;
        for( int i = ma ; i >= 1 ; i-- ){
            mic[i] = mic[i+2]+(buc[i]*i);
            mic[i] = max( mic[i], mic[i+1] );
        }
        printf("%lld\n",mic[1]);
    }
    return 0;
}
