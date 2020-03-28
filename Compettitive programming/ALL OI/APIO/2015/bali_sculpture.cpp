#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 2e3 + 10;
long mx[N], mn[N], a[N], ans;
int n, l, r;

int main()
{
    scanf("%d %d %d",&n,&l,&r);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
    for( int bit = 61 ; bit >= 0 ; bit-- ) {
        for( int i = 1 ; i <= n ; i++ ) {
            long sum = 0; 
            mx[i] = -1e9, mn[i] = 1e9;
            for( int j = i ; j >= 1 ; j-- ) {
                sum += a[j];
                if( sum - ( sum & ans ) < ( 1ll << bit ) && mn[j-1] + 1 <= r ) mn[i] = min( mn[i], mn[j-1] + 1 ), mx[i] = max( mx[i], mx[j-1] + 1 );
            }
        }
        if( mn[n] > r || mx[n] < l ) ans |= ( 1ll << bit );
    }
    printf("%lld",ans);
    return 0;
}