#include<bits/stdc++.h>

using namespace std;
int t;
long long num[100010], xo[100010], buc[150];
int main()
{
    scanf("%d",&t);
    while( t-- ){
        long long n, m;
        long long ans = 0;
        scanf("%lld %lld",&n,&m);
        memset( buc, 0, sizeof buc );
        memset( xo, 0, sizeof xo );
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%lld",&num[i]);
            xo[i] = num[i] ^ xo[i - 1];
            //if(xo[i]>=m) ans++;
        }
        buc[0] = 1;
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 0 ; j <= 130 ; j++ ){
                if( buc[j] ){
                    long long tt = xo[i] ^ j;
                    if( tt >= m ){
                        //printf("i %d j %d xor %d\n",i,j,xo[i]);
                        ans += buc[j];
                    }
                }
            }
            buc[xo[i]]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
